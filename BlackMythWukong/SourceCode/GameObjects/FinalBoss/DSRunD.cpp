#include "DSRunD.h"

DSRunD::DSRunD(IDemon* demon)
{
	m_Demon = demon;
}

void DSRunD::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/06_demon_walk/walk"), sf::Vector2i(1, 12), 0.1f,12);
}

void DSRunD::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	m_Demon->MFacingCheck(m_Demon->getHitBox()->getPosition().x, m_Demon->ReturnPlayerPosition().x);
	if ( m_Demon->getHitBox()->isAlive() )
	{
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
				m_Demon->changeNextState(HURT_DEMON);
			}
		}
		else if ( m_Demon->ReturnDistanceFromPlayer() <= 48 ) {
			if ( SM->IsUnlocked(DEMON_SKILL_SPELL) && !SM->IsOnCD(DEMON_SKILL_SPELL) ) {
				SM->SetOnCD(DEMON_SKILL_SPELL);
				m_Demon->changeNextState(CAST_SPELL);
			}
			else if ( SM->IsUnlocked(DEMON_SKILL_SMASH) && !SM->IsOnCD(DEMON_SKILL_SMASH) ) {
				SM->SetOnCD(DEMON_SKILL_SMASH);
				m_Demon->changeNextState(SMASH);
			}
			else if ( SM->IsUnlocked(DEMON_SKILL_FIRE) && !SM->IsOnCD(DEMON_SKILL_FIRE) ) {
				SM->SetOnCD(DEMON_SKILL_FIRE);
				m_Demon->changeNextState(FIRE_BREATH);
			}
			else if ( SM->IsUnlocked(DEMON_SKILL_NA) && !SM->IsOnCD(DEMON_SKILL_NA) ) {
				SM->SetOnCD(DEMON_SKILL_NA);
				m_Demon->changeNextState(CLEAVE);
			}
			else if ( !m_Demon->getHitBox()->isVulnerable() ) {
				m_Demon->changeNextState(HURT_DEMON);
			}

		}
	}
	else {
		m_Demon->changeNextState(DEATH);
		m_Demon->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 64 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSRunD::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);

}

void DSRunD::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
