#include "DSRun.h"

DSRun::DSRun(IDemon* demon)
{
	m_Demon = demon;
}

void DSRun::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/02_move/walk"), sf::Vector2i(3, 3), 0.1f,8);
}

void DSRun::Update(float deltaTime, SkillManager& SM)
{
	
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	m_Demon->MFacingCheck(m_Demon->getHitBox()->getPosition().x, m_Demon->ReturnPlayerPosition().x);
	if ( m_Demon->ReturnDistanceFromPlayer() > 48 && m_Demon->ReturnDistanceFromPlayer() < screenWidth ) {
		if ( m_Demon->FacingLeft() ) {
			//printf("left\n");
			m_Demon->getHitBox()->move(-m_Demon->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else {
			//printf("right\n");
			m_Demon->getHitBox()->move(m_Demon->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		if ( !m_Demon->getHitBox()->isVulnerable() ) {
			m_Demon->changeNextState(HURT);
		}
	}
	else if ( !m_Demon->getHitBox()->isVulnerable() ) {
			m_Demon->changeNextState(HURT);
		}
	if ( m_Demon->getHitBox()->GetCurrentHP() <= 250 ) {
		m_Demon->changeNextState(TRANSFORM);
	}
	if ( !m_Demon->getHitBox()->isAlive() ) m_Demon->changeNextState(IDState::DEATH);
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 48 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSRun::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
