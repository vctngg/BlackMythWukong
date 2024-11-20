#pragma once
#include "BossWeapon.h"
#include "../ObjectManager/Collision/MovementCheck.h"
#include "../ObjectManager/Skill/SkillManager.h"

class IBState {
public:
	enum STATE
	{
		SNULL,
		HURT,
		IDLE,
		ATTACK,
		RUN,
		WAITING,
		FLEE,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};