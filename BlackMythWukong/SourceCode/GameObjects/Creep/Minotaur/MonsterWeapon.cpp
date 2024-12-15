#include "MonsterWeapon.h"

MonsterWeapon::MonsterWeapon()
{
	m_Num = 1;
	m_currentTime = 0.f;
}

MonsterWeapon::~MonsterWeapon()
{
	for ( auto it : m_ListBullet ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListBullet.clear();
	for ( auto it : m_ListNA ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListNA.clear();
}

void MonsterWeapon::Init(CollisionManager& CM)
{

	for ( int i = 0; i < m_Num; i++ ) {
		MBullet* bullet = new MBullet();
		bullet->Init();
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		CM.addObj(bullet->getHitBox());
	}
	for ( int i = 0; i < m_Num; i++ ) {
		MNA* bullet = new MNA();
		bullet->Init();
		bullet->getHitBox()->setAlive(false);
		m_ListNA.push_back(bullet);
		CM.addObj(bullet->getHitBox());
	}
}

void MonsterWeapon::Update(float deltaTime, sf::Vector2f offset)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListBullet ) {
		bullet->Update(deltaTime, offset);
	}
	for ( auto bullet : m_ListNA ) {
		bullet->Update(deltaTime, offset);
	}
}

void MonsterWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListBullet ) {
		bullet->Render(window);
	}
	for ( auto bullet : m_ListNA ) {
		bullet->Render(window);
	}
}

void MonsterWeapon::GetDirection(bool going_left)
{
	for ( auto it : m_ListBullet ) {
		it->SetDirection(going_left);
	}
	for ( auto it : m_ListNA ) {
		it->SetDirection(going_left);
	}
}

void MonsterWeapon::Fire(sf::Vector2f startPoint)
{
	MNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(MONSTER_Swing);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void MonsterWeapon::NA(sf::Vector2f startPoint)
{
	MNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(MONSTER_Attack);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
