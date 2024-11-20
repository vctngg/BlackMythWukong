#pragma once
#include "HitBox.h"
#include "../../../GameManager/Singleton.h"
#define CM CollisionManager::GetInstance()

class CollisionManager :public CSingleton<CollisionManager>
{
public:
	void addObj(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	float GetDistance(HitBox* a, HitBox* b);
	void Update(float deltaTime);
private:
	std::list<HitBox*> m_listObj;
	float m_currentTime = 0;
};
