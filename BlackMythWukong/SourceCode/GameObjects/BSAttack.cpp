#include "BSAttack.h"

BSAttack::BSAttack(IBoss* boss)
{
	m_Boss = boss;
}

void BSAttack::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Erlang/ATTACK"), sf::Vector2i(5, 1), 0.1f, 5);
	m_Animation->setModeEndFrame(true);
}

void BSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 2 ) {
		sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
		m_Boss->getWeapon()->GetDirection(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
		m_Boss->getWeapon()->Fire(pos);
		printf("fire\n");
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Boss->changeNextState(STATE::IDLE);
	}
	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x, m_Boss->getHitBox()->getPosition().y - 16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSAttack::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}