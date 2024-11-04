#include "LevelManager.h"

void Level::Init()
{
	m_currentLevel = 0;
	m_exp = 0;
	m_expPerLevel = EXP_PER_LEVEL;
	m_expToLevelUp = EXP_PER_LEVEL;

	m_skill1 = new Skill;
	m_skill2 = new Skill;
	m_skill3 = new Skill;
	m_skill4 = new Skill;
	m_skill5 = new Skill;

	m_skill1->SetType(BOSS_NA);
	m_skill2->SetType(PLAYER_SKILL_SUMMON);
	m_skill3->SetType(PLAYER_ATTACK_1);
	m_skill4->SetType(PLAYER_ATTACK_2);
	m_skill5->SetType(PLAYER_ATTACK_3);

	m_SkillManager.AddSkill(m_skill1);
	m_SkillManager.AddSkill(m_skill2);
	m_SkillManager.AddSkill(m_skill3);
	m_SkillManager.AddSkill(m_skill4);
	m_SkillManager.AddSkill(m_skill5);

	m_SkillManager.UnlockSkill(PLAYER_ATTACK_1);
	m_SkillManager.UnlockSkill(PLAYER_ATTACK_3);
	m_SkillManager.UnlockSkill(BOSS_NA);
}

void Level::Update(float deltaTime)
{
	LevelUp();
	m_SkillManager.Update(deltaTime);

}

void Level::Reset()
{
}

void Level::LevelUp()
{
	m_expToLevelUp = EXP_PER_LEVEL * (1 - pow(EXP_MULTIPLIER, m_currentLevel+1)) / (1 - EXP_MULTIPLIER);
	while ( m_exp > m_expToLevelUp ) {
		m_currentLevel++;
		m_expToLevelUp = EXP_PER_LEVEL * (1 - pow(EXP_MULTIPLIER, m_currentLevel + 1)) / (1 - EXP_MULTIPLIER);
		ObtainSkill();
	}
	m_expPerLevel += m_currentLevel * EXP_MULTIPLIER * EXP_PER_LEVEL;
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}

void Level::GetExp(bool met_requirement)
{
	if ( met_requirement ) {
		m_exp += 150;
	}
}

void Level::ObtainSkill()
{
	if ( m_currentLevel == 1 ) {
		m_SkillManager.UnlockSkill(PLAYER_ATTACK_3);
	}
	if ( m_currentLevel == 3 ) {
		m_SkillManager.UnlockSkill(PLAYER_ATTACK_2);
	}
	if ( m_currentLevel == 5 ) {
		m_SkillManager.UnlockSkill(PLAYER_SKILL_SUMMON);
	}
}
SkillManager Level::AccessSkillManager() {
	return m_SkillManager;
}