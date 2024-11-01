#pragma once
#include "IPState.h"
#include "HitBox.h"

class IPlayer :public MovementCheck
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};
