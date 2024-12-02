#include "DSIdle.h"

DSIdle::DSIdle(IDemon* demon)
{
	m_Demon = demon;
}

void DSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Demon/01_idle/idle"), sf::Vector2i(6, 1), 0.1f);
}

void DSIdle::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if ( m_Demon->getHitBox()->isAlive() )
	{
		if ( m_Demon->ReturnDistanceFromPlayer() > 48 && m_Demon->ReturnDistanceFromPlayer() < screenWidth ) {
			m_Demon->changeNextState(RUN);
			if ( !m_Demon->getHitBox()->isVulnerable() ) {
				m_Demon->changeNextState(HURT);
			}
		}
		else if ( !m_Demon->getHitBox()->isVulnerable() ) {
				m_Demon->changeNextState(HURT);
			}
	}
	else
	{
		m_Demon->changeNextState(TRANSFORM);
		m_Demon->getHitBox()->setAlive(false);
	}
	m_Animation->setPosition(m_Demon->getHitBox()->getPosition().x + m_Demon->m_playerOffset.x, m_Demon->m_playerOffset.y - 64 + m_Demon->getHitBox()->getPosition().y );
	m_Animation->flip(!(m_Demon->getHitBox()->getPosition().x > m_Demon->ReturnPlayerPosition().x));
}

void DSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void DSIdle::Reset()
{
	m_Animation->Reset();
}
