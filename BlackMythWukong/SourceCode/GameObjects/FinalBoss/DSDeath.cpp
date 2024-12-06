#include "DSDeath.h"

DSDeath::DSDeath(IDemon* demon)
{
	m_Demon = demon;
	m_timeRemain = 2.2f;
}

void DSDeath::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/12_demon_death/death"), sf::Vector2i(3, 8), 0.1f,22);
	m_Animation->setModeEndFrame(true);
}

void DSDeath::Update(float deltaTime, SkillManager& SM)
{
	
	m_Demon->FacingCheck();
	m_currentTime += deltaTime;
	if ( m_currentTime >= m_timeRemain ) {
		GSM->ChangeState(StateTypes::END);
		//DATA->getMusic("Uprising")->stop();
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 48 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
