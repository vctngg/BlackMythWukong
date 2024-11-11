#pragma once
#include "../GameManager/ResourceManager.h"
#include "Guard.h"
#include "Dog.h"
#include "CollisionManager.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	std::list<Dog*> GetDog();

private:
	/*void SpawnRino();
	void SpawnBat();*/
	/*std::list<CreepRino*> m_ListCreepRino;
	std::list<CreepBat*> m_ListCreepBat;*/
	void SpawnGuards();
	std::list<Guard*> m_listGuard;
	int m_GuardNum;

	std::list<Dog*> m_Dog;
	void SpawnDog();

	int m_EntityCount;
	int m_EntityCap;
	float m_TimeSpwanCreep;
	float m_currentTime;
};