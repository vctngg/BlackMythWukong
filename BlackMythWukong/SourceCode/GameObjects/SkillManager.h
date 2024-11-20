#pragma once
#include "Skill.h"
#include "../GameManager/Singleton.h"
#define SM SkillManager::GetInstance()
class SkillManager :public CSingleton<SkillManager>
{
public:
	void AddSkill(Skill* skill);
	void Update(float deltaTime);
	bool IsOnCD(SKILL skill);
	void SetOnCD(SKILL skill);
	void LockSkill(SKILL skill);
	void UnlockSkill(SKILL skill);
	bool IsUnlocked(SKILL skill);
private:
	std::list<Skill*> m_listSkill;
	
};