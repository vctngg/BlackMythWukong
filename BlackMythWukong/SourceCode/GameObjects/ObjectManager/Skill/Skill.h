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
	FROG_SKILL_SPIT,
	FROG_SKILL_HEAL,
	FROG_SKILL_LICK,
	DEMON_SKILL_NA,
	DEMON_SKILL_SMASH,
	DEMON_SKILL_FIRE,
	DEMON_SKILL_SPELL,
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