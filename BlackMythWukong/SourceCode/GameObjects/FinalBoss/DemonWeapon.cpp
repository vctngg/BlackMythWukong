#include "DemonWeapon.h"

DemonWeapon::DemonWeapon()
{
	m_Num = 1;
	m_currentTime = 0.f;
}

DemonWeapon::~DemonWeapon()
{
	for ( auto it : m_ListNA ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListNA.clear();
	for ( auto it : m_ListFire ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListFire.clear();
	for ( auto it : m_ListSmash ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListSmash.clear();
	for ( auto it : m_ListSpell ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListSpell.clear();
}

void DemonWeapon::Init()
{
	for ( int i = 0; i < m_Num; i++ ) {
		
	}
}

void DemonWeapon::Update(float deltaTime, sf::Vector2f offset)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListSpell ) {
		bullet->Update(deltaTime, offset);
	}
	for ( auto na : m_ListNA ) {
		na->Update(deltaTime, offset);
	}
	for ( auto bullet : m_ListFire ) {
		bullet->Update(deltaTime, offset);
	}
	for ( auto bullet : m_ListSmash ) {
		bullet->Update(deltaTime, offset);
	}
}

void DemonWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListSpell ) {
		bullet->Render(window);
	}
	for ( auto na : m_ListNA ) {
		na->Render(window);
	}
	for ( auto bullet : m_ListFire ) {
		bullet->Render(window);
	}
	for ( auto bullet : m_ListSmash ) {
		bullet->Render(window);
	}
}

void DemonWeapon::GetDirection(bool going_left)
{
	for ( auto bullet : m_ListSpell ) {
		bullet->SetDirection(going_left);
	}
	for ( auto na : m_ListNA ) {
		na->SetDirection(going_left);
	}
	for ( auto bullet : m_ListFire ) {
		bullet->SetDirection(going_left);
	}
	for ( auto bullet : m_ListSmash ) {
		bullet->SetDirection(going_left);
	}
}

void DemonWeapon::CastSpell(sf::Vector2f startPoint)
{
	Spell* bullet = nullptr;
	for ( auto it : m_ListSpell ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(DEMON_Spell);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void DemonWeapon::NA(sf::Vector2f startPoint)
{
	DNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(DEMON_NA);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void DemonWeapon::CastSmash(sf::Vector2f startPoint)
{
	Smash* bullet = nullptr;
	for ( auto it : m_ListSmash ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(DEMON_Smash);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void DemonWeapon::CastFire(sf::Vector2f startPoint)
{
	Fire* bullet = nullptr;
	for ( auto it : m_ListFire ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(DEMON_Fire);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
