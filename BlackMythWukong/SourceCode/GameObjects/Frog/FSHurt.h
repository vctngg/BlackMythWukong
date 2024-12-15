#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSHurt :public IFState {
public:
	FSHurt(IFrog* frog);
	void Init();
	void Update(float deltaTime, SkillManager& CM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;
	bool sound;
};