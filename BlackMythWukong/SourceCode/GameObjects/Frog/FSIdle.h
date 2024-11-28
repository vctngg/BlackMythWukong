#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSIdle :public IFState {
public:
	FSIdle(IFrog* frog);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;
	Skill* skill;

};