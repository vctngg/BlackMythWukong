#include "HPManager.h"

float HPManager::GetCurrentHP()
{
	return m_currentHP;
}

float HPManager::GetTotalHP()
{
	return m_totalHP;
}

void HPManager::SetCurrentHP(float hp)
{
	m_currentHP = hp;
}

void HPManager::SetTotalHP(float hp)
{
	m_totalHP = hp;
}

float HPManager::GetDamage()
{
	return m_damage;
}

void HPManager::SetDamage(float damage)
{
	m_damage = damage;
}

void HPManager::TakeDamage(float damage)
{
	m_currentHP -= damage;
}

void HPManager::Reset()
{
	m_currentHP = m_totalHP;
}
