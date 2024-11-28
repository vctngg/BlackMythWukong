#include "FrogWeapon.h"

FrogWeapon::FrogWeapon()
{
	m_Num = 1;
	m_currentTime = 0.f;
}

FrogWeapon::~FrogWeapon()
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

void FrogWeapon::Init()
{

	for ( int i = 0; i < m_Num; i++ ) {
		printf("+1\n");
		FBullet* bullet = new FBullet();
		bullet->Init();
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		CM->addObj(bullet->getHitBox());

		FNA* na = new FNA();
		na->Init();
		na->getHitBox()->setAlive(false);
		m_ListNA.push_back(na);
		CM->addObj(na->getHitBox());

	}
}

void FrogWeapon::Update(float deltaTime, sf::Vector2f offset)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListBullet ) {
		bullet->Update(deltaTime, offset);
	}
	for ( auto na : m_ListNA ) {
		na->Update(deltaTime, offset);
	}
}

void FrogWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListBullet ) {
		bullet->Render(window);
	}
	for ( auto na : m_ListNA ) {
		na->Render(window);
	}
}

void FrogWeapon::GetDirection(bool going_left)
{
	for ( auto it : m_ListBullet ) {
		it->SetDirection(going_left);
	}
	for ( auto it : m_ListNA ) {
		it->SetDirection(going_left);
	}
}

void FrogWeapon::Spit(sf::Vector2f startPoint)
{
	FBullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(FROG_Spit);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
void FrogWeapon::Lick(sf::Vector2f startPoint)
{
	FNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListNA )
	{
		bullet->getHitBox()->SetTag(FROG_Attack);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}