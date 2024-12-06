#pragma once
#include "IDemon.h"

class Demon : public IDemon
{
public:
	Demon();
	~Demon();
	void changeNextState(IDState::STATE nextState);

	void Init(CollisionManager& CM, SkillManager& SM);
	void Update(float deltaTime, sf::Vector2f offset, SkillManager& SM);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	sf::Vector2f getPosition();
	DemonWeapon* getWeapon();
	void FacingCheck();
	void GetDistanceFromPlayer(HitBox* player_hitbox, CollisionManager& CM);
	float ReturnDistanceFromPlayer();
	void GetPlayerPosition(HitBox* player_hitbox);
	sf::Vector2f ReturnPlayerPosition();

private:
	void performStateChange();
	HitBox* m_HitBox;

	IDState::STATE m_nextState;

	IDState* m_currentState;
	IDState* m_runState;
	IDState* m_runDState;
	IDState* m_deathState;
	IDState* m_idleState;
	IDState* m_idleDState;
	IDState* m_hurtState;
	IDState* m_hurtDState;
	IDState* m_transformState;
	IDState* m_cleaveState;
	IDState* m_smashState;
	IDState* m_castspellState;
	IDState* m_firebreathState;


	DemonWeapon* m_DemonWeapon;
	Skill* m_skill;
};
