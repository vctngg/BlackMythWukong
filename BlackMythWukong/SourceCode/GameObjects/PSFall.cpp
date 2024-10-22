#include "PSFall.h"

PSFall::PSFall(IPlayer* player)
{
	m_Player = player;
}

void PSFall::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_jump"), sf::Vector2i(4, 1), 0.1f);
}

void PSFall::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_MovementCheck.FacingCheck();
	m_currentTime += deltaTime;
	float v = 30 * m_currentTime;
	m_Player->getHitBox()->move(0, v);
	if ( m_Player->getHitBox()->getPosition().y >= groundY ) {
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
		else m_Player->changeNextState(RUN);
		m_currentTime = 0.f;
	}

	if ( m_MovementCheck.FacingLeft() )
	{
		if ( m_Player->getHitBox()->isAlive() ) {
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
				m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			}
			else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
				m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			}
		}
		m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	}
	else
	{
		if ( m_Player->getHitBox()->isAlive() ) {
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
				m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			}
			else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
				m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			}
		}
		m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	}
	m_Animation->flip(m_MovementCheck.FacingLeft());
}

void PSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFall::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}

