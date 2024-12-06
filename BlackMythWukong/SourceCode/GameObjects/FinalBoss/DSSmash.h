#pragma once
#include "IDState.h"
#include "IDemon.h"

class DSSmash :public IDState {
public:
	DSSmash(IDemon* demon);
	void Init();
	void Update(float deltaTime, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IDemon* m_Demon;
	Animation* m_Animation;

};