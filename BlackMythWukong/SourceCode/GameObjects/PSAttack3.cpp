#include "PSAttack3.h"

PSAttack3::PSAttack3(IPlayer* player)
{
	m_Player = player;
}

void PSAttack3::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("wukong/wukong_attack3"), sf::Vector2i(4, 1), 0.1f,4);
	m_Animation->setModeEndFrame(true);
}

void PSAttack3::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	m_Player->FacingCheck();
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Player->changeNextState(IDLE);
	}
	if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition().x, m_Player->getHitBox()->getPosition().y + 6);
	m_Animation->flip(m_Player->FacingLeft());
}

void PSAttack3::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack3::Reset()
{
	m_Animation->Reset();
}