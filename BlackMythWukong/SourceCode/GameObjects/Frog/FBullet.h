#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../ObjectManager/Collision/HitBox.h"

class FBullet {
public:
	FBullet();
	~FBullet();
	void Init();
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);

	HitBox* getHitBox() {
		return m_HitBox;
	}
	void setStartPoint(sf::Vector2f point) {
		m_startPoint = point;
	}
	void SetDirection(bool going_left) {
		m_left = going_left;
	}
	bool GetDirection() {
		return m_left;
	}
	void Reset();
	bool isStop() {
		return m_stop;
	}
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;

	bool m_stop;
	bool m_soundIsPlaying;

	bool m_left;
};
