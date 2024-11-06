#include "Dog.h"

void Dog::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(45, 28));
	m_HitBox->Init(sf::Vector2f(240, 0));
	setStartPoint(sf::Vector2f(screenWidth / 2, groundY));
	m_HitBox->setPosition(screenWidth*2 / 3 + 50,-10+  groundY - this->getHitBox()->getSize().y / 2);
	m_idleAni = new Animation(*DATA->getTexture("Characters/Dog/Idle/idle"), sf::Vector2i(3, 1), 0.2f);
	m_runAni = new Animation(*DATA->getTexture("Characters/Dog/Run/run"), sf::Vector2i(4, 1), 0.2f);
	m_deathAni = new Animation(*DATA->getTexture("Characters/Dog/Death/death" ), sf::Vector2i(9, 1), 0.2f);
	m_barkAni = new Animation(*DATA->getTexture("Characters/Dog/Bark/bark" ), sf::Vector2i(5, 1), 0.2f);
	m_idleAni->setScale(-0.5, 0.5);
	m_deathAni->setScale(-0.5, 0.5);
	m_runAni->setScale(-0.5, 0.5);
	m_currentAni = m_idleAni;
	m_HitBox->SetTag(NON_INTERACTIVE);
}