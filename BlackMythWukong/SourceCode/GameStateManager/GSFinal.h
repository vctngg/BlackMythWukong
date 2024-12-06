#pragma once
#include "GameStateBase.h"

#include "../GameObjects/Background/ParallelBackground.h"

#include "../GameObjects/Player/Player.h"
#include "../GameObjects/FinalBoss/Demon.h"
#include "../GameObjects/UI/DialogManager.h"

class GSFinal : public GameStateBase {
public:
	GSFinal();
	virtual ~GSFinal();

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
	Demon m_Demon;

	bool exp_gain = false;

	int m_currentScore;
	float m_currentTime;

	sf::Text m_Score;
	sf::Text m_title;

	UI m_playerUI;
	UI m_playerUI2;
	UI m_playerUI3;
	UI m_playerUI4;

	Level LM;
	SkillManager SM;
	CollisionManager CM;

	std::list<GameButton*> m_listButton;

	//debug
	sf::RectangleShape rect;
};

