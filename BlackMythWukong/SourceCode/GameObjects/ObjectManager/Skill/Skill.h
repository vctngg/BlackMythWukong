#pragma once
#include "../../../GameManager/ResourceManager.h"
#include "CooldownManager.h"
enum SKILL {
	BOSS_NA,
	PLAYER_SKILL_SUMMON,
	PLAYER_ATTACK_1,
	PLAYER_ATTACK_2,
	PLAYER_ATTACK_3,
	MONSTER_STRIKE,
	MONSTER_CHOP,
	MONSTER_SWING,
	FROG_SPIT,
	FROG_HEAL,
	FROG_LICK,
};
class Skill :public CooldownManager
{
public:
	void SetType(SKILL skill) {
		m_skillType = skill;
		SetCD();
	}
	SKILL GetType() {
		return m_skillType;
	}
	void SetCD();
	float GetCD() {
		return m_cooldownDuration;
	}
	bool IsUnlocked();
	void LockSkill();
	void UnlockSkill();
private:
	SKILL m_skillType;
	float m_cooldownDuration;
	bool m_isUnlocked = false;
};