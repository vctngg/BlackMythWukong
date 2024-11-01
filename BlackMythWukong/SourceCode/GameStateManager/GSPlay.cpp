#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	m_Background.Init();
	m_Player.Init(m_CollisionManager);
	m_Boss.Init(m_CollisionManager);
	//m_CreepManager.Init(m_CollisionManager);

	//UI
	m_playerUI.Init(*DATA->getTexture("UI/HP/HP"), sf::Vector2i(3, 3),sf::Vector2f(100,50),7);
	m_playerUI.setScale(4, 4);
	m_playerUI2.Init(*DATA->getTexture("UI/HP/HPBar"), sf::Vector2i(1, 1), sf::Vector2f(100, 50), 1);
	m_playerUI2.setScale(4, 4);

	//ground debug
	rect.setSize(sf::Vector2f(screenWidth, 1));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(0, groundY));
	//score
	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(screenWidth - 100, 50);

	/*DATA->playMusic("Uprising");
	DATA->getMusic("Uprising")->setLoop(true);;
	DATA->getMusic("Uprising")->setVolume(30);*/
}

void GSPlay::Update(float deltaTime)
{
	if ( m_Player.getHitBox()->isAlive() ) {
		m_currentTime += deltaTime;
		if ( m_currentTime >= 0.5f ) {
			m_currentScore++;
			m_Score.setString(std::to_string(m_currentScore));
			m_currentTime -= 1.f;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);

	if ( m_Player.getHitBox()->isAlive() ) 
	{
		if ( m_Player.getHitBox()->getPosition().x < screenWidth / 4 || m_Player.getHitBox()->getPosition().x > screenWidth * 3 / 4 )
		{
			if ( m_Player.getHitBox()->getPosition().x < screenWidth / 4 ) {
				m_Player.getHitBox()->setPosition(screenWidth / 4, m_Player.getHitBox()->getPosition().y);
			}
			if ( m_Player.getHitBox()->getPosition().x > screenWidth * 3 / 4 ) {
				m_Player.getHitBox()->setPosition(screenWidth * 3 / 4, m_Player.getHitBox()->getPosition().y);
			}
			if ( m_Player.IsMoving() )
			{
				m_Background.Update(deltaTime);
			}
		}//screen scrolling mechanic
		m_Boss.GetDistanceFromPlayer(m_Player.getHitBox());
		m_Boss.GetPlayerPosition(m_Player.getHitBox());
	}
	m_Player.Update(deltaTime);
	if ( m_Player.getHitBox()->isAlive() ) {
		m_Boss.Update(deltaTime);
		//m_CreepManager.Update(deltaTime);
		m_CollisionManager.Update();
	}

	m_playerUI.Update(deltaTime);
	m_playerUI2.Update(deltaTime);
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	m_Boss.Render(window);
	m_Player.Render(window);
	//m_CreepManager.Render(window);
	window->draw(m_Score);

	window->draw(m_playerUI);
	window->draw(m_playerUI2);

	window->draw(rect);

}