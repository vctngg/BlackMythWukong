#pragma once
#include "IPState.h"
#include "IPlayer.h"
#include "../../GameStateManager/GameStateMachine.h"

class PSIdle :public IPState {
public:
	PSIdle(IPlayer* player);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation* m_Animation;
	float m_currentTime;
};

