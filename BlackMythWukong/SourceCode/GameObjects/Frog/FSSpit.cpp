#include "FSSpit.h"

FSSpit::FSSpit(IFrog* frog)
{
	m_Frog = frog;
}

void FSSpit::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Characters/Frogger/frogger_spit"), sf::Vector2i(11, 1), 0.1f, 11);
	m_Animation->setModeEndFrame(true);
}

void FSSpit::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 1 ) {
		sf::Vector2f pos = m_Frog->getHitBox()->getPosition();
		m_Frog->getWeapon()->GetDirection(m_Frog->FacingLeft());
		m_Frog->getWeapon()->Spit(pos);
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Frog->changeNextState(IDLE);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->getHitBox()->getPosition().y - 32 + m_Frog->m_playerOffset.y);
	m_Animation->flip(m_Frog->FacingLeft());
}

void FSSpit::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSSpit::Reset()
{
	m_Animation->Reset();
}
