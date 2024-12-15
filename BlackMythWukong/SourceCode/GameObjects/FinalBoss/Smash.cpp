#include "Smash.h"

Smash::Smash()
{
	m_stop = true;
}

Smash::~Smash()
{
	if ( m_HitBox != nullptr ) {
		delete m_HitBox;
	}
}

void Smash::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(32, 16));
	m_HitBox->Init(sf::Vector2f(280, 0));
	m_HitBox->SetTag(DEMON_Smash);
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);
	m_HitBox2 = new HitBox(sf::Vector2i(32, 16));
	m_HitBox2->Init(sf::Vector2f(280, 0));
	m_HitBox2->SetTag(DEMON_Smash);
	m_HitBox2->setPosition(screenWidth, groundY);
}

void Smash::Update(float deltaTime, sf::Vector2f offset)
{
	if ( m_stop == true ) return;
	if ( m_HitBox->isAlive() ) {
		m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if ( m_HitBox->getPosition().x > m_startPoint.x + 100 ) {
			m_HitBox->setPosition(m_startPoint);
			m_stop = true;
			m_HitBox->setAlive(false);//kill bullet
		}
	}
	else
	{
		if ( m_soundIsPlaying == false ) {
			m_soundIsPlaying = true;
		}
		m_stop = true;

	}
	if ( m_HitBox2->isAlive() )
	{
		m_HitBox2->move(-m_HitBox2->getVelocity().x * deltaTime, m_HitBox2->getVelocity().y * deltaTime);
		//printf("(%f,%f)\n", m_HitBox2->getPosition().x, m_HitBox2->getPosition().y);
		if ( m_HitBox2->getPosition().x < m_startPoint.x - 100 ) {
			m_HitBox2->setPosition(m_startPoint);
			m_stop = true;
			m_HitBox2->setAlive(false);//kill bullet
		}
	}
	else
	{
		if ( m_soundIsPlaying == false ) {
			//DATA->playSound("impactsplat03");
			m_soundIsPlaying = true;
		}
		m_stop = true;

	}
}

void Smash::Render(sf::RenderWindow* window)
{
	if ( m_stop ) return;
	//window->draw(*m_HitBox);
	//window->draw(*m_HitBox2);
}
void Smash::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_HitBox->setPosition(m_startPoint);
	m_HitBox2->setPosition(m_startPoint);
}
