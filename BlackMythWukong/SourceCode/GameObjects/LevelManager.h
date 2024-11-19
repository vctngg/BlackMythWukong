#pragma once
#include "SkillManager.h"
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
	SkillManager AccessSkillManager();
private:
	int m_currentLevel;
	float m_exp;
	float m_expPerLevel;
	float m_expToLevelUp;

	SkillManager m_SkillManager;
	Skill* m_skill1;
	Skill* m_skill2;
	Skill* m_skill3;
	Skill* m_skill4;
	Skill* m_skill5;
};