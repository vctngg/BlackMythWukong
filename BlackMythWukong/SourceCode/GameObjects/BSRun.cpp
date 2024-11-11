#include "BSRun.h"

BSRun::BSRun(IBoss* boss)
{
	m_Boss = boss;
}

void BSRun::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Erlang/RUN"), sf::Vector2i(8, 1), 0.1f);
}

void BSRun::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_Animation->Update(deltaTime);
	if (m_Boss->getHitBox()->isAlive())
	{
		if ( m_Boss->ReturnDistanceFromPlayer() < 20 ) {
			if ( m_currentTime > 1 )
			{
				m_Boss->changeNextState(ATTACK);
			}
		}
		else if ( m_Boss->ReturnDistanceFromPlayer() > 20 && m_Boss->ReturnDistanceFromPlayer() < screenWidth ) {
			if ( m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x ) {
				m_Boss->getHitBox()->move(-m_Boss->getHitBox()->getVelocity().x * deltaTime, 0);
			}
			else if ( m_Boss->getHitBox()->getPosition().x < m_Boss->ReturnPlayerPosition().x ) {
				m_Boss->getHitBox()->move(m_Boss->getHitBox()->getVelocity().x * deltaTime, 0);
			}
		}
		else {
			m_Boss->changeNextState(IDLE);
		}
		if ( !m_Boss->getHitBox()->isVulnerable() ) {
			m_Boss->changeNextState(HURT);
		}
	}
	else {
		m_Boss->changeNextState(FLEE);
	}
	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x + m_Boss->m_playerOffset.x, m_Boss->m_playerOffset.y+ m_Boss->getHitBox()->getPosition().y - 16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSRun::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
