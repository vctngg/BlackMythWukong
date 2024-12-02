#include "DSSmash.h"

DSSmash::DSSmash(IDemon* demon)
{
	m_Demon = demon;
}

void DSSmash::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/08_demon_smash/smash"), sf::Vector2i(3, 6), 0.1f, 18);
	m_Animation->setModeEndFrame(true);
}

void DSSmash::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 1 ) {
		sf::Vector2f pos = m_Demon->getHitBox()->getPosition();
		m_Demon->getWeapon()->GetDirection(m_Demon->FacingLeft());
		m_Demon->getWeapon()->CastSmash(pos);
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Demon->changeNextState(IDLE_DEMON);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 64 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSSmash::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSSmash::Reset()
{
	m_Animation->Reset();
}
