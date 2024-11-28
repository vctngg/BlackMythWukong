#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSHeal :public IFState {
public:
	FSHeal(IFrog* frog);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;

};
