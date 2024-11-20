#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_Player = player;
}

void PSRun::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_run"), sf::Vector2i(4, 1), 0.1f);
}

void PSRun::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->FacingCheck();
	if ( m_Player->FacingLeft() )
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_1) )
			{
				m_Player->changeNextState(ATTACK1);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_2) )
			{
				m_Player->changeNextState(ATTACK2);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_3) )
			{
				m_Player->changeNextState(ATTACK3);
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if ( !(m_Player->IsMoving()) ) {
			m_Player->changeNextState(IDLE);
		}
		

		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	}
	else
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_1) )
			{
				m_Player->changeNextState(ATTACK1);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_2) )
			{
				m_Player->changeNextState(ATTACK2);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			if ( SM->IsUnlocked(PLAYER_ATTACK_3) )
			{
				m_Player->changeNextState(ATTACK3);
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if ( !(m_Player->IsMoving()) ) {
			m_Player->changeNextState(IDLE);
		}
		

		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition().x + m_Player->m_offset.x, m_Player->getHitBox()->getPosition().y + 6 + m_Player->m_offset.y);
	m_Animation->flip(m_Player->FacingLeft());
}

void PSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRun::Reset()
{
	m_Animation->Reset();
}