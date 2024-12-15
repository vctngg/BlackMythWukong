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

void DemonWeapon::Init(CollisionManager& CM)
{
	for ( int i = 0; i < m_Num; i++ ) {
		DNA* na = new DNA();
		na->Init();
		na->getHitBox()->setAlive(false);
		m_ListNA.push_back(na);
		CM.addObj(na->getHitBox());
		Smash* sm = new Smash();
		sm->Init();
		sm->getHitBox()->setAlive(false);
		m_ListSmash.push_back(sm);
		CM.addObj(sm->getHitBox());
		Fire* f = new Fire();
		f->Init();
		f->getHitBox()->setAlive(false);
		m_ListFire.push_back(f);
		CM.addObj(f->getHitBox());
	}
	for ( int i = 0; i < (m_Num + 4); i++ ) {
		Spell* s = new Spell();
		s->Init();
		s->getHitBox()->setAlive(false);
		m_ListSpell.push_back(s);
		CM.addObj(s->getHitBox());
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
		else if ( it->getHitBox2()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(DEMON_Smash);
	bullet->getHitBox()->setAlive(true);
	bullet->getHitBox2()->SetTag(DEMON_Smash);
	bullet->getHitBox2()->setAlive(true);
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
