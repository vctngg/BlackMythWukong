#include "UI.h"

void UI::Init(sf::Texture& texture, sf::Vector2i frame_num, sf::Vector2f pos, int frame_count)
{
	m_frameCount = frame_count;
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
	m_currentTime += deltaTime;
	if ( m_currentFrame.x == m_frameNum.x ) {
		m_currentFrame.x = 0;
		m_currentFrame.y++;
		if ( m_currentFrame.y == m_frameNum.y ) {
			m_currentFrame.y = 0;
		}
	}
	else if ( (m_frameCount - m_currentFrame.y * m_frameNum.x - (m_currentFrame.x + 1)) < 0 ) {
		Reset();
	}
	CalculateRectUV();
	ApplyRect();
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

void UI::Reset()
{
	m_currentFrame = sf::Vector2i(0, 0);
}
