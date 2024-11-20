#include "Monster.h"

Monster::~Monster()
{
}
void Monster::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(42, 36));
	m_HitBox->Init(sf::Vector2f(100, 0));
	setStartPoint(sf::Vector2f(screenWidth / 2, groundY));
	m_HitBox->setPosition(screenWidth - 0.4 * screenWidth * (rand() % (3)), -10 + groundY - this->getHitBox()->getSize().y / 2);
	m_idleAni = new Animation(*DATA->getTexture("Characters/Minotaur/Idle/idle"), sf::Vector2i(5, 1), 0.1f);
	m_runAni = new Animation(*DATA->getTexture("Characters/Minotaur/Run/run"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Characters/Minotaur/Death/death"), sf::Vector2i(6, 1), 0.1f);
	m_chopAni = new Animation(*DATA->getTexture("Characters/Minotaur/Chop/chop"), sf::Vector2i(9, 1), 0.1f);
	m_strikeAni = new Animation(*DATA->getTexture("Characters/Minotaur/Strike/strike"), sf::Vector2i(5, 1), 0.2f);
	m_swingAni = new Animation(*DATA->getTexture("Characters/Minotaur/Swing/swing"), sf::Vector2i(9, 1), 0.1f);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(MONSTER);
	m_stop = false;

	m_skillChop = new Skill();
	m_skillStrike = new Skill();
	m_skillSwing = new Skill();
	m_skillChop->SetType(MONSTER_CHOP);
	m_skillStrike->SetType(MONSTER_STRIKE);
	m_skillSwing->SetType(MONSTER_SWING);
	m_skillChop->UnlockSkill();
	m_skillStrike->UnlockSkill();
	m_skillSwing->UnlockSkill();
	SM->AddSkill(m_skillChop);
	SM->AddSkill(m_skillStrike);
	SM->AddSkill(m_skillSwing);

	m_weapon = new MonsterWeapon();
	m_attackTimer = 0;
}
void Monster::Update(float deltaTime, sf::Vector2f offset, HitBox* player_hitbox)
{
	if ( m_stop == true ) return;
	m_currentTime += deltaTime;
	if ( m_HitBox->isAlive() ) {
		CalculateDistanceFromPlayer(player_hitbox);
		GetPlayerPosition(player_hitbox);
		GetFacing();
		if ( !m_isAttacking )
		{
			if ( m_distanceFromPlayer < 32 ) {
				if ( SM->IsUnlocked(MONSTER_SWING) && !SM->IsOnCD(MONSTER_SWING)) {
					Swing();
					printf("swing\n");
				}
				else if ( SM->IsUnlocked(MONSTER_CHOP) && !SM->IsOnCD(MONSTER_CHOP) ) {
					Chop();
					printf("chop\n");
				}
				else if ( SM->IsUnlocked(MONSTER_STRIKE) && !SM->IsOnCD(MONSTER_STRIKE) ) {
					Strike();
					printf("strike\n");
				}
				else {
					if ( m_currentAni != m_idleAni )
					{
						m_currentAni = m_idleAni;
						printf("idle\n");
					}
				}
			}
			else
			{
				if ( m_currentAni != m_runAni ) {
					m_currentAni = m_runAni;
				}
				
				if ( m_left ) {
					m_HitBox->move(-m_HitBox->getVelocity() * deltaTime);
				}
				else
				{
					m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
				}
			}
		}
		else
		{
			m_attackTimer += deltaTime;
			if ( m_attackTimer > 0.5 ) {
				if ( m_currentAni->getCurrentFrame().x == m_currentAni->getFrameNum().x -1)
				{
					m_isAttacking = false;
					
				}
			}
		}

		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition().x + offset.x, getHitBox()->getPosition().y + offset.y);
		m_currentAni->flip(m_left);
		
	}
	else
	{
		/*if ( m_soundDeadisPlay == false ) {
			DATA->playSound("monster-hurt");
			m_soundDeadisPlay = true;
		}*/
		m_currentAni = m_deathAni;
		if ( m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1 ) {
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition().x + offset.x, getHitBox()->getPosition().y + offset.y);
			m_currentAni->flip(m_left);
		}
		else m_stop = true;

	}
}

void Monster::Chop()
{ 
	if (!m_isAttacking )
	{
		m_isAttacking = true;
		m_currentAni = m_chopAni;
		sf::Vector2f pos = getHitBox()->getPosition();
		GetWeapon()->GetDirection(m_left);
		GetWeapon()->NA(pos);
		SM->SetOnCD(MONSTER_CHOP);
	}

}

void Monster::Strike()
{
	if ( !m_isAttacking )
	{
		m_isAttacking = true;
		m_currentAni = m_strikeAni;
		sf::Vector2f pos = getHitBox()->getPosition();
		GetWeapon()->GetDirection(m_left);
		GetWeapon()->NA(pos);
		SM->SetOnCD(MONSTER_STRIKE);
	}
}

void Monster::Swing()
{
	if ( !m_isAttacking )
	{
		m_isAttacking = true;
		m_currentAni = m_swingAni;
		sf::Vector2f pos = getHitBox()->getPosition();
		GetWeapon()->GetDirection(m_left);
		GetWeapon()->Fire(pos);
		SM->SetOnCD(MONSTER_SWING);
	}
}

MonsterWeapon* Monster::GetWeapon()
{
	return m_weapon;
}
