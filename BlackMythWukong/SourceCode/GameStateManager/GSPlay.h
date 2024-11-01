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
private:
	ParallexBackground m_Background;
	Player m_Player;
	CollisionManager m_CollisionManager;
	//CreepManager m_CreepManager;
	Boss m_Boss;

	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	UI m_playerUI;
	UI m_playerUI2;

	sf::RectangleShape rect;
};
