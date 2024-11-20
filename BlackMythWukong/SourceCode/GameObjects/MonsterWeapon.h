#pragma once
#include "../GameManager/ResourceManager.h"
#include "CollisionManager.h"
#include "MBullet.h"
#include "MNA.h"

class MonsterWeapon {
public:
	MonsterWeapon();
	~MonsterWeapon();
	void Init();
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void Fire(sf::Vector2f startPoint);
	void NA(sf::Vector2f startPoint);
private:
	std::list<MBullet*> m_ListBullet;
	std::list<MNA*> m_ListNA;
	int m_Num;
	float m_currentTime;
};