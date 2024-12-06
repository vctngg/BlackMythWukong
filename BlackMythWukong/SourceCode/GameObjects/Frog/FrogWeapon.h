#pragma once
#include "../ObjectManager/Collision/CollisionManager.h"
#include "../../GameManager/ResourceManager.h"
#include "FBullet.h"
#include "FNA.h"

class FrogWeapon {
public:
	FrogWeapon();
	~FrogWeapon();
	void Init(CollisionManager& CM);
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void Spit(sf::Vector2f startPoint);
	void Lick(sf::Vector2f startPoint);
private:
	std::list<FBullet*> m_ListBullet;
	std::list<FNA*> m_ListNA;
	int m_Num;
	float m_currentTime;
};

