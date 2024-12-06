#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSHurt :public IBState {
public:
	BSHurt(IBoss* boss);
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