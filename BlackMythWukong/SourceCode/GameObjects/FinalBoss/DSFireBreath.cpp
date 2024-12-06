#include "DSFireBreath.h"

DSFireBreath::DSFireBreath(IDemon* demon)
{
	m_Demon = demon;
}

void DSFireBreath::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/09_demon_fire_breath/fire_breath"), sf::Vector2i(7, 3), 0.1f, 21);
	m_Animation->setModeEndFrame(true);
}

void DSFireBreath::Update(float deltaTime, SkillManager& SM)
{
	
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 8 ) {
		sf::Vector2f pos = m_Demon->getHitBox()->getPosition();
		m_Demon->getWeapon()->GetDirection(m_Demon->FacingLeft());
		if ( m_Demon->FacingLeft() )
		{
			m_Demon->getWeapon()->CastFire(sf::Vector2f(pos.x,pos.y-32));
		}
		else
		{
			m_Demon->getWeapon()->CastFire(sf::Vector2f(pos.x, pos.y - 32));
		}
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Demon->changeNextState(IDLE_DEMON);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 48 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSFireBreath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSFireBreath::Reset()
{
	m_Animation->Reset();
}
