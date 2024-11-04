#include "UI.h"

void UI::Init(sf::Texture& texture, sf::Vector2i frame_num, sf::Vector2f pos, int frame_count)
{
	m_frameCount = frame_count;
	m_currentFrameCount = 0;
	m_frameNum = frame_num;
	this->setTexture(texture);
	m_currentFrame = sf::Vector2i(0, 0);
	this->setPosition(pos);
	m_currentTime = 0.f;
	CalculateRectSize();
	CalculateRectUV();
	ApplyRect();
	this->setOrigin((sf::Vector2f)m_rectSize / 2.f);
}
void UI::CalculateRectSize()
{
	m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void UI::CalculateRectUV()
{
	m_rectUV.x = m_currentFrame.x * m_rectSize.x;
	m_rectUV.y = m_currentFrame.y * m_rectSize.y;
}

void UI::ApplyRect()
{
	m_rect = sf::IntRect(m_rectUV, m_rectSize);
	this->setTextureRect(m_rect);
}
void UI::Update(float deltaTime)
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
	}
}



void UI::flip(bool do_flip)
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

sf::Vector2i UI::GetCurrentFrame()
{
	return m_currentFrame;
}

void UI::Animate(float deltaTime) {
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

void UI::SetAnimate(float frame_time)
{
	m_doAnimate = true;
	m_frameTime = frame_time;
}

void UI::ChangeFrame(int frame_number)
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

void UI::Reset()
{
	m_currentFrame = sf::Vector2i(0, 0);
	m_currentFrameCount = 0;
}
