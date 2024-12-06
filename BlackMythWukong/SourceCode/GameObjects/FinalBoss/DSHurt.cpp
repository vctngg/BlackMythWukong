#include "DSHurt.h"

DSHurt::DSHurt(IDemon* demon)
{
	m_Demon = demon;
}

void DSHurt::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Demon/03_take_hit/hurt"), sf::Vector2i(6, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void DSHurt::Update(float deltaTime, SkillManager& SM)
{
	
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( m_Animation->IsEndFrame() ) {

		if ( m_Demon->getHitBox()->isVulnerable() )
		{
			m_Demon->changeNextState(IDState::IDLE);
		}
	}
	if ( m_Demon->getHitBox()->GetCurrentHP() <= 250 ) {
		m_Demon->changeNextState(TRANSFORM);
	}
	if ( !m_Demon->getHitBox()->isAlive() ) m_Demon->changeNextState(IDState::DEATH);
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 48 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!(m_Demon->getHitBox()->getPosition().x > m_Demon->ReturnPlayerPosition().x));
}

void DSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSHurt::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
