#include "DSHurtD.h"

DSHurtD::DSHurtD(IDemon* demon)
{
	m_Demon = demon;
}

void DSHurtD::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Demon/11_demon_take_hit/hurt"), sf::Vector2i(5, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
	sound = false;
}

void DSHurtD::Update(float deltaTime, SkillManager& SM)
{
	
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( !sound ) {
		sound = true;
		DATA->playSound("monster-hurt");
	}
	if ( m_Animation->IsEndFrame() ) {

		if ( m_Demon->getHitBox()->isVulnerable() )
		{
			m_Demon->changeNextState(STATE::IDLE_DEMON);
		}
	}
	if ( !m_Demon->getHitBox()->isAlive() ) m_Demon->changeNextState(IDState::DEATH);
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 48 + m_Demon->getHitBox()->getPosition().y);
	m_Animation->flip(!(m_Demon->getHitBox()->getPosition().x > m_Demon->ReturnPlayerPosition().x));
}

void DSHurtD::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSHurtD::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
	sound = false;
}
