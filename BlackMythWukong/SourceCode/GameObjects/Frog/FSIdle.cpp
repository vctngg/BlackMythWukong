#include "FSIdle.h"

FSIdle::FSIdle(IFrog* frog)
{
	m_Frog = frog;
}

void FSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Characters/Frogger/frogger_idle"), sf::Vector2i(5, 1), 0.1f);
}

void FSIdle::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( m_Frog->getHitBox()->isAlive() )
	{
		if ( m_Frog->ReturnDistanceFromPlayer() > 32 && m_Frog->ReturnDistanceFromPlayer() < screenWidth ) {
			m_Frog->changeNextState(RUN);
			if ( !m_Frog->getHitBox()->isVulnerable() ) {
				m_Frog->changeNextState(HURT);
			}
		}
		else if ( m_Frog->ReturnDistanceFromPlayer() <= 32 ) {
			if ( SM->IsUnlocked(FROG_SKILL_HEAL) && !SM->IsOnCD(FROG_SKILL_HEAL) ) {
				SM->SetOnCD(FROG_SKILL_HEAL);
				m_Frog->changeNextState(HEAL);
			}
			else if ( SM->IsUnlocked(FROG_SKILL_SPIT) && !SM->IsOnCD(FROG_SKILL_SPIT) ) {
				SM->SetOnCD(FROG_SKILL_SPIT);
				m_Frog->changeNextState(SPIT);
			}
			else if ( SM->IsUnlocked(FROG_SKILL_LICK) && !SM->IsOnCD(FROG_SKILL_LICK) ) {
				SM->SetOnCD(FROG_SKILL_LICK);
				m_Frog->changeNextState(ATTACK);
			}
			else if ( !m_Frog->getHitBox()->isVulnerable() ) {
				m_Frog->changeNextState(HURT);
			}

		}
		
	}
	else
	{
		m_Frog->changeNextState(DEATH);
		m_Frog->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->m_playerOffset.y + m_Frog->getHitBox()->getPosition().y - 32);
	m_Animation->flip(m_Frog->getHitBox()->getPosition().x > m_Frog->ReturnPlayerPosition().x);
}

void FSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSIdle::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
