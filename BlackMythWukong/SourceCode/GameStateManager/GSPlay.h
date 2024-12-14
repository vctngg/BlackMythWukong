#pragma once
#include "GameStateBase.h"

#include "../GameObjects/Background/ParallelBackground.h"

#include "../GameObjects/Player/Player.h"
#include "../GameObjects/Erlang/Boss.h"
#include "../GameObjects/Creep/CreepManager.h"

#include "../GameObjects/UI/DialogManager.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void UpdateBackground(float deltaTime);

	void ManageUI();
	void ManagePlayerHP();
	void ManagePlayerEXP();
	void ManagePlayerSkill();
private:
	ParallexBackground m_Background;
	Player m_Player;
	CreepManager m_CreepManager;
	Boss m_Boss;

	int m_currentScore;
	float m_currentTime;

	sf::Text m_Score;

	UI m_playerUI;
	UI m_playerUI2;
	UI m_playerUI3;
	UI m_playerUI4;

	UI skill1;
	UI skill2;
	UI skill3;
	UI skill4;

	Level LM;
	SkillManager SM;
	CollisionManager CM;

	//trigger stuff
	bool m_bossTrigger = false;
	bool m_bossPhase2 = false;
	bool m_bossStateTrigger = false;
	bool m_bossAxe = false;
	float m_axeTimer = 0;
	bool m_bgTrigger = false;
	float m_fadeTimer = 0;
	sf::RectangleShape shape;
	float alpha = 255;
	//debug
	sf::RectangleShape rect;
	sf::Sprite ui;
};
