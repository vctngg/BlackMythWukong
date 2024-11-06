#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_GuardNum = 50;
	m_TimeSpwanCreep = 2.f;
	m_currentTime = 0.f;
}

CreepManager::~CreepManager()
{
	for ( auto it : m_listGuard ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_listGuard.clear();
	for ( auto it : m_Dog ) {
		if ( it != nullptr ) {
			delete it;
		}
	}

}

void CreepManager::Init(CollisionManager& collisionManager)
{

	for ( int i = 0; i < m_GuardNum; i++ ) {
		Guard* creepR = new Guard();
		creepR->Init();
		creepR->getHitBox()->setAlive(false);
		m_listGuard.push_back(creepR);
		collisionManager.addObj(creepR->getHitBox());

	}
		Dog* dog = new Dog();
		dog->Init();
		dog->getHitBox()->setAlive(false);
		m_Dog.push_back(dog);
		collisionManager.addObj(dog->getHitBox());
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	for ( int i = 0; i < m_GuardNum; i++ ) {
		SpawnGuards();
	}
	SpawnDog();
	for ( auto creep : m_listGuard ) {
		creep->Update(deltaTime);
		//printf("(%f,%f)\n",creep->getHitBox()->getPosition().x, creep->getHitBox()->getPosition().y);
	}
	for ( auto creep : m_Dog ) {
		creep->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for ( auto creep : m_listGuard ) {
		creep->Render(window);
	}
	for ( auto creep : m_Dog ) {
		creep->Render(window);
	}
}

void CreepManager::SpawnGuards()
{
	Creep* creep = nullptr;
	for ( auto it : m_listGuard ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			creep = it;
			break;
		}
	}
	if ( creep == nullptr ) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth / 3 + 5 * (rand() % (101)), -50 + groundY - creep->getHitBox()->getSize().y / 2));
	creep->Reset();
}

void CreepManager::SpawnDog()
{
	Dog* dog = nullptr;
	for ( auto it : m_Dog ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			dog = it;
			break;
		}
	}
	if ( dog == nullptr ) return;
	dog->getHitBox()->setAlive(true);
	dog->setStartPoint(sf::Vector2f(screenWidth *2 / 3 + 50,-10+ groundY - dog->getHitBox()->getSize().y / 2));
	dog->Reset();
}

//void CreepManager::SpawnBat()
//{
//	Creep* creep = nullptr;
//	for ( auto it : m_ListCreepBat ) {
//		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
//			creep = it;
//			break;
//		}
//	}
//	if ( creep == nullptr ) return;
//	creep->getHitBox()->setAlive(true);
//	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY - (rand() % (300 - 100 + 1) + 100)));
//	creep->Reset();
//}