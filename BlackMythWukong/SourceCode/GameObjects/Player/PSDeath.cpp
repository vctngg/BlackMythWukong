#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 4.f;
}

void PSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_death"), sf::Vector2i(14, 1), 0.2f);
	m_Animation->setScale(2, 2);
	m_Animation->setModeEndFrame(true);
}

void PSDeath::Update(float deltaTime, SkillManager& SM)
{
	m_Player->FacingCheck();
	m_currentTime += deltaTime;
	if ( m_currentTime >= m_timeRemain ) {
		GSM->ChangeState(StateTypes::END);
		DATA->getMusic("Uprising")->stop();
		DATA->getMusic("softspot")->stop();
		DATA->getMusic("summer")->stop();
		DATA->playSound("lose");
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition().x + m_Player->m_offset.x, m_Player->getHitBox()->getPosition().y + 6 + m_Player->m_offset.y);
	m_Animation->flip(m_Player->FacingLeft());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}