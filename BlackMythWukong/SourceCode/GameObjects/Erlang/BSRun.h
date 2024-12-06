#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSRun :public IBState {
public:
	BSRun(IBoss* boss);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IBoss* m_Boss;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;

};