#include "Layer.h"
#define pos0 -screenWidth
#define pos1 0
#define pos2 screenWidth
#define pos3 screenWidth * 2

void Layer::Init(std::string name, float speed, float y_pos)
{
	sf::Texture* texture = DATA->getTexture(name);
	m_SizeImage = (sf::Vector2i)texture->getSize();
	for ( int i = 0; i < int(screenWidth / m_SizeImage.x)+3;i++ )
	{
		m_ImageNumber++;
		m_image[i].setTexture(*texture);
		m_image[i].setPosition(sf::Vector2f(m_SizeImage.x * i - m_SizeImage.x, y_pos));
	}
	m_Speed = speed;
}

void Layer::Update(float deltaTime)
{
	m_MovementManager.FacingCheck();
	if ( m_MovementManager.FacingRight() )
	{
		for ( int i = 0; i < m_ImageNumber; i++ )
		{
			m_image[i].move(-m_Speed * deltaTime, 0);
		}
	}
	else if ( m_MovementManager.FacingLeft() )
	{
		for ( int i = 0; i < m_ImageNumber; i++ )
		{
			m_image[i].move(m_Speed * deltaTime, 0);
		}
	}
	//image positioning
	if ( m_MovementManager.FacingLeft() )
	{
		for ( int i = 0; i < m_ImageNumber; i++ )
		{
			if ( m_image[i].getPosition().x > screenWidth + 50 )
			{
				m_image[i].setPosition(m_image[i].getPosition().x - m_ImageNumber * m_SizeImage.x, m_image[i].getPosition().y);
			}
		}
	}
	if ( m_MovementManager.FacingRight() )
	{
		for ( int i = 0; i < m_ImageNumber; i++ )
		{
			if ( m_image[i].getPosition().x < -m_SizeImage.x - 50 )
			{
				m_image[i].setPosition(m_image[i].getPosition().x + m_ImageNumber * m_SizeImage.x, m_image[i].getPosition().y);
			}
		}
	}
}

void Layer::Render(sf::RenderWindow* window)
{
	for ( int i = 0; i < m_ImageNumber; i++ )
	{
		window->draw(m_image[i]);
	}
}
