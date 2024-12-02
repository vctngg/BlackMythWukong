#pragma once
#include "../ObjectManager/Collision/CollisionManager.h"
#include "../../GameManager/ResourceManager.h"
#include "Spell.h"
#include "DNA.h"
#include "Smash.h"
#include "Fire.h"

class DemonWeapon {
public:
	DemonWeapon();
	~DemonWeapon();
	void Init();
	void Update(float deltaTime, sf::Vector2f offset);
	void Render(sf::RenderWindow* window);
	void GetDirection(bool going_left);
	void CastSpell(sf::Vector2f startPoint);
	void NA(sf::Vector2f startPoint);
	void CastSmash(sf::Vector2f startPoint);
	void CastFire(sf::Vector2f startPoint);
private:
	std::list<Spell*> m_ListSpell;
	std::list<DNA*> m_ListNA;
	std::list<Smash*> m_ListSmash;
	std::list<Fire*> m_ListFire;
	int m_Num;
	float m_currentTime;
};