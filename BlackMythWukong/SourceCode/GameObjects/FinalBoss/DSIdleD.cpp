#include "DSIdleD.h"

DSIdleD::DSIdleD(IDemon* demon)
{
	m_Demon = demon;
}

void DSIdleD::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Demon/05_demon_idle/idle"), sf::Vector2i(6, 1), 0.1f);
}

void DSIdleD::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( m_Demon->getHitBox()->isAlive() )
	{
		if ( m_Demon->ReturnDistanceFromPlayer() > 48 && m_Demon->ReturnDistanceFromPlayer() < screenWidth ) {
			m_Demon->changeNextState(RUN);
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
	else
	{
		m_Demon->changeNextState(DEATH);
		m_Demon->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 64 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!(m_Demon->getHitBox()->getPosition().x > m_Demon->ReturnPlayerPosition().x));
}

void DSIdleD::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSIdleD::Reset()
{
	m_Animation->Reset();
}
