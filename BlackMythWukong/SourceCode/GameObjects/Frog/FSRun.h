#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSRun :public IFState {
public:
	FSRun(IFrog* frog);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;

};