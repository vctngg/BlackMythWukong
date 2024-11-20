#include "LevelManager.h"

void Level::Init()
{
	m_currentLevel = 0;
	m_exp = 0;
	m_expPerLevel = EXP_PER_LEVEL;
	m_expToLevelUp = EXP_PER_LEVEL;
}

void Level::Update(float deltaTime)
{
	LevelUp();
	SM->Update(deltaTime);

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
		SM->UnlockSkill(PLAYER_ATTACK_3);
	}
	if ( m_currentLevel == 3 ) {
		SM->UnlockSkill(PLAYER_ATTACK_2);
	}
	if ( m_currentLevel == 5 ) {
		SM->UnlockSkill(PLAYER_SKILL_SUMMON);
	}
}