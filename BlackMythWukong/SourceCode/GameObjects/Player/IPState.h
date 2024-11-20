#pragma once
#include "PlayerWeapon.h"
#include "../ObjectManager/Collision/MovementCheck.h"
#include "LevelManager.h"

class IPState {
public:
	enum STATE
	{
		IDLE,
		RUN,
		JUMP,
		FALL,
		DEATH,
		ATTACK1,
		ATTACK2,
		ATTACK3,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};
