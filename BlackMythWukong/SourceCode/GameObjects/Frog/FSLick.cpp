#include "FSLick.h"

FSLick::FSLick(IFrog* frog)
{
	m_Frog = frog;
}

void FSLick::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Characters/Frogger/frogger_tongue"), sf::Vector2i(8, 1), 0.1f, 8);
	m_Animation->setModeEndFrame(true);	
}

void FSLick::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == 0 ) {
		sf::Vector2f pos = m_Frog->getHitBox()->getPosition();
		m_Frog->getWeapon()->GetDirection(m_Frog->FacingLeft());
		m_Frog->getWeapon()->Lick(pos);
	}
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Frog->changeNextState(IDLE);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->getHitBox()->getPosition().y - 32 + m_Frog->m_playerOffset.y);
	m_Animation->flip(m_Frog->FacingLeft());
}

void FSLick::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSLick::Reset()
{
	m_Animation->Reset();
}
