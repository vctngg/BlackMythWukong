#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "PBullet.h"

class PlayerWeapon {
public:
	PlayerWeapon();
	~PlayerWeapon();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void Fire(sf::Vector2f startPoint);
private:
	std::list<PBullet*> m_ListBullet;
	int m_Num;
	float m_currentTime;
};
