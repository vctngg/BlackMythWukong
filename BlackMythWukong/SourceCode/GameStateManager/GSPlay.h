#pragma once
#include "GameStateBase.h"

#include "../GameObjects/ParallelBackground.h"

#include "../GameObjects/Player.h"
#include "../GameObjects/Boss.h"
#include "../GameObjects/UI.h"

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

	void ManagePlayerHP();
	void ManagePlayerEXP();
private:
	ParallexBackground m_Background;
	Player m_Player;
	//CreepManager m_CreepManager;
	CollisionManager m_CollisionManager;
	Boss m_Boss;

	int m_currentScore;
	float m_currentTime;

	sf::Text m_Score;

	UI m_playerUI;
	UI m_playerUI2;
	UI m_playerUI3;
	UI m_playerUI4;

	sf::RectangleShape rect;
};
