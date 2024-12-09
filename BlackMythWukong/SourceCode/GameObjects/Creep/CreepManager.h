#pragma once
#include "../../GameManager/ResourceManager.h"
#include "Guard/Guard.h"
#include "Dog/Dog.h"
#include "Minotaur/Monster.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(int stage, CollisionManager& CM, SkillManager& SM);
	void Update(float deltaTime, sf::Vector2f offset, HitBox* player_hitbox, CollisionManager& CM, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	int GetKillCounter() {
		return m_kill_counter;
	}
	std::list<Dog*> GetDog();
	std::list<Monster*> GetMonster() {
		return m_listMonster;
	}

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
	float m_TimeSpawnCreep;
	float m_currentTime;
	int m_kill_counter;
};