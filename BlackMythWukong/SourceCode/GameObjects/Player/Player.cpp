#include "Player.h"
#include "PSRun.h"
#include "PSJump.h"
#include "PSFall.h"
#include "PSDeath.h"
#include"PSAttack1.h"
#include"PSAttack2.h"
#include"PSAttack3.h"
#include "PSIdle.h"

Player::Player()
{
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_jumpState = new PSJump(this);
	m_fallState = new PSFall(this);
	m_deathState = new PSDeath(this);
	m_attack1State = new PSAttack1(this);
	m_attack2State = new PSAttack2(this);
	m_attack3State = new PSAttack3(this);
	m_idleState = new PSIdle(this);

	m_currentState = m_idleState;

	m_PlayerWeapon = new PlayerWeapon();

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}
void Player::Init(CollisionManager& collisionmanager, SkillManager& skillmanager)
{
	m_runState->Init();
	m_jumpState->Init();
	m_fallState->Init();
	m_deathState->Init();
	m_attack1State->Init();
	m_attack2State->Init();
	m_attack3State->Init();
	m_idleState->Init();

	m_skill = new Skill();
	m_skill->SetType(PLAYER_ATTACK_1);
	m_skill->UnlockSkill();
	skillmanager.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(PLAYER_ATTACK_2);
	m_skill->UnlockSkill();
	skillmanager.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(PLAYER_ATTACK_3);
	m_skill->UnlockSkill();
	skillmanager.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(PLAYER_SKILL_SUMMON);
	m_skill->UnlockSkill();
	skillmanager.AddSkill(m_skill);
	//delete m_skill;

	m_HitBox = new HitBox(sf::Vector2i(15, 30));
	m_HitBox->setPosition(400, groundY-m_HitBox->getSize().y/2);
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->SetTag(PLAYER);
	m_HitBox->setAlive(true);

	collisionmanager.addObj(m_HitBox);
	m_PlayerWeapon->Init(collisionmanager);
	/*DATA->getSound("summon")->setVolume(15);
	DATA->getSound("attack")->setVolume(15);*/
}

void Player::Update(float deltaTime, SkillManager& SM)
{
	if ( this->getHitBox()->getPosition().x < screenWidth / 4 || this->getHitBox()->getPosition().x > screenWidth * 3 / 4 )
	{
		if ( this->getHitBox()->getPosition().x < screenWidth / 4 ) {
			m_offset.x = abs(screenWidth / 4 - this->getHitBox()->getPosition().x);
		}
		if ( this->getHitBox()->getPosition().x > screenWidth * 3 / 4 ) {
			m_offset.x = -abs(this->getHitBox()->getPosition().x - screenWidth * 3 / 4);
		}
	}
	performStateChange();
	m_PlayerWeapon->Update(deltaTime, m_offset);
	m_currentState->Update(deltaTime, SM);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	m_PlayerWeapon->Render(window);
	//window->draw(*m_HitBox);
}


HitBox* Player::getHitBox()
{
	return m_HitBox;
}

sf::Vector2f Player::getPosition() 
{
	return getHitBox()->getPosition();
}

PlayerWeapon* Player::getWeapon()
{
	return m_PlayerWeapon;
}

void Player::performStateChange()
{
	if ( m_nextState != IPState::SNULL ) {
		switch ( m_nextState )
		{
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::JUMP:
			m_currentState = m_jumpState;
			break;
		case IPState::FALL:
			m_currentState = m_fallState;
			break;
		case IPState::ATTACK1:
			m_currentState = m_attack1State;
			break;
		case IPState::ATTACK2:
			m_currentState = m_attack2State;
			break;
		case IPState::ATTACK3:
			m_currentState = m_attack3State;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			m_currentState = m_idleState;
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
} 

Player::~Player()

{
	if ( m_runState != nullptr ) {
		delete m_runState;
	}
	if ( m_jumpState != nullptr ) {
		delete m_jumpState;
	}
	if ( m_fallState != nullptr ) {
		delete m_fallState;
	}
	if ( m_PlayerWeapon != nullptr ) {
		delete m_PlayerWeapon;
	}
	if ( m_deathState != nullptr ) {
		delete m_deathState;
	}
	if ( m_attack1State != nullptr ) {
		delete m_attack1State;
	}
	if ( m_attack2State != nullptr ) {
		delete m_attack2State;
	}
	if ( m_attack3State != nullptr ) {
		delete m_attack3State;
	}
	if ( m_idleState != nullptr ) {
		delete m_idleState;
	}
	m_currentState = nullptr;
	
}

	

	





