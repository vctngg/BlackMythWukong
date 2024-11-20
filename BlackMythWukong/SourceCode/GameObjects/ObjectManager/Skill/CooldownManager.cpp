#include "CooldownManager.h"

void CooldownManager::Init()
{
	m_currentTime = 0;
	SetOnCooldown(false);
}

void CooldownManager::Update(float deltaTime)
{
	if (IsOnCooldown() )
	{
		m_currentTime += deltaTime;
	}
}

void CooldownManager::SetOnCooldown(bool is_on_cd)
{
	m_onCooldown = is_on_cd;
	m_currentTime = 0;
}

bool CooldownManager::IsOnCooldown()
{
	return m_onCooldown;
}

float CooldownManager::GetCurrentTime()
{
	return m_currentTime;
}
