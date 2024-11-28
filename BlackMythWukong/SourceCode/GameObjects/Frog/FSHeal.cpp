#include "FSHeal.h"

FSHeal::FSHeal(IFrog* frog)
{
	m_Frog = frog;
}

void FSHeal::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Characters/Frogger/frogger_heal"), sf::Vector2i(17, 1), 0.1f, 17);
	m_Animation->setModeEndFrame(true);
}

void FSHeal::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;
	if ( ani->getCurrentFrameCount() == ani->getFrameTotals() - 1 ) {
		m_Frog->changeNextState(IDLE);
		m_Frog->getHitBox()->SetCurrentHP(m_Frog->getHitBox()->GetCurrentHP() + FROG_HEAL);
	}
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->getHitBox()->getPosition().y - 32 + m_Frog->m_playerOffset.y);
	m_Animation->flip(m_Frog->FacingLeft());
}

void FSHeal::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void FSHeal::Reset()
{
	m_Animation->Reset();
}
