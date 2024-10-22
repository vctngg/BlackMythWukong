#include "PSAttack3.h"

PSAttack3::PSAttack3(IPlayer* player)
{
	m_Player = player;
}

void PSAttack3::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_attack3"), sf::Vector2i(4, 1), 0.1f);
}

void PSAttack3::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_MovementCheck.FacingCheck();
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
		m_Player->changeNextState(RUN);
	}
	if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->flip(m_MovementCheck.FacingLeft());
}

void PSAttack3::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack3::Reset()
{
	m_Animation->Reset();
}