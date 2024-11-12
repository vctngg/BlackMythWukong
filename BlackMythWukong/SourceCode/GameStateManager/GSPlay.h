#pragma once
#include "GameStateBase.h"

#include "../GameObjects/ParallelBackground.h"

#include "../GameObjects/Player.h"
#include "../GameObjects/Boss.h"
#include "../GameObjects/CreepManager.h"

#include "../GameObjects/DialogManager.h"

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

	void ManagePlayerHP();
	void ManagePlayerEXP();
private:
	ParallexBackground m_Background;
	Player m_Player;
	CreepManager m_CreepManager;
	CollisionManager m_CollisionManager;
	Boss m_Boss;

	int m_currentScore;
	float m_currentTime;

	sf::Text m_Score;

	UI m_playerUI;
	UI m_playerUI2;
	UI m_playerUI3;
	UI m_playerUI4;

	std::list<GameButton*> m_listButton;

	DialogManager m_dialogManager;

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
};
