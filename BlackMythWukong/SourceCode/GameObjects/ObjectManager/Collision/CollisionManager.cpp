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

void CollisionManager::Update(float deltaTime, Level& LM)
{
    m_currentTime += deltaTime;
    for ( auto a : m_listObj ) {
        a->Update(deltaTime);
        
    }
    for ( auto a : m_listObj ) {
        if ( a->GetCurrentHP() <= 0 && a->GetCurrentHP() != -1 ) a->setAlive(false);
        if ( a->isAlive() == false ) continue;
        for ( auto b : m_listObj ) {
            if ( b->GetCurrentHP() <= 0 && b->GetCurrentHP() != -1 ) b->setAlive(false);
            if ( b->isAlive() == false ) continue;
            if ( a->getTag() == b->getTag() ) continue;
            if ( !checkCollision(a, b) ) continue;
            
            if ( !a->isVulnerable() ) continue;
            if ( !b->isVulnerable() ) continue;
            //collision with player hitbox
            if ( a->getTag() == PLAYER && b->getTag() == BOSS ) {
                a->TakeDamage(b->GetDamage());
                b->TakeDamage(a->GetDamage());
                a->setVulnerable(false);
                b->setVulnerable(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == BOSS_Bullet ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == MONSTER_Attack ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == MONSTER_Swing ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == FROG_Attack ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == FROG_Spit ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == DEMON_Fire ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == DEMON_NA ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == DEMON_Smash ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            if ( a->getTag() == PLAYER && b->getTag() == DEMON_Spell ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                continue;
            }
            //collision with player skills
            if ( a->getTag() == BOSS && b->getTag() == PLAYER_Summon ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == BOSS && b->getTag() == PLAYER_Attack1 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                ///*if ( a->GetCurrentHP() <= 0 ) {
                //    LM.GetExp(true);
                //}*/
                continue;
            }
            if ( a->getTag() == BOSS && b->getTag() == PLAYER_Attack2 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                ///*if ( a->GetCurrentHP() <= 0 ) {
                //    LM.GetExp(true);
                //}*/
                continue;
            }
            if ( a->getTag() == BOSS && b->getTag() == PLAYER_Attack3 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == FROG && b->getTag() == PLAYER_Summon ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == FROG && b->getTag() == PLAYER_Attack1 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == FROG && b->getTag() == PLAYER_Attack2 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == FROG && b->getTag() == PLAYER_Attack3 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == MONSTER && b->getTag() == PLAYER_Summon ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == MONSTER && b->getTag() == PLAYER_Attack1 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == MONSTER && b->getTag() == PLAYER_Attack2 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }
                continue;
            }
            if ( a->getTag() == MONSTER && b->getTag() == PLAYER_Attack3 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == DEMON && b->getTag() == PLAYER_Summon ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                //a->setAlive(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == DEMON && b->getTag() == PLAYER_Attack1 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == DEMON && b->getTag() == PLAYER_Attack2 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            if ( a->getTag() == DEMON && b->getTag() == PLAYER_Attack3 ) {
                a->TakeDamage(b->GetDamage());
                a->setVulnerable(false);
                b->setAlive(false);
                /*if ( a->GetCurrentHP() <= 0 ) {
                    LM.GetExp(true);
                }*/
                continue;
            }
            
        }
    }
}