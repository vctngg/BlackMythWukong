#include "BSFlee.h"

BSFlee::BSFlee(IBoss* boss)
{
	m_Boss = boss;
}

void BSFlee::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Erlang/RUN"), sf::Vector2i(8, 1), 0.1f);
	m_AnimationTalking = new Animation(*DATA->getTexture("Erlang/IDLE"), sf::Vector2i(5, 1), 0.1f);
	m_currentAnimation = m_AnimationTalking;
	m_isTalking = true;
}

void BSFlee::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	m_currentAnimation->Update(deltaTime);
	if ( !m_isTalking ) {
		m_Boss->getHitBox()->move(m_Boss->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	m_currentAnimation->setPosition(m_Boss->getHitBox()->getPosition().x + m_Boss->m_playerOffset.x, m_Boss->m_playerOffset.y + m_Boss->getHitBox()->getPosition().y - 16);
	m_currentAnimation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSFlee::Render(sf::RenderWindow* window)
{
	window->draw(*m_currentAnimation);
}

void BSFlee::Reset()
{
	m_currentAnimation->Reset();
	m_currentAnimation = m_AnimationTalking;
	m_currentTime = 0.f;
}
