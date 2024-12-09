#include "FNA.h"

FNA::FNA()
{
	m_stop = true;
}

FNA::~FNA()
{
	if ( m_HitBox != nullptr ) {
		delete m_HitBox;
	}
}

void FNA::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(8, 8));
	m_HitBox->Init(sf::Vector2f(240, 0));
	m_HitBox->SetTag(FROG_Attack);
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY));
	m_HitBox->setPosition(screenWidth, groundY);
}

void FNA::Update(float deltaTime, sf::Vector2f offset)
{
	if ( m_stop == true ) return;
	if ( m_HitBox->isAlive() ) {
		if ( !m_left )
		{
			m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
			if ( m_HitBox->getPosition().x > m_startPoint.x + 50 ) {
				m_HitBox->setPosition(m_startPoint);
				m_stop = true;
				m_HitBox->setAlive(false);//kill bullet
			}
		}
		else
		{
			m_HitBox->move(-m_HitBox->getVelocity() * deltaTime);
			if ( m_HitBox->getPosition().x < m_startPoint.x - 50 ) {
				m_HitBox->setPosition(m_startPoint);
				m_stop = true;
				m_HitBox->setAlive(false);//kill bullet
			}
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

void FNA::Render(sf::RenderWindow* window)
{
	if ( m_stop ) return;
	//window->draw(*m_HitBox);
}


void FNA::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_HitBox->setPosition(m_startPoint);
}