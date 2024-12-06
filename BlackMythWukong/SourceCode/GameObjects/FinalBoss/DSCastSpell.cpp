#include "DSCastSpell.h"

DSCastSpell::DSCastSpell(IDemon* demon)
{
	m_Demon = demon;
}

void DSCastSpell::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/10_demon_cast_spell/cast_spell"), sf::Vector2i(6, 1), 0.1f, 6);
	m_Animation->setModeEndFrame(true);
}

void DSCastSpell::Update(float deltaTime, SkillManager& SM)
{
	
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 1 ) {
		sf::Vector2f pos = m_Demon->getHitBox()->getPosition();
		m_Demon->getWeapon()->GetDirection(m_Demon->FacingLeft());
		if (m_Demon->FacingLeft() )
		{
			m_Demon->getWeapon()->CastSpell(sf::Vector2f(pos.x -72, pos.y +60));
		}
		else
		{
			m_Demon->getWeapon()->CastSpell(sf::Vector2f(pos.x + 72, pos.y - 60));
		}
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Demon->changeNextState(IDLE_DEMON);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 48 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSCastSpell::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSCastSpell::Reset()
{
	m_Animation->Reset();
}
