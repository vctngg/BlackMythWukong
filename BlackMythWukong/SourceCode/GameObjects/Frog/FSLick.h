#pragma once
#include "IFState.h"
#include "IFrog.h"

class FSLick :public IFState {
public:
	FSLick(IFrog* frog);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IFrog* m_Frog;
	Animation* m_Animation;

};
