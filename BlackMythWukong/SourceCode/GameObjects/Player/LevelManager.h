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
private:
	int m_currentLevel;
	float m_exp;
	float m_expPerLevel;
	float m_expToLevelUp;
};