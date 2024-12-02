#pragma once
#include "IDState.h"
#include "IDemon.h"

class DSHurt :public IDState {
public:
	DSHurt(IDemon* demon);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IDemon* m_Demon;
	Animation* m_Animation;

	float m_currentTime;
	float m_ChangeTime;

};