#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSFlee :public IBState {
public:
	BSFlee(IBoss* boss);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IBoss* m_Boss;
	Animation* m_Animation;
	Animation* m_AnimationTalking;
	Animation* m_currentAnimation;

	float m_currentTime;
	float m_ChangeTime;
	bool m_isTalking;
};