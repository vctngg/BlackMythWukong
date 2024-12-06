#pragma once
#include "../ObjectManager/Skill/SkillManager.h"

class Level
{
public:
	void Init();
	void Update(float deltaTime, SkillManager& skillmanager);
	void Reset();
	void LevelUp(SkillManager& skillmanager);
	int GetCurrentLevel();
	void GetExp(bool met_requirement);
	void ObtainSkill(SkillManager& skillmanager);
	float GetExpPerLevel() {
		return m_expPerLevel;
	}
	float GetExpToLevelUp()
	{
		return m_expToLevelUp;
	}
	float GetCurrentExp() {
		return m_exp;
	}
private:
	int m_currentLevel;
	float m_exp;
	float m_expPerLevel;
	float m_expToLevelUp;
};