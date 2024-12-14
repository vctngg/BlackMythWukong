#pragma once
#include "Skill.h"

class SkillManager
{
public:
	void AddSkill(Skill* skill);
	void Update(float deltaTime);
	bool IsOnCD(SKILL skill);
	void SetOnCD(SKILL skill);
	void LockSkill(SKILL skill);
	void UnlockSkill(SKILL skill);
	bool IsUnlocked(SKILL skill);
	float GetCD(SKILL skill);
	float GetTime(SKILL skill);
private:
	std::list<Skill*> m_listSkill;
	
};