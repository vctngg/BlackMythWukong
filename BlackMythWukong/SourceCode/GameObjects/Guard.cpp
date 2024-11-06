#include "Guard.h"

void Guard::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(45, 28));
	m_HitBox->Init(sf::Vector2f(240, 0));
	setStartPoint(sf::Vector2f(screenWidth/2, groundY));
	m_HitBox->setPosition(screenWidth/3, -50 + groundY- this->getHitBox()->getSize().y / 2);
	int variations = rand() % 10 + 1;
	std::string pathend = "/Idle/idle";
	m_idleAni = new Animation(*DATA->getTexture("Characters/Guards/1"  + pathend), sf::Vector2i(4, 1), 0.2f);
	m_runAni = new Animation(*DATA->getTexture("Characters/Guards/1"  + pathend), sf::Vector2i(4, 1), 0.2f);
	m_deathAni = new Animation(*DATA->getTexture("Characters/Guards/1"  + pathend), sf::Vector2i(4, 1), 0.2f);
	m_currentAni = m_idleAni;
	m_HitBox->SetTag(NON_INTERACTIVE);
}