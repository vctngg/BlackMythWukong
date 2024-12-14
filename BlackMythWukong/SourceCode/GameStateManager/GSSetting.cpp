#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("close", sf::Vector2i(2, 1), sf::Vector2f(screenWidth - screenWidth / 20 - 50, screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {GSM->PopState(); DATA->playSound("click"); });
	m_ListBtn.push_back(button);
	//turn on music
	button = new GameButton();
	button->Init("sound-on", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 + screenWidth / 4 - 50 -100, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {DATA->setAllowSound(true); DATA->playSound("click"); DATA->getMusic("menu")->setVolume(30); });
	m_ListBtn.push_back(button);

	//turn off music
	button = new GameButton();
	button->Init("sound-off", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - screenWidth / 4 - 50 + 100, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {DATA->setAllowSound(false); DATA->playSound("click"); DATA->getMusic("menu")->setVolume(0); });
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background/Forest/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2 , screenHeight - texture->getSize().y / 2 );

	//Tile Game
	m_Title.setString("SETTINGS");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth / 2 - 50, screenHeight / 5 );

	a.setString("- A,D to move");
	a.setFont(*DATA->getFont("ARCADE"));
	a.setPosition(screenWidth / 8 - 200  + screenWidth / 3, screenHeight / 5 + 60 );
	b.setString("- SPACE to jump");
	b.setFont(*DATA->getFont("ARCADE"));
	b.setPosition(screenWidth / 8 - 200  + screenWidth / 3, screenHeight / 5 + 60 * 2 );
	c.setString("- J,K,L,O to attack");
	c.setFont(*DATA->getFont("ARCADE"));
	c.setPosition(screenWidth / 8 - 200  + screenWidth / 3, screenHeight / 5 + 60 * 3 );
	d.setString("- ENTER to go to the next dialog");
	d.setFont(*DATA->getFont("ARCADE"));
	d.setPosition(screenWidth / 8 - 200  + screenWidth/3, screenHeight / 5 + 60 * 4 );
}

void GSSetting::Update(float deltaTime)
{
	for ( auto btn : m_ListBtn ) {
		btn->Update(deltaTime);
	}
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Title);
	window->draw(a);
	window->draw(b);
	window->draw(c);
	window->draw(d);
	for ( auto btn : m_ListBtn ) {
		btn->Render(window);
	}
}