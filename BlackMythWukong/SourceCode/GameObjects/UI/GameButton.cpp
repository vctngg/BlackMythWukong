#include "GameButton.h"

GameButton::GameButton()
{
	m_isHandling = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(std::string name, sf::Vector2i frame_num, sf::Vector2f pos, int frame_count, sf::Vector2f size, sf::Vector2f scaling)
{
	m_currentTime = 0.f;

	m_frameCount = frame_count;
	m_currentFrameCount = 0;
	m_frameNum = frame_num;
	m_currentFrame = sf::Vector2i(0, 0);
	this->setTexture(DATA->getTexture("UI/Button/" + name));
	this->setSize(size);
	setPosition(pos);
	CalculateRectSize();
	CalculateRectUV();
	ApplyRect();
	setOrigin((sf::Vector2f)m_rectSize / 2.f);
	setScale(scaling.x/1.75,scaling.y/1.75);
}

void GameButton::Update(float deltaTime)
{
	if ( m_doAnimate ) {
		Animate(deltaTime);
	}
	else
	{
		m_currentTime += deltaTime;
		if ( m_currentFrame.x == m_frameNum.x ) {
			m_currentFrame.x = 0;
			m_currentFrame.y++;
		}
		if ( (m_frameCount - m_currentFrame.y * m_frameNum.x - (m_currentFrame.x + 1)) < 0 ) {
			//Reset();// if frame index exceeds frame number -> reset
			int x_index = m_currentFrame.x - 1;
			if ( x_index == -1 ) {
				x_index = m_frameNum.x - 1;
			}
			m_currentFrame = sf::Vector2i(x_index, m_frameNum.y - 1);// reset to last frame

		}

		CalculateRectUV();
		ApplyRect();

		if ( this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) )
		{
			ChangeFrame(2);
		}
		else
		{
			ChangeFrame(1);
		}// animate when cursor inside button
	}
	
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}


void GameButton::HandleTouchEvent()
{
	m_isHandling = false;
	if ( this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())) )
	{
		m_btnClickFunc();
		m_isHandling = true;
	}

}

bool GameButton::isHandle()
{
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)())
{
	m_btnClickFunc = Func;
}

void GameButton::CalculateRectSize()
{
	m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void GameButton::CalculateRectUV()
{
	m_rectUV.x = m_currentFrame.x * m_rectSize.x;
	m_rectUV.y = m_currentFrame.y * m_rectSize.y;
}

void GameButton::ApplyRect()
{
	m_rect = sf::IntRect(m_rectUV, m_rectSize);
	this->setTextureRect(m_rect);
}

void GameButton::flip(bool do_flip)
{
	if ( do_flip )
	{
		this->setScale(-1.0f, 1.0f);
	}
	else
	{
		this->setScale(1.0f, 1.0f);
	}
}

sf::Vector2i GameButton::GetCurrentFrame()
{
	return m_currentFrame;
}

void GameButton::Animate(float deltaTime) {
	m_currentTime += deltaTime;
	if ( m_currentTime >= m_frameTime ) {
		m_currentFrame.x++;
		m_currentFrameCount++;
		if ( (m_currentFrame.x == m_frameNum.x) || ((m_currentFrame.y * m_frameNum.x + m_currentFrame.x) == m_frameCount) ) {
			m_currentFrame.x = 0;
			m_currentFrame.y++;
		}
		if ( m_currentFrame.y == m_frameNum.y ) {
			m_currentFrame.y = 0;
			m_currentFrameCount = 0;
			m_currentFrame.x = 0;
		}
		CalculateRectUV();
		ApplyRect();
		m_currentTime -= m_frameTime;
	}
}

void GameButton::SetAnimate(float frame_time)
{
	m_doAnimate = true;
	m_frameTime = frame_time;
}

void GameButton::ChangeFrame(int frame_number)
{
	if ( frame_number != (m_currentFrame.x + 1 + m_frameNum.x * m_currentFrame.y) ) // only changes when frame indexes are different
	{
		int y = 0;
		int x = frame_number;
		while ( x > m_frameNum.x ) {
			x -= m_frameNum.x;
			y++;
		}
		m_currentFrame = sf::Vector2i(x - 1, y);
	}
}