#include "GSPlay2.h"

GSPlay2::GSPlay2()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay2::~GSPlay2()
{
}

void GSPlay2::Exit()
{
}

void GSPlay2::Pause()
{
}

void GSPlay2::Resume()
{
}

void GSPlay2::Init()
{
	m_Background.Init(FOREST);
	m_Player.Init();
	m_CreepManager.Init(2);

	//UI
	m_playerUI.Init(*DATA->getTexture("UI/HP/HP"), sf::Vector2i(9, 1), sf::Vector2f(171, 26), 9, sf::Vector2f(2.5, 2.5));
	m_playerUI2.Init(*DATA->getTexture("wukong/wukong_icon"), sf::Vector2i(4, 1), sf::Vector2f(58, 74), 4, sf::Vector2f(4, 4));
	m_playerUI2.SetAnimate(0.2f);
	m_playerUI3.Init(*DATA->getTexture("UI/EXP/EXP"), sf::Vector2i(8, 1), sf::Vector2f(162, 42), 8, sf::Vector2f(2.5, 2.5));
	m_playerUI4.Init(*DATA->getTexture("UI/PLAYER-UI"), sf::Vector2i(1, 1), sf::Vector2f(130, 50), 1, sf::Vector2f(4, 4));

	//Dialog manager
	DM->Init(2);

	//ground debug
	rect.setSize(sf::Vector2f(screenWidth, 1));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(0, groundY));
	//score
	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(screenWidth - 100, 50);
	//title
	m_title.setFont(*DATA->getFont("ARCADE"));
	m_title.setString("STAGE 1");
	m_title.setFillColor(sf::Color::White);
	m_title.setScale(3, 3);
	m_title.setPosition(screenWidth/2- m_title.getGlobalBounds().getSize().x/2, screenHeight / 2 - m_title.getGlobalBounds().getSize().y / 2);
}

void GSPlay2::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	srand(m_currentTime);
	DM->Update(deltaTime);
	if ( DM->IsDialog() )
	{

	}
	else
	{
		LM->Update(deltaTime);
		if ( m_Player.getHitBox()->isAlive() ) {
			m_currentTime += deltaTime;
			
		}
		else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);
		UpdateBackground(deltaTime);
		m_Player.Update(deltaTime);
		if ( m_Player.getHitBox()->isAlive() )
		{
			m_CreepManager.Update(deltaTime, m_Player.m_offset, m_Player.getHitBox());
			CM->Update(deltaTime);

			ManagePlayerHP();
			ManagePlayerEXP();
		}
	}
	m_playerUI.Update(deltaTime);
	m_playerUI2.Update(deltaTime);
	m_playerUI3.Update(deltaTime);
	m_playerUI4.Update(deltaTime);
}

void GSPlay2::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Score);

	window->draw(m_playerUI4);
	window->draw(m_playerUI3);
	window->draw(m_playerUI2);
	window->draw(m_playerUI);

	m_Player.Render(window);
	m_CreepManager.Render(window);

	window->draw(rect);

	if (m_currentTime < 2 )
	{
		window->draw(m_title);
	}
}

void GSPlay2::UpdateBackground(float deltaTime)
{
	if ( m_Player.getHitBox()->isAlive() ) {
		if ( m_Player.getHitBox()->getPosition().x < screenWidth / 4 || m_Player.getHitBox()->getPosition().x > screenWidth * 3 / 4 )
		{
			if ( m_Player.IsMoving() )
			{
				m_Background.Update(deltaTime);
			}
		}
	}
}

void GSPlay2::ManagePlayerHP()
{
	float hpperframe = m_Player.getHitBox()->GetTotalHP() / 9;//HP bar has 9 frames
	int frame = (int)((m_Player.getHitBox()->GetTotalHP() - m_Player.getHitBox()->GetCurrentHP()) / hpperframe) + 1;
	m_playerUI.ChangeFrame(frame);
}

void GSPlay2::ManagePlayerEXP()
{
	float expperframe = m_Player.getHitBox()->GetTotalHP() / 8;//EXP bar has 8 frames
	int frame = (int)((m_Player.getHitBox()->GetTotalHP() - m_Player.getHitBox()->GetCurrentHP()) / expperframe) + 1;
	m_playerUI3.ChangeFrame(8 - frame + 1);
}
