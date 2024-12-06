#pragma once
#include "IDState.h"
#include "IDemon.h"
#include "../../GameStateManager/GameStateMachine.h"

class DSDeath :public IDState {
public:
	DSDeath(IDemon* demon);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IDemon* m_Demon;
	Animation* m_Animation;
	float m_currentTime;
	float m_timeRemain;
};
