#pragma once
#include "IPlayer.h"

class Player : public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	sf::Vector2f getPosition();
	PlayerWeapon* getWeapon();

private:
	void performStateChange();
	HitBox* m_HitBox;

	IPState::STATE m_nextState;

	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_jumpState;
	IPState* m_fallState;
	IPState* m_deathState;
	IPState* m_attack1State;
	IPState* m_attack2State;
	IPState* m_attack3State;
	IPState* m_idleState;

	PlayerWeapon* m_PlayerWeapon;
	Skill* m_skillJ;
	Skill* m_skillK;
	Skill* m_skillL;
	Skill* m_skillO;
};
