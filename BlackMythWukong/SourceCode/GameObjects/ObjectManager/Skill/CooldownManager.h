#pragma once

class CooldownManager
{
public:
	void Init();
	void Update(float deltaTime);
	void SetOnCooldown(bool is_on_cd);
	bool IsOnCooldown();
	float GetCurrentTime();
private:
	float m_currentTime;
	bool m_onCooldown;
};