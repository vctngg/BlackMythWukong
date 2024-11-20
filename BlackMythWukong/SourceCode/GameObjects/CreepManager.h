#pragma once
#include "../GameManager/ResourceManager.h"
#include "Guard.h"
#include "Dog.h"
#include "Monster.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(int stage);
	void Update(float deltaTime, sf::Vector2f offset, HitBox* player_hitbox);
	void Render(sf::RenderWindow* window);
	std::list<Dog*> GetDog();

private:
	int m_stageNumber;

	void SpawnGuards();
	std::list<Guard*> m_listGuard;
	int m_GuardNum;

	std::list<Dog*> m_Dog;
	void SpawnDog();

	std::list<Monster*> m_listMonster;
	void SpawnMonster();
	int m_MonsterNum;

	int m_EntityCount;
	int m_EntityCap;
	float m_TimeSpwanCreep;
	float m_currentTime;
};