#include "CollisionManager.h"


void CollisionManager::addObj(HitBox* hitBox)
{
    m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

float CollisionManager::GetDistance(HitBox* a, HitBox* b) {
    float distance = sqrt(pow(a->getPosition().x - b->getPosition().x, 2) + pow(a->getPosition().y - b->getPosition().y, 2));
    return distance;
}

void CollisionManager::Update(float deltaTime)
{
    m_currentTime += deltaTime;
    for ( auto a : m_listObj ) {
        if ( a->GetCurrentHP() == 0 ) a->setAlive(false);
        if ( a->isAlive() == false ) continue;
        for ( auto b : m_listObj ) {
            if ( b->GetCurrentHP() == 0 ) b->setAlive(false);
            if ( b->isAlive() == false ) continue;
            a->Update(deltaTime);
            b->Update(deltaTime);
            if ( a->getTag() == b->getTag() ) continue;
            if ( !checkCollision(a, b) ) continue;
            
            if ( !a->isVulnerable() ) continue;
            if ( !b->isVulnerable() ) continue;

            /*if ( a->getTag() == PLAYER && b->getTag() == CREEP ) {
                a->setAlive(false);
                b->setAlive(false);
            }*/

            if ( a->getTag() == PLAYER && b->getTag() == BOSS ) {
                a->TakeDamage(b->GetDamage());
                b->TakeDamage(a->GetDamage());
                a->setVulnerable(false);
                b->setVulnerable(false);
            }

            if ( a->getTag() == PLAYER && b->getTag() == BOSS_Bullet ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
            }
            if ( a->getTag() == BOSS && b->getTag() == PLAYER_Bullet ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
            }

            /*if ( a->getTag() == CREEP && b->getTag() == BOSS_Bullet ) {
                a->setAlive(false);
                b->setAlive(false);
            }
            if ( a->getTag() == CREEP && b->getTag() == BOSS ) {
                a->setAlive(false);
                b->setAlive(false);
            }*/
        }
    }
}