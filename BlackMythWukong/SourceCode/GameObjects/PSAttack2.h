#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSAttack2 :public IPState {
public:
	PSAttack2(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation* m_Animation;
	MovementCheck m_MovementCheck;
};
