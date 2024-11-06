#pragma once
#include "Creep.h"

class Dog :public Creep {
public:
	void Init();	
private:
	Animation* m_barkAni;
};