#include "BSIdle.h"

BSIdle::BSIdle(IBoss* boss)
{
	m_Boss = boss;
}

void BSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Erlang/IDLE"), sf::Vector2i(5, 1), 0.1f);
}

void BSIdle::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if (m_Boss->getHitBox()->isAlive() )
	{
		if ( m_Boss->ReturnDistanceFromPlayer() > 20 && m_Boss->ReturnDistanceFromPlayer() < screenWidth ) {
			m_Boss->changeNextState(RUN);
		}
		else if ( m_Boss->ReturnDistanceFromPlayer() < 20 ) {
			if ( m_currentTime > 1 )
			{
				m_Boss->changeNextState(ATTACK);
			}
		}
		if ( !m_Boss->getHitBox()->isVulnerable() ) {
			m_Boss->changeNextState(HURT);
		}
	}
	else {
		m_Boss->changeNextState(FLEE);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x + m_Boss->m_playerOffset.x, m_Boss->m_playerOffset.y+ m_Boss->getHitBox()->getPosition().y-16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSIdle::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
