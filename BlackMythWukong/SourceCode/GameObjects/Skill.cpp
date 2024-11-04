#include "Skill.h"

void Skill::SetCD()
{
	switch ( m_skillType )
	{
	case (BOSS_NA): {
		m_cooldownDuration = 0.4;
		break;
		}
	case (PLAYER_SKILL_SUMMON): {
		m_cooldownDuration = 0.5;
		break;
		}
	case (PLAYER_ATTACK_1): {
		m_cooldownDuration = 1;
		break;
		}
	case (PLAYER_ATTACK_2): {
		m_cooldownDuration = 0;
		break;
		}
	case (PLAYER_ATTACK_3): {
		m_cooldownDuration = 0.4;
		break;
		}
	default: {
		break;
		}
	}
}

bool Skill::IsUnlocked()
{
	return m_isUnlocked;
}

void Skill::LockSkill()
{
	m_isUnlocked = false;
}

void Skill::UnlockSkill()
{
	m_isUnlocked = true;
}
