#pragma once
#include "IFrog.h"

class Frog : public IFrog
{
public:
	Frog();
	~Frog();
	void changeNextState(IFState::STATE nextState);

	void Init(CollisionManager& CM, SkillManager& SM);
	void Update(float deltaTime, sf::Vector2f offset, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	void FacingCheck();
	void GetDistanceFromPlayer(HitBox* player_hitbox, CollisionManager& CM);
	float ReturnDistanceFromPlayer();
	void GetPlayerPosition(HitBox* player_hitbox);
	sf::Vector2f ReturnPlayerPosition();

	FrogWeapon* getWeapon();

private:
	void performStateChange();
	HitBox* m_HitBox;
	FrogWeapon* m_FrogWeapon;


	IFState::STATE m_nextState;

	IFState* m_currentState;
	IFState* m_idleState;
	IFState* m_hurtState;
	IFState* m_attackState;
	IFState* m_runState;
	IFState* m_spitState;
	IFState* m_healState;
	IFState* m_deathState;

	Skill* m_skill;

};