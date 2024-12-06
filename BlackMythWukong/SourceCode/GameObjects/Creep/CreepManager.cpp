#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_GuardNum = 50;
	m_MonsterNum = 4;

	m_TimeSpawnCreep = 2.f;
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
	m_Dog.clear();
	for ( auto it : m_listMonster ) {
		if ( it != nullptr ) {
			delete it;
		}
	}
	m_listMonster.clear();

}

void CreepManager::Init(int stage, CollisionManager& CM, SkillManager& SM)
{
	m_stageNumber = stage;
	switch ( m_stageNumber )
	{
	case 1: {
		for ( int i = 0; i < m_GuardNum; i++ ) {
			Guard* creepR = new Guard();
			creepR->Init();
			creepR->getHitBox()->setAlive(false);
			m_listGuard.push_back(creepR);
			CM.addObj(creepR->getHitBox());
		}

		Dog* dog = new Dog();
		dog->Init();
		dog->getHitBox()->setAlive(false);
		m_Dog.push_back(dog);
		CM.addObj(dog->getHitBox());

		break;
	}
	case 2: {
		for ( int i = 0; i < m_MonsterNum; i++ ) {
			Monster* m = new Monster();
			m->Init(SM);
			m->getHitBox()->setAlive(true);
			m_listMonster.push_back(m);
			CM.addObj(m->getHitBox());
		}
		break;
	}
	}
}

void CreepManager::Update(float deltaTime,sf::Vector2f offset, HitBox* player_hitbox,CollisionManager& CM, SkillManager& SM)
{
	m_currentTime += deltaTime;
	switch ( m_stageNumber )
	{
	case 1: {
		for ( int i = 0; i < m_GuardNum; i++ ) {
			SpawnGuards();
		}
		SpawnDog();
		for ( auto creep : m_listGuard ) {
			creep->Update(deltaTime, offset);
		}
		for ( auto creep : m_Dog ) {
			creep->Update(deltaTime, offset);
		}
		break;
	}
	case 2: {
		if ( m_currentTime >= m_TimeSpawnCreep ) {
			SpawnMonster();
			m_currentTime -= m_TimeSpawnCreep;
		}
		for ( auto creep : m_listMonster ) {
			creep->Update(deltaTime, offset, player_hitbox,SM,CM);
		}
		break;
	}
	}
	
}

void CreepManager::Render(sf::RenderWindow* window)
{
	switch ( m_stageNumber )
	{
	case 1: {
		for ( auto creep : m_listGuard ) {
			creep->Render(window);
		}
		for ( auto creep : m_Dog ) {
			creep->Render(window);
		}
		break;
	}
	case 2: {
		for ( auto creep : m_listMonster ) {
			creep->Render(window);
		}
		break;
	}
	default: break;
	}
	

}

std::list<Dog*> CreepManager::GetDog()
{
	return m_Dog;
}

void CreepManager::SpawnGuards()
{
	Guard* creep = nullptr;
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

void CreepManager::SpawnMonster()
{
	Monster* creep = nullptr;
	for ( auto it : m_listMonster ) {
		if ( it->getHitBox()->isAlive() == false && it->isStop() == true ) {
			creep = it;
			break;
		}
	}
	if ( creep == nullptr ) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth - 0.4 * screenWidth * (rand() % (3)), -50 + groundY - creep->getHitBox()->getSize().y / 2));
	creep->Reset();
}
