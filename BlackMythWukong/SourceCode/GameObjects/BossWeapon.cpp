#include "BossWeapon.h"

BossWeapon::BossWeapon()
{
	m_Num = 1;
	m_currentTime = 0.f;
}

BossWeapon::~BossWeapon()
{
	for ( auto it : m_ListBullet ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_ListBullet.clear();
}

void BossWeapon::Init(CollisionManager& collisionManager)
{

	for ( int i = 0; i < m_Num; i++ ) {
		Bullet* bullet = new Bullet();
		bullet->Init();
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		collisionManager.addObj(bullet->getHitBox());

	}
}

void BossWeapon::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListBullet ) {
		bullet->Update(deltaTime);
	}
}

void BossWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListBullet ) {
		bullet->Render(window);
	}
}

void BossWeapon::GetDirection(bool going_left)
{
	for ( auto it : m_ListBullet ) {
		it->SetDirection(going_left);
	}
}

void BossWeapon::Fire(sf::Vector2f startPoint)
{
	Bullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}