#include "PSAttack1.h"

PSAttack1::PSAttack1(IPlayer* player)
{
	m_Player = player;
}

void PSAttack1::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_attack1"), sf::Vector2i(4, 1), 0.1f);
}

void PSAttack1::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_MovementCheck.FacingCheck();
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
		m_Player->changeNextState(ATTACK1);
	}
	if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->flip(m_MovementCheck.FacingLeft());
}

void PSAttack1::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack1::Reset()
{
	m_Animation->Reset();
}