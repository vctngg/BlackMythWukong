#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../../Dialog.h"
#include "UI.h"
#include "../../GameManager/Singleton.h"

#define DM DialogManager::GetInstance()
class DialogManager :public CSingleton<DialogManager>
{
public:
	void Init(int scene_number);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Skip();
	void NextDialog();
	void TriggerDialog();
	void EndDialog();
	bool IsDialog();
	int GetCurrentDialog();
private:
	UI m_dialogBox;
	std::list<GameButton*> m_ListBtn;
	sf::Text m_currentDialog[100];
	sf::Text m_Char[3];
	float m_currentTime;
	float m_skipTimer;
	bool m_isDialog;
	int m_sceneNumber;
	int m_DialogIndex;
	sf::Text m_currentChar;

	//the dialogs of the entire game
	std::string m_dialogList_Scene1[52] = 
	{
		WUKONG_1_1,WUKONG_1_2,WUKONG_1_3,WUKONG_1_4,WUKONG_1_5,WUKONG_1_6,WUKONG_1_7,
		ERLANG_1_1,ERLANG_1_2,ERLANG_1_3,ERLANG_1_4,ERLANG_1_5,ERLANG_1_6,ERLANG_1_7,ERLANG_1_8,ERLANG_1_9,ERLANG_1_10,ERLANG_1_11,
		WUKONG_1_8,WUKONG_1_9,WUKONG_1_10,WUKONG_1_11,WUKONG_1_12,WUKONG_1_13,WUKONG_1_14,
		ERLANG_1_12,ERLANG_1_13,
		ERLANG_1_14,ERLANG_1_15,
		WUKONG_1_15,WUKONG_1_16,WUKONG_1_17,
		ERLANG_1_16,
		WUKONG_1_18,WUKONG_1_19,
		WUKONG_1_20,
		ERLANG_1_17,
		OLDMONKEY_1_1,OLDMONKEY_1_2,OLDMONKEY_1_3,OLDMONKEY_1_4,
		OLDMONKEY_1_5,OLDMONKEY_1_6,OLDMONKEY_1_7,OLDMONKEY_1_8,OLDMONKEY_1_9,OLDMONKEY_1_10,OLDMONKEY_1_11,OLDMONKEY_1_12,OLDMONKEY_1_13,OLDMONKEY_1_14,OLDMONKEY_1_15
	};
	std::string m_dialogList_Scene2[1] = {OLDMONKEY_2_1};

};


