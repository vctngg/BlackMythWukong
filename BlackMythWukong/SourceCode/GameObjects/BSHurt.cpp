#include "BSHurt.h"

BSHurt::BSHurt(IBoss* boss)
{
	m_Boss = boss;
}

void BSHurt::Init()
{
	m_Animation = new Animation2(*DATA->getTexture("Erlang/HURT"), sf::Vector2i(5, 1), 0.1f, 5);
	m_Animation->setModeEndFrame(true);
}

void BSHurt::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	Animation2* ani = (Animation2*)m_Animation;

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x, m_Boss->getHitBox()->getPosition().y - 16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSHurt::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSHurt::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
