#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	GameButton* button;
	//menu Button
	button = new GameButton();
	button->Init("home", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 + screenWidth / 12 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {
		GSM->PopState();
		GSM->PopState();
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		DATA->playSound("click");
		});
	m_ListBtn.push_back(button);

	//replay Button
	button = new GameButton();
	button->Init("restart", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - screenWidth / 12 - 50, screenHeight - screenHeight / 8 - 50), 2, sf::Vector2f(150, 150), sf::Vector2f(1, 1));
	button->setOnClick([]() {
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		ScoreManager::GetInstance()->UpdateHighScore();
		ScoreManager::GetInstance()->writeFile();
		DATA->playSound("click");
		});
	m_ListBtn.push_back(button);

	//Background
	sf::Texture* texture = DATA->getTexture("Background/Forest/Background");
	m_Background.setTexture(*texture);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y / 2);

	//Tile Game
	m_Title.setString("END GAME!");
	m_Title.setFont(*DATA->getFont("ARCADE"));
	m_Title.setPosition(screenWidth / 2 - 100, screenHeight / 5);

	//Best Score
	m_bestScore.setString("BEST SCORE: " + std::to_string(ScoreManager::GetInstance()->getBestScore()));
	m_bestScore.setFont(*DATA->getFont("ARCADE"));
	m_bestScore.setPosition(screenWidth / 2 - 100, screenHeight / 2);

	//current Score
	m_currentScore.setString("YOUR SCORE: " + std::to_string(ScoreManager::GetInstance()->getCurrentScore()));
	m_currentScore.setFont(*DATA->getFont("ARCADE"));
	m_currentScore.setPosition(screenWidth / 2 - 100, screenHeight / 2 + 50);
}

void GSEnd::Update(float deltaTime)
{
	for ( auto btn : m_ListBtn ) {
		btn->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	for ( auto btn : m_ListBtn ) {
		btn->Render(window);
	}
	window->draw(m_Title);
	window->draw(m_bestScore);
	window->draw(m_currentScore);
}