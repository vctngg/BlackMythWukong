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
	DM->Init(1);
	
	// buttons
	/*GameButton* button;
	button = new GameButton();
	button->Init("skip", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 - 50, screenHeight / 2 + screenHeight / 10 - 50), 2, sf::Vector2f(50, 50), sf::Vector2f(1, 1));
	button->setOnClick([]() {DM->Skip(); });
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
	shape.setSize(sf::Vector2f(screenWidth, screenHeight));
	shape.setFillColor(sf::Color(0, 0, 0, alpha));
}

void GSPlay::Update(float deltaTime)
{
	srand(m_currentTime);
	DM->Update(deltaTime);
	if ( DM->IsDialog() )
	{
		for ( auto btn : m_listButton ) {
			btn->Update(deltaTime);
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::G) ) {
			GSM->ChangeState(StateTypes::PLAY2);
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ) {
			DM->NextDialog();
		}
		if ( DM->GetCurrentDialog() == 52 ) {
			printf("change");
			GSM->ChangeState(StateTypes::PLAY2);
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
		UpdateBackground(deltaTime);
		if ( m_Player.getHitBox()->isAlive() )
		{
			m_Boss.GetDistanceFromPlayer(m_Player.getHitBox());
			m_Boss.GetPlayerPosition(m_Player.getHitBox());
		}
		m_Player.Update(deltaTime);
		if ( m_Player.getHitBox()->isAlive() ) {
			
			m_Boss.Update(deltaTime, m_Player.m_offset);
			if ( !m_Boss.getHitBox()->isAlive() && !m_Boss.m_isWaiting ) {
				if(!m_bossTrigger )
				{
					m_bossTrigger = true;
					DM->TriggerDialog();
				}
			}
			if ( DM->GetCurrentDialog() == 7 ) {
				for ( auto dog : m_CreepManager.GetDog() ) {
					dog->TriggerThreaten(deltaTime);
				}
			}
			if ( DM->GetCurrentDialog() == 27 ) {
				for ( auto dog : m_CreepManager.GetDog() ) {
					dog->TriggerRetreat(deltaTime);
				}
				if (!m_bossStateTrigger )
				{
					m_bossStateTrigger = true;
					m_Boss.changeNextState(IBState::STATE::IDLE);
					m_Boss.getHitBox()->setAlive(true);
				}
			}
			if ( m_Boss.getHitBox()->GetCurrentHP() / m_Boss.getHitBox()->GetTotalHP() <= 0.5 && !m_bossPhase2 ) {
				m_bossPhase2 = true;
				DM->TriggerDialog();
			}
			if ( DM->GetCurrentDialog() == 33 ) {
				if ( !m_bossAxe ) {
					m_bossAxe = true;
					m_Boss.getWeapon()->Axe(m_Boss.getHitBox()->getPosition());
				}
				m_axeTimer += deltaTime;
				if ( m_axeTimer > 3 ) {
					DM->TriggerDialog();
				}
			}
			m_CreepManager.Update(deltaTime, m_Player.m_offset);
			m_CollisionManager.Update(deltaTime);

			ManagePlayerHP();
			ManagePlayerEXP();
		}

		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::F) ) {
			DM->TriggerDialog();
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
	if ( DM->GetCurrentDialog() < 37 )
	{
		m_CreepManager.Render(window);
		m_Boss.Render(window);
		m_Player.Render(window);
	}
	window->draw(m_Score);
	
	window->draw(m_playerUI4);
	window->draw(m_playerUI3);
	window->draw(m_playerUI2);
	window->draw(m_playerUI);

	if ( DM->IsDialog() )
	{
		DM->Render(window);
		for ( auto btn : m_listButton ) {
			btn->Render(window);
		}
	}


	window->draw(rect);
	if ( !m_Boss.getHitBox()->isAlive() && !m_Boss.m_isWaiting && DM->GetCurrentDialog() == 37 && !DM->IsDialog() )
	{
		window->draw(shape);
	}
}

void GSPlay::UpdateBackground(float deltaTime)
{
	if ( m_Player.getHitBox()->isAlive() )
	{
		if (!m_Boss.getHitBox()->isAlive() && !m_Boss.m_isWaiting && DM->GetCurrentDialog() == 37 && !DM->IsDialog() ) {
			if ( !m_bgTrigger )
			{
				m_bgTrigger = true;
				m_Background.SwitchBackground(FOREST);
			}
			m_fadeTimer += deltaTime;
			if ( m_fadeTimer >= 3 ) {
				if ( alpha >=0 ) {
					alpha -= 2.4;
				}
				else {
					alpha = 0;
				}
			}
			if ( alpha == 0 ) {
				DM->TriggerDialog();
			}
			shape.setFillColor(sf::Color(0, 0, 0, alpha));
		}

		if ( m_Player.getHitBox()->getPosition().x < screenWidth / 4 || m_Player.getHitBox()->getPosition().x > screenWidth * 3 / 4 )
		{
			if ( m_Player.IsMoving() )
			{
				m_Background.Update(deltaTime);
			}
		}
	}
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
