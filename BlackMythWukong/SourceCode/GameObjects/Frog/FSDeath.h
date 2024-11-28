#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSDeath :public IFState {
public:
	FSDeath(IFrog* frog);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;
	float m_currentTime;
};
