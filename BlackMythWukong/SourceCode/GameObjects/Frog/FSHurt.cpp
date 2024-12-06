#include "FSHurt.h"

FSHurt::FSHurt(IFrog* frog)
{
	m_Frog = frog;
}

void FSHurt::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Characters/Frogger/frogger_hurt"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void FSHurt::Update(float deltaTime, SkillManager& CM)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	/*if ( m_Frog->getHitBox()->isVulnerable() ) {
		printf("vulnerable\n");
	}
	else {
		printf("invulnerable\n");
	}*/
	if ( m_Frog->getHitBox()->isAlive() )
	{
		//printf("(%f,%f)\n", float(ani->getCurrentFrameCount()), float(ani->getFrameTotals() - 1));
		if ( m_Animation->IsEndFrame() ) {
			
			if ( m_Frog->getHitBox()->isVulnerable() )
			{
				m_Frog->changeNextState(STATE::IDLE);
			}
		}
	}
	else {
		m_Frog->changeNextState(DEATH);
		m_Frog->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->m_playerOffset.y + m_Frog->getHitBox()->getPosition().y - 32);
	m_Animation->flip(m_Frog->getHitBox()->getPosition().x > m_Frog->ReturnPlayerPosition().x);
}

void FSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSHurt::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
