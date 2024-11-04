#include "SkillManager.h"

void SkillManager::AddSkill(Skill* skill)
{
	m_listSkill.push_back(skill);
	skill->Init();
}

void SkillManager::Update(float deltaTime)
{
	for ( auto a : m_listSkill ) {
		a->Update(deltaTime);
		if ( a->GetCurrentTime() > a->GetCD() ) {
			a->SetOnCooldown(false);
		}
	}
}


void SkillManager::LockSkill(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			a->LockSkill();
		}
	}
}

void SkillManager::UnlockSkill(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			a->UnlockSkill();
		}
	}
}
bool SkillManager::IsUnlocked(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			return(a->IsUnlocked());
		}
	}
	return false;
}
