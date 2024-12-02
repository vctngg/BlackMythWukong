#include "DSHurt.h"

DSHurt::DSHurt(IDemon* demon)
{
	m_Demon = demon;
}

void DSHurt::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Demon/03_take_hit/hurt"), sf::Vector2i(6, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void DSHurt::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( m_Demon->getHitBox()->isAlive() )
	{
		if ( m_Animation->IsEndFrame() ) {

			if ( m_Demon->getHitBox()->isVulnerable() )
			{
				m_Demon->changeNextState(STATE::IDLE);
			}
		}
	}
	else {
		m_Demon->changeNextState(TRANSFORM);
		m_Demon->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 64 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!(m_Demon->getHitBox()->getPosition().x > m_Demon->ReturnPlayerPosition().x));
}

void DSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSHurt::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
