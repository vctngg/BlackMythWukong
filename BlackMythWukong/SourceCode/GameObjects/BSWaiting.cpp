#include "BSWaiting.h"

BSWaiting::BSWaiting(IBoss* boss)
{
	m_Boss = boss;
}

void BSWaiting::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Erlang/IDLE"), sf::Vector2i(5, 1), 0.1f);
}

void BSWaiting::Update(float deltaTime)
{
	m_Boss->getHitBox()->setAlive(false);
	m_Animation->Update(deltaTime);
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::E) ) {
		m_Boss->changeNextState(IDLE);
		m_Boss->getHitBox()->setAlive(true);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition().x, m_Boss->getHitBox()->getPosition().y - 16);
	m_Animation->flip(m_Boss->getHitBox()->getPosition().x > m_Boss->ReturnPlayerPosition().x);
}

void BSWaiting::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSWaiting::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
