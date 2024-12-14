#include "GSFinal.h"

GSFinal::GSFinal()
{
	m_currentScore = 500;
	m_currentTime = 0.f;
}

GSFinal::~GSFinal()
{
}

void GSFinal::Exit()
{
}

void GSFinal::Pause()
{
}

void GSFinal::Resume()
{
}

void GSFinal::Init()
{
	m_Background.Init(AUTUMN_FOREST);
	m_Player.Init(CM,SM);
	LM.Init();
	m_Demon.Init(CM,SM);

	//UI
	m_playerUI.Init(*DATA->getTexture("UI/HP/HP"), sf::Vector2i(9, 1), sf::Vector2f(171, 26), 9, sf::Vector2f(2.5, 2.5));
	m_playerUI2.Init(*DATA->getTexture("wukong/wukong_icon"), sf::Vector2i(4, 1), sf::Vector2f(58, 74), 4, sf::Vector2f(4, 4));
	m_playerUI2.SetAnimate(0.2f);
	m_playerUI3.Init(*DATA->getTexture("UI/EXP/EXP"), sf::Vector2i(8, 1), sf::Vector2f(162, 42), 8, sf::Vector2f(2.5, 2.5));
	m_playerUI4.Init(*DATA->getTexture("UI/PLAYER-UI"), sf::Vector2i(1, 1), sf::Vector2f(130, 50), 1, sf::Vector2f(4, 4));

	skill1.Init(*DATA->getTexture("UI/ATK/1"), sf::Vector2i(4, 1), sf::Vector2f(screenWidth - 320, screenHeight - 32), 4, sf::Vector2f(4, 4));
	skill2.Init(*DATA->getTexture("UI/ATK/2"), sf::Vector2i(4, 1), sf::Vector2f(screenWidth - 250, screenHeight - 32), 4, sf::Vector2f(4, 4));
	skill3.Init(*DATA->getTexture("UI/ATK/3"), sf::Vector2i(4, 1), sf::Vector2f(screenWidth - 180, screenHeight - 32), 4, sf::Vector2f(4, 4));
	skill4.Init(*DATA->getTexture("UI/ATK/4"), sf::Vector2i(4, 1), sf::Vector2f(screenWidth - 90, screenHeight - 32), 4, sf::Vector2f(4, 4));

	ui.setTexture(*DATA->getTexture("UI/ui"));
	ui.setScale(2, 2);
	ui.setPosition(sf::Vector2f(0, screenHeight - 75));

	//Dialog manager
	DM->Init(2);

	//ground debug
	rect.setSize(sf::Vector2f(screenWidth, 1));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(0, groundY));
	//score
	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("500");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(screenWidth - 100, 50);
	//title
	m_title.setFont(*DATA->getFont("ARCADE"));
	m_title.setString("BOSS STAGE");
	m_title.setFillColor(sf::Color::White);
	m_title.setScale(3, 3);
	m_title.setPosition(screenWidth / 2 - m_title.getGlobalBounds().getSize().x / 2, screenHeight / 2 - m_title.getGlobalBounds().getSize().y / 2);
	//music
	DATA->playMusic("summer");
	DATA->getMusic("summer")->setLoop(true);
	DATA->getMusic("summer")->setVolume(30);
}

