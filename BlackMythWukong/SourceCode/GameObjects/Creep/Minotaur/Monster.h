#pragma once
#include "../Creep.h"
#include "MonsterWeapon.h"

class Monster :public Creep {
public:
	~Monster();
	void Update(float deltaTime, sf::Vector2f offset, HitBox* player_hitbox, SkillManager& SM, CollisionManager& CM);
	void Init(SkillManager& SM);
	void Chop(SkillManager& SM);
	void Strike(SkillManager& SM);
	void Swing(SkillManager& SM);
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