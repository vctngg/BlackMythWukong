#include "GSMenu.h"

GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	GameButton* button;
	//Title
	m_Title.setString("Black Myth: Wukong");
	m_Title.setFont(*DATA->getFont("Karate"));
	m_Title.setPosition(screenWidth / 5, screenHeight / 5);
	m_Title.setScale(sf::Vector2f(2, 2));
	//Title 2
	m_Title2.setString("Remastered");
	m_Title2.setFillColor(sf::Color::Red);
	m_Title2.setFont(*DATA->getFont("Karate"));
	m_Title2.setPosition(screenWidth * 3 / 5, screenHeight / 3);
	m_Title2.setScale(sf::Vector2f(1.5, 1.5));

	//PlayButton
	button = new GameButton();
	button->Init("play", sf::Vector2i(2,1), sf::Vector2f(screenWidth / 2 - 50, screenHeight / 2 + screenHeight / 10 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1,1));
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); DATA->getMusic("menu")->stop(); DATA->playSound("click"); });

	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("close", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 + screenWidth / 4 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {WConnect->getWindow()->close(); DATA->playSound("click"); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("settings", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - screenWidth / 4 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); DATA->playSound("click"); });
	m_ListBtn.push_back(button);

	//about Button
	button = new GameButton();
	button->Init("about", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 + screenWidth / 12 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); DATA->playSound("click"); });
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("achievements", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - screenWidth / 12 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); DATA->playSound("click"); });
	m_ListBtn.push_back(button);


	//Background
	sf::Texture* texture = DATA->getTexture("Monke");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 5, screenHeight);
	m_Background.setScale(sf::Vector2f(0.5, 0.5));

	ScoreManager::GetInstance()->readFile();
	DATA->playMusic("menu");
	DATA->getMusic("menu")->setLoop(true);
	DATA->getMusic("menu")->setVolume(30);
}

void GSMenu::Update(float deltaTime)
{
	for ( auto btn : m_ListBtn ) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{

	window->draw(m_Background);
	for ( auto btn : m_ListBtn ) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_Title2);
}