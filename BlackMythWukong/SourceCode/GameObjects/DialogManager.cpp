#include "DialogManager.h"

void DialogManager::Init(int scene_number)
{
	m_sceneNumber = scene_number;
	m_currentTime = 0;
	m_skipTimer = 0;
	m_DialogIndex = 0;
	m_dialogBox.Init(*DATA->getTexture("UI/dialog-box"), sf::Vector2i(1, 1), sf::Vector2f(screenWidth / 2, screenHeight / 2), 1, sf::Vector2f(16, 16));
	GameButton* button;
	button = new GameButton();
	button->Init("skip", sf::Vector2i(2, 1), sf::Vector2f(screenWidth / 2 + 250, screenHeight / 2 + screenHeight / 10 ), 2, sf::Vector2f(200, 200), sf::Vector2f(0.75, 0.5));
	button->setOnClick([]() mutable {&DialogManager::Skip; printf("skip!\n"); });

	m_ListBtn.push_back(button);
;
	switch ( scene_number )
	{
	case 1: 
	{
		sf::Text text;
		float box_size_x = m_dialogBox.getGlobalBounds().getSize().x;
		float box_size_y = m_dialogBox.getGlobalBounds().getSize().y;
		for ( int i=0; i < 52; i++ ) {
			text.setString(m_dialogList_Scene1[i]);
			text.setFont(*DATA->getFont("ARCADE"));
			float text_size_x = text.getLocalBounds().getSize().x;
			float text_size_y = text.getLocalBounds().getSize().y;
			
			text.setOrigin(text_size_x /2, text_size_y /2);
			text.setLineSpacing(5);
			text.setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2));
			if ( box_size_x / text_size_x < 1 ) {
				text.setScale(box_size_x / text_size_x * 0.9, 1);
			}
			
			m_currentDialog[i] = text;
		}
		//wukong
		text.setString("Sun Wukong");
		text.setFont(*DATA->getFont("ARCADE"));
		text.setOrigin(text.getLocalBounds().getSize().x / 2, text.getLocalBounds().getSize().y / 2);
		text.setPosition(sf::Vector2f(screenWidth / 3 - 50, screenHeight / 3));
		m_Char[0] = text;
		//erlang
		text.setString("Erlang the Sacred Divinity");
		text.setFont(*DATA->getFont("ARCADE"));
		text.setOrigin(text.getLocalBounds().getSize().x / 2, text.getLocalBounds().getSize().y / 2);
		text.setPosition(sf::Vector2f(screenWidth / 3, screenHeight / 3));
		m_Char[1] = text;
		//old monkey
		text.setString("Old monkey");
		text.setFont(*DATA->getFont("ARCADE"));
		text.setOrigin(text.getLocalBounds().getSize().x / 2, text.getLocalBounds().getSize().y / 2);
		text.setPosition(sf::Vector2f(screenWidth / 3 - 50, screenHeight / 3));
		m_Char[2] = text;

		m_currentChar = m_Char[0];
		break;
	}
	default: 
	{
		break;
	}
	}
	
}

void DialogManager::Update(float deltaTime)
{
	m_skipTimer += deltaTime;
	if ( m_isDialog ) {
		for ( auto btn : m_ListBtn ) {
			btn->Update(deltaTime);
		}
		m_dialogBox.Update(deltaTime);
	}
	else {
		m_currentTime += deltaTime;
		switch ( m_sceneNumber )
		{
		case 1:
		{
			if ( m_currentTime > 5 && m_currentTime < 10 ) {
				TriggerDialog();
				m_currentTime = 10;
			}
			else if ( m_currentTime > 20 && m_currentTime < 30 ) {
				TriggerDialog();
				m_currentTime = 30;
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void DialogManager::Render(sf::RenderWindow* window)
{
	if ( m_isDialog ) {
		window->draw(m_dialogBox);
		window->draw(m_currentChar);
		window->draw(m_currentDialog[m_DialogIndex]);
		for ( auto btn : m_ListBtn ) {
			btn->Render(window);
		}
	}
}

void DialogManager::Skip()
{
	EndDialog();
	
}

void DialogManager::NextDialog()
{
	if ( m_DialogIndex < 52 ) {
		if ( m_skipTimer > 2.f )
		{
			m_skipTimer = 0;
			m_DialogIndex++;
			switch ( m_sceneNumber ) {
			case 1: {
				if ( (m_DialogIndex >= 0 && m_DialogIndex <= 6) || (m_DialogIndex >= 29 && m_DialogIndex <= 31) || (m_DialogIndex >= 33 && m_DialogIndex <= 35) || (m_DialogIndex >= 18 && m_DialogIndex <= 24) ) {
					m_currentChar = m_Char[0];
				}
				else if ( (m_DialogIndex >= 7 && m_DialogIndex <= 17) || (m_DialogIndex >= 25 && m_DialogIndex <= 28) || (m_DialogIndex == 32) || (m_DialogIndex == 36) ) {
					m_currentChar = m_Char[1];
				}
				else if ( (m_DialogIndex >= 37 && m_DialogIndex <= 51) ) {
					m_currentChar = m_Char[2];
				}
				if ( m_DialogIndex == 7 || m_DialogIndex == 36 || m_DialogIndex == 39 || m_DialogIndex == 27 || m_DialogIndex == 33 || m_DialogIndex == 37 ) {
					EndDialog(); //index+1 cuz i used plus before to prevent bug
				}
				break;
			}
			default: {
				break;
			}
			}
			
		}
	}
	else {
		EndDialog();
	}
}

void DialogManager::TriggerDialog()
{
	m_isDialog = true;
}

void DialogManager::EndDialog()
{
	m_isDialog = false;
}

bool DialogManager::IsDialog()
{
	return m_isDialog;
}

