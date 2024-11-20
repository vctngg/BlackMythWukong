#pragma once
#include "IBoss.h"

class Boss : public IBoss
{
public:
	Boss();
	~Boss();
	void changeNextState(IBState::STATE nextState);

	void Init();
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void FacingCheck();
	HitBox* getHitBox();

	void GetDistanceFromPlayer(HitBox* player_hitbox);
	float ReturnDistanceFromPlayer();
	void GetPlayerPosition(HitBox* player_hitbox);
	sf::Vector2f ReturnPlayerPosition();

	BossWeapon* getWeapon();

private:
	void performStateChange();
	HitBox* m_HitBox;
	BossWeapon* m_BossWeapon;


	IBState::STATE m_nextState;

	IBState* m_currentState;
	IBState* m_idleState;
	IBState* m_hurtState;
	IBState* m_attackState;
	IBState* m_runState;
	IBState* m_waitingState;
	IBState* m_fleeState;

};