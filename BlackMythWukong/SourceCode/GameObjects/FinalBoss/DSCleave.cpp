#include "DSCleave.h"

DSCleave::DSCleave(IDemon* demon)
{
	m_Demon = demon;
}

void DSCleave::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/07_demon_cleave/cleave"), sf::Vector2i(3, 5), 0.1f, 15);
	m_Animation->setModeEndFrame(true);
}

void DSCleave::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 1 ) {
		sf::Vector2f pos = m_Demon->getHitBox()->getPosition();
		m_Demon->getWeapon()->GetDirection(m_Demon->FacingLeft());
		m_Demon->getWeapon()->NA(pos);
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Demon->changeNextState(IDLE_DEMON);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 64 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSCleave::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSCleave::Reset()
{
	m_Animation->Reset();
}
