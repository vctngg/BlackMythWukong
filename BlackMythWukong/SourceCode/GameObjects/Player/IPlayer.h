#pragma once
#include "IPState.h"
#include "../ObjectManager/Collision/HitBox.h"


class IPlayer :public MovementCheck
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual PlayerWeapon* getWeapon() = 0;
	sf::Vector2f m_offset = sf::Vector2f(0,0);
};
