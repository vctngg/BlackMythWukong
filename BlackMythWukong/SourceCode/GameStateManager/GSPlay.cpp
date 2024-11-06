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
	m_Background.Init(GLACIAL_MOUNTAIN);
	m_Player.Init(m_CollisionManager);
	m_Boss.Init(m_CollisionManager);
	m_CreepManager.Init(m_CollisionManager);

	//UI
	m_playerUI.Init(*DATA->getTexture("UI/HP/HP"), sf::Vector2i(9, 1),sf::Vector2f(171,26),9, sf::Vector2f(2.5, 2.5));
	m_playerUI2.Init(*DATA->getTexture("wukong/wukong_icon"), sf::Vector2i(4, 1), sf::Vector2f(58, 74), 4, sf::Vector2f(4, 4));
	m_playerUI2.SetAnimate(0.2f);
	m_playerUI3.Init(*DATA->getTexture("UI/EXP/EXP"), sf::Vector2i(8, 1), sf::Vector2f(162, 42), 8, sf::Vector2f(2.5, 2.5));
	m_playerUI4.Init(*DATA->getTexture("UI/PLAYER-UI"), sf::Vector2i(1, 1), sf::Vector2f(130, 50), 1, sf::Vector2f(4, 4));

	//Dialog manager
	m_dialogManager.Init(1);
	
	// buttons
	/*GameButton* button;
	button = new GameButton();
	button->Init("skip", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - 50, screenHeight / 2 + screenHeight / 10 - 50), 2, sf::Vector2f(50, 50), sf::Vector2f(1, 1));
	button->setOnClick([&Skip()]() {m_dialogManager.Skip(); });
	m_listButton.push_back(button);*/

	//ground debug
	rect.setSize(sf::Vector2f(screenWidth, 1));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(0, groundY));
	//score
	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(screenWidth - 100, 50);
	//music
	/*DATA->playMusic("Uprising");
	DATA->getMusic("Uprising")->setLoop(true);;
	DATA->getMusic("Uprising")->setVolume(30);*/
}

void GSPlay::Update(float deltaTime)
{
	srand(m_currentTime);
	m_dialogManager.Update(deltaTime);
	if ( m_dialogManager.IsDialog() )
	{
		for ( auto btn : m_listButton ) {
			btn->Update(deltaTime);
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::G) ) {
			m_dialogManager.Skip();//if not dialog space wont skip
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ) {
			m_dialogManager.NextDialog();
		}
	}
	else
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
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::R) ) {
				m_Background.SwitchBackground(FOREST);
			}

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
			m_CreepManager.Update(deltaTime);
			m_CollisionManager.Update(deltaTime);

			ManagePlayerHP();
			ManagePlayerEXP();
		}

		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F) ) {
			m_dialogManager.TriggerDialog();
		}
		
	}
	m_playerUI.Update(deltaTime);
	m_playerUI2.Update(deltaTime);
	m_playerUI3.Update(deltaTime);
	m_playerUI4.Update(deltaTime);
	
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	m_CreepManager.Render(window);
	m_Boss.Render(window);
	m_Player.Render(window);
	window->draw(m_Score);
	
	window->draw(m_playerUI4);
	window->draw(m_playerUI3);
	window->draw(m_playerUI2);
	window->draw(m_playerUI);

	if ( m_dialogManager.IsDialog() )
	{
		m_dialogManager.Render(window);
		for ( auto btn : m_listButton ) {
			btn->Render(window);
		}
	}
	

	window->draw(rect);

}

void GSPlay::ManagePlayerHP()
{
	float hpperframe = m_Player.getHitBox()->GetTotalHP() / 9;//HP bar has 9 frames
	int frame = (int)((m_Player.getHitBox()->GetTotalHP() - m_Player.getHitBox()->GetCurrentHP()) / hpperframe)+1;
	m_playerUI.ChangeFrame(frame);
}
void GSPlay::ManagePlayerEXP()
{
	float expperframe = m_Player.getHitBox()->GetTotalHP() / 8;//EXP bar has 8 frames
	int frame = (int)((m_Player.getHitBox()->GetTotalHP() - m_Player.getHitBox()->GetCurrentHP()) / expperframe) + 1;
	m_playerUI3.ChangeFrame(8 - frame + 1);
}
