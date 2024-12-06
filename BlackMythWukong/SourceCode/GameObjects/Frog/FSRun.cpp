#include "FSRun.h"

FSRun::FSRun(IFrog* frog)
{
	m_Frog = frog;
}

void FSRun::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Characters/Frogger/frogger_move"), sf::Vector2i(8, 1), 0.1f);
}

void FSRun::Update(float deltaTime, SkillManager& SM)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	m_Frog->MFacingCheck(m_Frog->getHitBox()->getPosition().x, m_Frog->ReturnPlayerPosition().x);
	if ( m_Frog->getHitBox()->isAlive() )
	{
		if ( m_Frog->ReturnDistanceFromPlayer() > 48 && m_Frog->ReturnDistanceFromPlayer() < screenWidth ) {
			if ( m_Frog->FacingLeft() ) {
				//printf("left\n");
				m_Frog->getHitBox()->move(-m_Frog->getHitBox()->getVelocity().x * deltaTime, 0);
			}
			else {
				//printf("right\n");
				m_Frog->getHitBox()->move(m_Frog->getHitBox()->getVelocity().x * deltaTime, 0);
			}
			if ( !m_Frog->getHitBox()->isVulnerable() ) {
				m_Frog->changeNextState(HURT);
			}
		}
		else if ( m_Frog->ReturnDistanceFromPlayer() <= 48 ) {
			if ( SM.IsUnlocked(FROG_SKILL_HEAL) && !SM.IsOnCD(FROG_SKILL_HEAL) ) {
				SM.SetOnCD(FROG_SKILL_HEAL);
				m_Frog->changeNextState(HEAL);
			}
			else if ( SM.IsUnlocked(FROG_SKILL_SPIT) && !SM.IsOnCD(FROG_SKILL_SPIT) ) {
				SM.SetOnCD(FROG_SKILL_SPIT);
				m_Frog->changeNextState(SPIT);
			}
			else if ( SM.IsUnlocked(FROG_SKILL_LICK) && !SM.IsOnCD(FROG_SKILL_LICK) ) {
				SM.SetOnCD(FROG_SKILL_LICK);
				m_Frog->changeNextState(ATTACK);
			}
			else if ( !m_Frog->getHitBox()->isVulnerable() ) {
				m_Frog->changeNextState(HURT);
			}

		}
	}
	else {
		m_Frog->changeNextState(DEATH);
		m_Frog->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->m_playerOffset.y + m_Frog->getHitBox()->getPosition().y - 32);
	m_Animation->flip(m_Frog->FacingLeft());
}

void FSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSRun::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
