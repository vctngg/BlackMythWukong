#include "BSHurt.h"

BSHurt::BSHurt(IBoss* boss)
{
	m_Boss = boss;
	printf("construct hurt\n");
}

void BSHurt::Init()
{
	printf("init!\n");
	m_Animation = new Animation2(*DATA->getTexture("Erlang/HURT"), sf::Vector2i(4, 1), 0.1f, 4);
	m_Animation->setModeEndFrame(true);
}

void BSHurt::Update(float deltaTime, SkillManager& SM)
{
	printf("hurt\n");
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( (ani->getCurrentFrameCount() == ani->getFrameTotals() - 1) && m_Boss->getHitBox()->isVulnerable() ) {
		m_Boss->changeNextState(STATE::IDLE);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x+ m_Boss->m_playerOffset.x, m_Boss->m_playerOffset.y+ m_Boss->getHitBox()->getPosition().y - 16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSHurt::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
