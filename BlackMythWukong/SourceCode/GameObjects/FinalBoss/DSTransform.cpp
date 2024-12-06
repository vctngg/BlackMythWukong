#include "DSTransform.h"

DSTransform::DSTransform(IDemon* demon)
{
	m_Demon = demon;
	m_timeRemain = 3.2f;
}

void DSTransform::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Demon/04_transform/transform"), sf::Vector2i(3, 11), 0.1f,32);
	m_Animation->setModeEndFrame(true);
}

void DSTransform::Update(float deltaTime, SkillManager& SM)
{
	
	m_Demon->FacingCheck();
	m_currentTime += deltaTime;
	if ( m_currentTime >= m_timeRemain ) {
		m_Demon->changeNextState(IDLE_DEMON);
		m_Demon->getHitBox()->setAlive(true);
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->getHitBox()->getPosition().y - 48 + m_Demon->m_playerOffset.y);
	m_Animation->flip(!m_Demon->FacingLeft());
}

void DSTransform::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSTransform::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
