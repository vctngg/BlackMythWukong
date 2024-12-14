#include "PSAttack3.h"

PSAttack3::PSAttack3(IPlayer* player)
{
	m_Player = player;
}

void PSAttack3::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("wukong/wukong_attack3"), sf::Vector2i(4, 1), 0.1f,4);
	m_Animation->setScale(2, 2);
	m_Animation->setModeEndFrame(true);
}

void PSAttack3::Update(float deltaTime, SkillManager& SM)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	m_Player->FacingCheck();
	if ( ani->getCurrentFrameCount() == 0 ) {
		sf::Vector2f pos = m_Player->getHitBox()->getPosition();
		m_Player->getWeapon()->GetDirection(m_Player->FacingLeft());
		m_Player->getWeapon()->Attack3(pos);
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Player->changeNextState(IDLE);
	}
	if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition().x + m_Player->m_offset.x, m_Player->getHitBox()->getPosition().y + 6 + m_Player->m_offset.y);
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