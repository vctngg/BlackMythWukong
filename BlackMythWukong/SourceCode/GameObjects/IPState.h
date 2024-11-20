#pragma once
#include "../GameManager/ResourceManager.h"
#include "PlayerWeapon.h"
#include "../GameObjects/CollisionManager.h"
#include "../GameObjects/MovementCheck.h"
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
