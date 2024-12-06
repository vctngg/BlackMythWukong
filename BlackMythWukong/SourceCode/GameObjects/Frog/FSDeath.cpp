#include "FSDeath.h"

FSDeath::FSDeath(IFrog* frog)
{
	m_Frog = frog;
}

void FSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Characters/Frogger/frogger_death"), sf::Vector2i(4, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void FSDeath::Update(float deltaTime, SkillManager& CM)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Frog->getHitBox()->getPosition().x + m_Frog->m_playerOffset.x, m_Frog->getHitBox()->getPosition().y - 24 + m_Frog->m_playerOffset.y);
	m_Animation->flip(m_Frog->FacingLeft());
}

void FSDeath::Render(sf::RenderWindow* window)
{
	Animation2* ani = (Animation2*)m_Animation;
	if ( !(ani->getCurrentFrameCount() == ani->getFrameTotals() - 1) ) {
		window->draw(*m_Animation);
	}
}

void FSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}