#include "Spell.h"

Spell::Spell()
{
	m_stop = true;
}

Spell::~Spell()
{
	m_currentAni = nullptr;
	if ( m_deathAni != nullptr ) {
		delete m_deathAni;
	}
	if ( m_runAni != nullptr ) {
		delete m_runAni;
	}
	if ( m_HitBox != nullptr ) {
		delete m_HitBox;
	}
}

void Spell::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 32));
	m_HitBox->Init(sf::Vector2f(200, 0));
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);

	m_runAni = new Animation2(*DATA->getTexture("Demon/13_projectile_idle/idle"), sf::Vector2i(3, 1), 0.1f, 3);
	m_deathAni = new Animation2(*DATA->getTexture("Demon/14_projectile_explosion/explode"), sf::Vector2i(11, 1), 0.1f, 11);
	m_deathAni->setModeEndFrame(true);

	m_currentAni = m_runAni;
}

void Spell::Update(float deltaTime, sf::Vector2f offset)
{
	if ( m_stop == true ) return;
	if ( m_HitBox->isAlive() ) {
		if ( !m_left )
		{
			m_HitBox->move(m_HitBox->getVelocity().x * deltaTime, m_HitBox->getVelocity().y * deltaTime + rand()%(8+8+1)-8);
			if ( m_HitBox->getPosition().x > m_startPoint.x + 200 ) {
				m_HitBox->setPosition(m_startPoint);
				m_stop = true;
				m_HitBox->setAlive(false);//kill bullet
			}
		}
		else
		{
			m_HitBox->move(-m_HitBox->getVelocity().x * deltaTime, m_HitBox->getVelocity().y * deltaTime + rand() % (8 + 8 + 1) - 8);
			if ( m_HitBox->getPosition().x < m_startPoint.x - 200 ) {
				m_HitBox->setPosition(m_startPoint);
				m_stop = true;
				m_HitBox->setAlive(false);//kill bullet
			}
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition().x + offset.x, getHitBox()->getPosition().y + offset.y);
		m_currentAni->flip(m_left);
	}
	else
	{
		if ( m_soundIsPlaying == false ) {
			//DATA->playSound("impactsplat03");
			m_soundIsPlaying = true;
		}
		m_currentAni = m_deathAni;
		Animation2* ani = (Animation2*)m_currentAni;
		if ( ani->getCurrentFrameCount() != ani->getFrameTotals() - 1 ) {
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition().x + offset.x, getHitBox()->getPosition().y + offset.y);
			m_currentAni->flip(m_left);
		}
		else m_stop = true;

	}
}

void Spell::Render(sf::RenderWindow* window)
{
	if ( m_stop ) return;
	window->draw(*m_currentAni);
	window->draw(*m_HitBox);
}

void Spell::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_deathAni->Reset();
	m_runAni->Reset();
	m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
}
