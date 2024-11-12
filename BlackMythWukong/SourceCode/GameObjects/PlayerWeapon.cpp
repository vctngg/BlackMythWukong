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
}

void PlayerWeapon::Init(CollisionManager& collisionManager)
{

	for ( int i = 0; i < m_Num; i++ ) {
		PBullet* bullet = new PBullet();
		bullet->Init();	
		bullet->SetTag(PLAYER_Summon);
		bullet->getHitBox()->setAlive(false);
		m_ListBullet.push_back(bullet);
		collisionManager.addObj(bullet->getHitBox());

	}
}

void PlayerWeapon::Update(float deltaTime, sf::Vector2f offset)
{
	m_currentTime += deltaTime;
	for ( auto bullet : m_ListBullet ) {
		bullet->Update(deltaTime, offset);
	}
}

void PlayerWeapon::Render(sf::RenderWindow* window)
{
	for ( auto bullet : m_ListBullet ) {
		bullet->Render(window);
	}
}

void PlayerWeapon::GetDirection(bool going_left)
{
	for ( auto it : m_ListBullet ) {
		it->SetDirection(going_left);
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
	bullet->SetTag(PLAYER_Summon);
	bullet->getHitBox()->SetTag(PLAYER_Summon);
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}

void PlayerWeapon::Attack1(sf::Vector2f startPoint)
{
	PBullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListBullet )
	{
		bullet->SetTag(PLAYER_Attack1);
		bullet->getHitBox()->SetTag(PLAYER_Attack1);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
void PlayerWeapon::Attack2(sf::Vector2f startPoint)
{
	PBullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListBullet )
	{
		bullet->SetTag(PLAYER_Attack2);
		bullet->getHitBox()->SetTag(PLAYER_Attack2);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
void PlayerWeapon::Attack3(sf::Vector2f startPoint)
{
	PBullet* bullet = nullptr;
	for ( auto it : m_ListBullet ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			bullet = it;
			break;
		}
	}
	if ( bullet == nullptr ) return;
	for ( auto it : m_ListBullet )
	{
		bullet->SetTag(PLAYER_Attack3);
		bullet->getHitBox()->SetTag(PLAYER_Attack3);
	}
	bullet->getHitBox()->setAlive(true);
	bullet->setStartPoint(startPoint);
	bullet->Reset();
}
