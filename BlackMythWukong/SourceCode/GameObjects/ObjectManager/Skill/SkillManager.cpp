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

bool SkillManager::IsOnCD(SKILL skill)
{
	for ( auto s : m_listSkill ) {
		if ( s->GetType() == skill ) {
			return(s->IsOnCooldown());
		}
	}
}

void SkillManager::SetOnCD(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			a->SetOnCooldown(true);
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

float SkillManager::GetCD(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			return a->GetCD();
		}
	}
	return 0.0f;
}
float SkillManager::GetTime(SKILL skill)
{
	for ( auto a : m_listSkill ) {
		if ( a->GetType() == skill ) {
			return a->GetCurrentTime();
		}
	}
	return 0.0f;
}