#pragma once
#include "../../../GameManager/ResourceManager.h"
#include "HPManager.h"
enum TAG 
{
	NON_INTERACTIVE,

	PLAYER,
	PLAYER_Summon,
	PLAYER_Attack1,
	PLAYER_Attack2,
	PLAYER_Attack3,

	CREEP,

	BOSS,
	BOSS_Bullet,
	
	MONSTER,
	MONSTER_Attack,
	MONSTER_Swing,

	FROG,
	FROG_Attack,
	FROG_Spit,

	DEMON,
	DEMON_NA,
	DEMON_Spell,
	DEMON_Smash,
	DEMON_Fire,
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