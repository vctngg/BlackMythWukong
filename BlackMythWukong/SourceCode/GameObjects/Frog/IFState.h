#pragma once
#include "FrogWeapon.h"
#include "../ObjectManager/Collision/MovementCheck.h"
#include "../ObjectManager/Skill/SkillManager.h"

class IFState {
public:
	enum STATE
	{
		SNULL,
		HURT,
		IDLE,
		ATTACK,
		RUN,
		HEAL,
		SPIT,
		DEATH,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, SkillManager& SM) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};