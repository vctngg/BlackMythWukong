#include "Layer.h"

void Layer::Init(std::string name, float speed, float y_pos, sf::Vector2f scaling)
{
	sf::Texture* texture = DATA->getTexture(name);
	m_SizeImage = (sf::Vector2i)texture->getSize();
	m_scaling = scaling;
	for ( int i = 0; i < int(screenWidth / (m_SizeImage.x*m_scaling.x))+3;i++ )
	{
		m_ImageNumber++;
		m_image[i].setTexture(*texture);
		m_image[i].setPosition(sf::Vector2f((m_SizeImage.x * i - m_SizeImage.x)*m_scaling.x, y_pos));
		m_image[i].setScale(scaling);
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
				m_image[i].setPosition(m_image[i].getPosition().x - m_ImageNumber * m_SizeImage.x * m_scaling.x, m_image[i].getPosition().y);
			}
		}
	}
	if ( m_MovementManager.FacingRight() )
	{
		for ( int i = 0; i < m_ImageNumber; i++ )
		{
			if ( m_image[i].getPosition().x < -m_SizeImage.x * m_scaling.x - 50 )
			{
				m_image[i].setPosition(m_image[i].getPosition().x + m_ImageNumber * m_SizeImage.x * m_scaling.x, m_image[i].getPosition().y);
			}
		}
	}
	//printf("(%f,%f)\n", m_image[2].getPosition().x, m_image[2].getPosition().y);
}

void Layer::Render(sf::RenderWindow* window)
{
	for ( int i = 0; i < m_ImageNumber; i++ )
	{
		window->draw(m_image[i]);
	}
}

