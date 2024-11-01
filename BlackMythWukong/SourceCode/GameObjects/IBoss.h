#pragma once
#include "IBState.h"
#include "HitBox.h"

class IBoss :public MovementCheck
{
public:
	virtual void changeNextState(IBState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual void FacingCheck() = 0;

	virtual void GetDistanceFromPlayer(HitBox* player_hitbox) = 0;
	virtual float ReturnDistanceFromPlayer() = 0;
	virtual void GetPlayerPosition(HitBox* player_hitbox) = 0;
	virtual sf::Vector2f ReturnPlayerPosition() = 0;
	float m_distanceFromPlayer;
	sf::Vector2f m_playerPosition;
	virtual BossWeapon* getWeapon() = 0;
};
