#pragma once
#include "../GameManager/ResourceManager.h"
#include "HPManager.h"
enum TAG 
{
	NON_INTERACTIVE,
	PLAYER,
	CREEP,
	BOSS,
	BOSS_Bullet,
	PLAYER_Summon,
	PLAYER_Attack1,
	PLAYER_Attack2,
	PLAYER_Attack3,
	MONSTER,
	MONSTER_Attack,
	MONSTER_Swing,
};

class HitBox :public sf::RectangleShape, public HPManager {
public:
	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(sf::Vector2f velocity);
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
	void Update(float deltaTime);
	TAG getTag() {
		return m_Tag;
	};
	void SetTag(TAG tag) { 
		setVulnerable(true);
		m_Tag = tag;
		SetStats();
	}
	void SetStats();

	bool isAlive() {
		return m_isAlive;
	}
	void setAlive(bool alive) {
		m_isAlive = alive;
	}
	bool isVulnerable() {
		return m_isVulnerable;
	}
	void setVulnerable(bool vulnerable) {
		m_isVulnerable = vulnerable;
	}
private:
	sf::Vector2f m_Velocity;
	bool m_isAlive;
	bool m_isVulnerable;
	float m_vulnerability_timer = 0;
	TAG m_Tag;
};