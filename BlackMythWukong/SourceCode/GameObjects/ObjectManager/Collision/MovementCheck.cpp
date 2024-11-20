#include "MovementCheck.h"


bool MovementCheck::IsMoving()
{
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
	{
		m_isMoving = true;
	}
	else m_isMoving = false;

	return m_isMoving;
}

void MovementCheck::FacingCheck()
{
	if ( !(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) )
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		{
			m_leftfacing = true;
			m_rightfacing = false;
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		{
			m_leftfacing = false;
			m_rightfacing = true;
		}
	}
}


bool MovementCheck::FacingLeft()
{
	return m_leftfacing;
}

bool MovementCheck::FacingRight()
{
	return m_rightfacing;
}
