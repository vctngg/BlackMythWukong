#pragma once
#include "Creep.h"

class Dog :public Creep {
public:
	void Init();	
	void TriggerThreaten(float deltaTime);
	void TriggerRetreat(float deltaTime);
private:
	Animation* m_barkAni;
	float m_timer;
};