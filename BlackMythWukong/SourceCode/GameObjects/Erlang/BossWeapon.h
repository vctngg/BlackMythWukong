#pragma once
#include "../ObjectManager/Collision/CollisionManager.h"
#include "../../GameManager/ResourceManager.h"
#include "Bullet.h"

class BossWeapon {
public:
	BossWeapon();
	~BossWeapon();
	void Init();
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void Fire(sf::Vector2f startPoint);
	void Axe(sf::Vector2f startPoint);
private:
	std::list<Bullet*> m_ListBullet;
	int m_Num;
	float m_currentTime;
};