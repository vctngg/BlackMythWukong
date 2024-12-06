#pragma once
#include "IDState.h"
#include "IDemon.h"
#include "../../GameStateManager/GameStateMachine.h"

class DSIdle :public IDState {
public:
	DSIdle(IDemon* demon);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IDemon* m_Demon;
	Animation* m_Animation;
	float m_currentTime;
};