void GSFinal::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	srand(m_currentTime);
	DM->Update(deltaTime);
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) ) {
		m_Demon.getHitBox()->SetCurrentHP(0);
	}
	if ( DM->IsDialog() )
	{

	}
	else
	{ 
		LM.Update(deltaTime,SM);
		SM.Update(deltaTime);
		if ( m_Player.getHitBox()->isAlive() ) {
			m_currentTime += deltaTime;
			//m_currentScore = LM.GetCurrentExp();
			m_Score.setString(std::to_string(m_currentScore));
		}
		else ScoreManager::GetInstance()->setCurrentScore(m_currentScore+1000);
		UpdateBackground(deltaTime);
		m_Player.Update(deltaTime,SM);
		if ( m_Player.getHitBox()->isAlive() )
		{
			m_Demon.GetDistanceFromPlayer(m_Player.getHitBox(),CM);
			m_Demon.GetPlayerPosition(m_Player.getHitBox());
			m_Demon.Update(deltaTime, m_Player.m_offset,SM);
			CM.Update(deltaTime,LM);

			ManageUI();
		}
	}
	m_playerUI.Update(deltaTime);
	m_playerUI2.Update(deltaTime);
	m_playerUI3.Update(deltaTime);
	m_playerUI4.Update(deltaTime);

	skill1.Update(deltaTime);
	skill2.Update(deltaTime);
	skill3.Update(deltaTime);
	skill4.Update(deltaTime);
}

void GSFinal::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);

	window->draw(m_Score);

	window->draw(m_playerUI4);
	window->draw(m_playerUI3);
	window->draw(m_playerUI2);
	window->draw(m_playerUI);
	window->draw(ui);
	window->draw(skill1);
	window->draw(skill2);
	window->draw(skill3);
	window->draw(skill4);

	m_Player.Render(window);
	m_Demon.Render(window);

	//window->draw(rect);

	if ( m_currentTime < 2 )
	{
		window->draw(m_title);
	}
}

void GSFinal::UpdateBackground(float deltaTime)
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

void GSFinal::ManagePlayerHP()
{
	float hpperframe = m_Player.getHitBox()->GetTotalHP() / 9;//HP bar has 9 frames
	int frame = (int)((m_Player.getHitBox()->GetTotalHP() - m_Player.getHitBox()->GetCurrentHP()) / hpperframe) + 1;
	m_playerUI.ChangeFrame(frame);
}

void GSFinal::ManagePlayerEXP()
{
	float expperframe = LM.GetExpPerLevel() / 8;//EXP bar has 8 frames
	int frame = (int)((LM.GetExpToLevelUp() - LM.GetCurrentExp()) / expperframe) + 1;
	m_playerUI3.ChangeFrame(frame);
}

void GSFinal::ManagePlayerSkill()
{
	float frametime1 = SM.GetCD(PLAYER_ATTACK_1) / 3;
	int frame1 = 1;
	if ( !SM.IsOnCD(PLAYER_ATTACK_1) ) {
		frame1 = 1;
	}
	else
	{
		frame1 = 4 - (int)(SM.GetTime(PLAYER_ATTACK_1) / frametime1);
	}
	skill1.ChangeFrame(frame1);

	float frametime2 = SM.GetCD(PLAYER_ATTACK_2) / 3;
	int frame2 = 1;
	if ( !SM.IsOnCD(PLAYER_ATTACK_2) ) {
		frame2 = 1;
	}
	else
	{
		frame2 = 4 - (int)(SM.GetTime(PLAYER_ATTACK_2) / frametime2);
	}
	skill2.ChangeFrame(frame2);

	float frametime3 = SM.GetCD(PLAYER_ATTACK_3) / 3;
	int frame3 = 1;
	if ( !SM.IsOnCD(PLAYER_ATTACK_3) ) {
		frame3 = 1;
	}
	else
	{
		frame3 = 4 - (int)(SM.GetTime(PLAYER_ATTACK_3) / frametime3);
	}
	skill3.ChangeFrame(frame3);

	float frametime4 = SM.GetCD(PLAYER_SKILL_SUMMON) / 3;
	int frame4 = 1;
	if ( !SM.IsOnCD(PLAYER_SKILL_SUMMON) ) {
		frame4 = 1;
	}
	else
	{
		frame4 = 4 - (int)(SM.GetTime(PLAYER_SKILL_SUMMON) / frametime4);
	}
	skill4.ChangeFrame(frame4);
}

void GSFinal::ManageUI()
{
	ManagePlayerHP();
	ManagePlayerEXP();
	ManagePlayerSkill();
}
