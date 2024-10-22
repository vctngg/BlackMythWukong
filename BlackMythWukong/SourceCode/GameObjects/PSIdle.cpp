#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_stand"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(false);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_MovementCheck.FacingCheck();
	if ( m_MovementCheck.FacingLeft() )
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->changeNextState(RUN);
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

		m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	}
	else
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->changeNextState(RUN);
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

		m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	}
	m_Animation->flip(m_MovementCheck.FacingLeft());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSIdle::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}