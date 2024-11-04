#pragma once
#include "IPState.h"
#include "HitBox.h"
#include "LevelManager.h"


class IPlayer :public MovementCheck
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual PlayerWeapon* getWeapon() = 0;
	Level m_LevelManager;
};
