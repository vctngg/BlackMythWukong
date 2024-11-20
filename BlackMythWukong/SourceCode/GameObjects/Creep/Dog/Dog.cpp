#include "Dog.h"

void Dog::Init()
{
	m_timer = 1.5;
	m_HitBox = new HitBox(sf::Vector2i(45, 28));
	m_HitBox->Init(sf::Vector2f(100, 0));
	setStartPoint(sf::Vector2f(screenWidth / 2, groundY));
	m_HitBox->setPosition(screenWidth*2 / 3 + 50,-10+  groundY - this->getHitBox()->getSize().y / 2);
	m_idleAni = new Animation(*DATA->getTexture("Characters/Dog/Idle/idle"), sf::Vector2i(3, 1), 0.2f);
	m_runAni = new Animation(*DATA->getTexture("Characters/Dog/Run/run"), sf::Vector2i(4, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Characters/Dog/Death/death" ), sf::Vector2i(9, 1), 0.08f);
	m_barkAni = new Animation(*DATA->getTexture("Characters/Dog/Bark/bark" ), sf::Vector2i(5, 1), 0.2f);
	m_idleAni->setScale(-0.5, 0.5);
	m_deathAni->setScale(-0.5, 0.5);
	m_runAni->setScale(-0.5, 0.5);
	m_barkAni->setScale(-0.5, 0.5);
	m_currentAni = m_idleAni;
	m_HitBox->SetTag(NON_INTERACTIVE);
}

void Dog::TriggerThreaten(float deltaTime)
{
	m_timer -= deltaTime;
	if ( m_timer > 0 ) {
		m_currentAni = m_runAni;
		m_HitBox->move(-m_HitBox->getVelocity().x * deltaTime, 0);
	}
	if ( m_timer < 0 && m_timer > -2.5 ) {
		m_currentAni = m_barkAni;
	}
	else if ( m_timer < -2.5 ) {
		m_currentAni = m_idleAni;
	}
}

void Dog::TriggerRetreat(float deltaTime)
{
	m_timer += deltaTime;
	if (m_timer < -2.5 )
	{
		m_currentAni = m_runAni;
		m_currentAni->setScale(0.5, 0.5);
		m_HitBox->move(m_HitBox->getVelocity().x * deltaTime, 0);
	}
	if ( m_timer > -1 ) {
		m_currentAni = m_idleAni;
	}
}
