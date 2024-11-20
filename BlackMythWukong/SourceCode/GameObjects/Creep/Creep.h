#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../ObjectManager/Collision/HitBox.h"
#include "../ObjectManager/Skill/SkillManager.h"
#include "../ObjectManager/Collision/CollisionManager.h"

class Creep {
public:
	Creep();
	~Creep();
	virtual void Init();
	virtual void Update(float deltaTime, sf::Vector2f offset);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() {
		return m_HitBox;
	}
	void CalculateDistanceFromPlayer(HitBox* player_hitbox);
	void GetPlayerPosition(HitBox* player_hitbox);
	void GetFacing();

	void setStartPoint(sf::Vector2f point) {
		m_startPoint = point;
	}

	void Reset();
	bool isStop() {
		return m_stop;
	}
protected:
	float m_currentTime;
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;
	Animation* m_idleAni;

	float m_distanceFromPlayer;
	sf::Vector2f m_playerPosition;

	bool m_left;
	bool m_isAttacking;
	bool m_stop;
	bool m_soundDeadisPlay;
};
