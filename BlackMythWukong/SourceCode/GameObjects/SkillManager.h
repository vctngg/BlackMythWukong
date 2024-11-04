#pragma once
#include "Skill.h"


class SkillManager 
{
public:
	void AddSkill(Skill* skill);
	void Update(float deltaTime);
	void LockSkill(SKILL skill);
	void UnlockSkill(SKILL skill);
	bool IsUnlocked(SKILL skill);
private:
	std::list<Skill*> m_listSkill;
	
};