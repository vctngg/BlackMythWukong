#pragma once
class HPManager
{
public:
	float GetCurrentHP();
	float GetTotalHP();
	void SetCurrentHP(float hp);
	void SetTotalHP(float hp);
	
	float GetDamage();
	void SetDamage(float damage);

	void TakeDamage(float damage);

	void Reset();
private:
	float m_totalHP;
	float m_currentHP;
	float m_damage;
};