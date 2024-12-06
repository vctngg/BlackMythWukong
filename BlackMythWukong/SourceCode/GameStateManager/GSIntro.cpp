#include "GSIntro.h"
#include <fstream>

GSIntro::GSIntro()
{
	m_currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
	sf::Texture* texture = DATA->getTexture("Logo");
	m_Logo.setTexture(*texture);
	m_Logo.setPosition((screenWidth / 2) + 45, (screenHeight / 2)+30);
	m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Logo.setScale(sf::Vector2f(1.2, 1.2));
	shape.setSize(sf::Vector2f(screenWidth, screenHeight));
	shape.setFillColor(sf::Color(0,0,0,alpha));
}

void GSIntro::Update(float deltaTime)
{
	/*GSM->ChangeState(StateTypes::FINAL);*/
	m_currentTime += deltaTime;
	if ( m_currentTime >= 1.5 ) {
		if ( alpha <= 255 ) {
			alpha += 2.7;
		}
	}
	
	shape.setFillColor(sf::Color(0, 0, 0, alpha));
	if ( m_currentTime >= 3.f ) {
		GSM->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(m_Logo);
	window->draw(shape);
}