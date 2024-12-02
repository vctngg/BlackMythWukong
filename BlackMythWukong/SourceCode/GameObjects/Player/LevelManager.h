#pragma once
#include "../ObjectManager/Skill/SkillManager.h"
#define LM Level::GetInstance()

class Level :public CSingleton<Level>
{
public:
	void Init();
	void Update(float deltaTime);
	void Reset();
	void LevelUp();
	int GetCurrentLevel();
	void GetExp(bool met_requirement);
	void ObtainSkill();
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