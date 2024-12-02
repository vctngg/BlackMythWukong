#include "PlayerWeapon.h"

PlayerWeapon::PlayerWeapon()
{
	m_Num = 1;
	m_currentTime = 0.f;
}

PlayerWeapon::~PlayerWeapon()
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

void PlayerWeapon::Init()
{

	for ( int i = 0; i < m_Num; i++ ) {
		PBullet* bullet = new PBullet();
		bullet->Init();	
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		CM->addObj(bullet->getHitBox());

		PNA* na = new PNA();
		na->Init();
		na->getHitBox()->setAlive(false);
		m_ListNA.push_back(na);
		CM->addObj(na->getHitBox());

	}
}

void PlayerWeapon::Update(float deltaTime, sf::Vector2f offset)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListBullet ) {
		if (bullet != nullptr )
		{
			bullet->Update(deltaTime, offset);
		}
	}
	for ( auto na : m_ListNA ) {
		if (na != nullptr )
		{
			try
			{
				na->Update(deltaTime, offset);
			}
			catch ( const char* e ) {

			}
		}
	}
}

void PlayerWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListBullet ) {
		if ( bullet != nullptr )
		{
			bullet->Render(window);
		}
	}
	for ( auto na : m_ListNA ) {
		if ( na != nullptr )
		{
			na->Render(window);
		}
	}
}

void PlayerWeapon::GetDirection(bool going_left)
{
	for ( auto it : m_ListBullet ) {
		if ( it != nullptr )
		{
			it->SetDirection(going_left);
		}
	}
	for ( auto it : m_ListNA ) {
		if ( it != nullptr )
		{
			it->SetDirection(going_left);
		}
	}
}

void PlayerWeapon::Summon(sf::Vector2f startPoint)
{
	PBullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		} 
	}
	if ( bullet == nullptr ) return;
	bullet->getHitBox()->SetTag(PLAYER_Summon);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void PlayerWeapon::Attack1(sf::Vector2f startPoint)
{
	PNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListNA )
	{
		bullet->getHitBox()->SetTag(PLAYER_Attack1);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
void PlayerWeapon::Attack2(sf::Vector2f startPoint)
{
	PNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListNA )
	{
		bullet->getHitBox()->SetTag(PLAYER_Attack2);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
void PlayerWeapon::Attack3(sf::Vector2f startPoint)
{
	PNA* bullet = nullptr;
	for ( auto it : m_ListNA ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListNA )
	{
		bullet->getHitBox()->SetTag(PLAYER_Attack3);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
