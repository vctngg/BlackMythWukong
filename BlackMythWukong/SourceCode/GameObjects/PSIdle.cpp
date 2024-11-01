#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_stand"), sf::Vector2i(4, 1), 0.1f);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->FacingCheck();
	if ( m_Player->FacingLeft() )
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
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			m_Player->changeNextState(ATTACK1);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			m_Player->changeNextState(ATTACK2);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			m_Player->changeNextState(ATTACK3);
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

		m_Animation->setPosition(m_Player->getHitBox()->getPosition().x, m_Player->getHitBox()->getPosition().y + 6);
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
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			m_Player->changeNextState(ATTACK1);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			m_Player->changeNextState(ATTACK2);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			m_Player->changeNextState(ATTACK3);
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

		m_Animation->setPosition(m_Player->getHitBox()->getPosition().x, m_Player->getHitBox()->getPosition().y + 6);
	}
	m_Animation->flip(m_Player->FacingLeft());
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