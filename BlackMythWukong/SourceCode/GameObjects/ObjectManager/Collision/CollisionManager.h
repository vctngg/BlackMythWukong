#pragma once
#include "HitBox.h"
#include "../../Player/LevelManager.h"

class CollisionManager 
{
public:
	void addObj(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	float GetDistance(HitBox* a, HitBox* b);
	void Update(float deltaTime, Level& LM);
private:
	std::list<HitBox*> m_listObj;
	float m_currentTime = 0;
};
