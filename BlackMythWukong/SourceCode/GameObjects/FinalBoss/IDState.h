#pragma once
#include "DemonWeapon.h"
#include "../ObjectManager/Collision/MovementCheck.h"
#include "../ObjectManager/Skill/SkillManager.h"

class IDState {
public:
	enum STATE
	{
		IDLE,
		RUN,
		HURT,
		TRANSFORM,
		IDLE_DEMON,
		RUN_DEMON,
		HURT_DEMON,
		CLEAVE,
		SMASH,
		FIRE_BREATH,
		CAST_SPELL,
		DEATH,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, SkillManager& SM) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};
