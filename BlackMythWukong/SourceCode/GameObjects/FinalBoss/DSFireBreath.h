#pragma once
#include "IDState.h"
#include "IDemon.h"

class DSFireBreath :public IDState {
public:
	DSFireBreath(IDemon* demon);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IDemon* m_Demon;
	Animation* m_Animation;

};