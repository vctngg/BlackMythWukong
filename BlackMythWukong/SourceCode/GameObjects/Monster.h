#pragma once
#include "Creep.h"
#include "MonsterWeapon.h"

class Monster :public Creep {
public:
	~Monster();
	void Update(float deltaTime, sf::Vector2f offset, HitBox* player_hitbox);
	void Init();
	void Chop();
	void Strike();
	void Swing();
	MonsterWeapon* GetWeapon();
private:
	float m_attackTimer;

	Animation* m_chopAni;
	Animation* m_strikeAni;
	Animation* m_swingAni;

	Skill* m_skillChop;
	Skill* m_skillStrike;
	Skill* m_skillSwing;

	MonsterWeapon* m_weapon;
};