#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close", sf::Vector2i(2, 1), sf::Vector2f(screenWidth - screenWidth / 20 - 50, screenHeight / 8 - 50), 2, sf::Vector2f(100, 100), sf::Vector2f(1, 1));
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background/Forest/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setFont(*DATA->getFont("Karate"));
	m_Title.setPosition(screenWidth / 3 + 100, screenHeight / 5);

	//About
	author1.setString("Nguyen Viet Anh 202413944 - Project Overseer/Designer");
	author1.setFont(*DATA->getFont("Karate"));
	author1.setPosition(screenWidth / 8 -100/2, screenHeight / 5 + 60*3 + 60);

	author2.setString("Trinh Hieu Duc 202414111 - Source Code Manager");
	author2.setFont(*DATA->getFont("Karate"));
	author2.setPosition(screenWidth / 8 -100/2, screenHeight / 5 + 60*4 +60);

	team.setString("A project made by team 6");
	team.setFont(*DATA->getFont("Karate"));
	team.setPosition(screenWidth / 8 -100/2, screenHeight / 5 + 60*2 +60);

	clas.setString("Class no. 156394 - Instructor: Hoang Quang Huy");
	clas.setFont(*DATA->getFont("Karate"));
	clas.setPosition(screenWidth / 8 -100/2, screenHeight / 5 + 60 + 60);
}

void GSAbout::Update(float deltaTime)
{
	for ( auto btn : m_ListBtn ) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	//window->draw(m_Background);
	for ( auto btn : m_ListBtn ) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(author1);
	window->draw(author2);
	window->draw(clas);
	window->draw(team);
}