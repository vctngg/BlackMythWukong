#pragma once
#include "../ObjectManager/Collision/CollisionManager.h"
#include "../../GameManager/ResourceManager.h"
#include "PBullet.h"
#include "PNA.h"

class PlayerWeapon {
public:
	PlayerWeapon();
	~PlayerWeapon();
	void Init(CollisionManager& collisionmanager);
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void Summon(sf::Vector2f startPoint);
	void Attack1(sf::Vector2f startPoint);
	void Attack2(sf::Vector2f startPoint);
	void Attack3(sf::Vector2f startPoint);
private:
	std::list<PBullet*> m_ListBullet;
	std::list<PNA*> m_ListNA;
	int m_Num;
	float m_currentTime;
};
