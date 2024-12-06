#include "Demon.h"
#include "DSRun.h"
#include "DSRunD.h"
#include "DSIdle.h"
#include "DSIdleD.h"
#include"DSHurt.h"
#include"DSHurtD.h"
#include"DSTransform.h"
#include "DSCleave.h"
#include "DSFireBreath.h"
#include "DSCastSpell.h"
#include "DSSmash.h"
#include "DSDeath.h"

Demon::Demon()
{
	
	m_runState = new DSRun(this);
	m_runDState = new DSRunD(this);
	m_idleState = new DSIdle(this);
	m_idleDState=  new DSIdleD(this);
	m_transformState=  new DSTransform(this);
	m_hurtState = new DSHurt(this);
	m_hurtDState = new DSHurtD(this);
	m_cleaveState = new DSCleave(this);
	m_smashState = new DSSmash(this);
	m_castspellState = new DSCastSpell(this);
	m_firebreathState = new DSFireBreath(this);
	m_deathState = new DSDeath(this);

	m_currentState = m_transformState;

	m_DemonWeapon = new DemonWeapon();

}

void Demon::changeNextState(IDState::STATE nextState)
{
	m_nextState = nextState;
}
void Demon::Init(CollisionManager& CM, SkillManager& SM)
{
	m_runState->Init();
	m_runDState->Init();
	m_idleState->Init();
	m_idleDState->Init();
	m_transformState->Init();
	m_hurtState->Init();
	m_hurtDState->Init();
	m_cleaveState->Init();
	m_smashState->Init();
	m_castspellState->Init();
	m_firebreathState->Init();
	m_deathState->Init();

	m_skill = new Skill();
	m_skill->SetType(DEMON_SKILL_NA);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(DEMON_SKILL_FIRE);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(DEMON_SKILL_SMASH);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(DEMON_SKILL_SPELL);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;

	m_HitBox = new HitBox(sf::Vector2i(64, 64));
	m_HitBox->setPosition(400, groundY - m_HitBox->getSize().y / 2);
	m_HitBox->Init(sf::Vector2f(100, 500));
	m_HitBox->SetTag(DEMON);
	m_HitBox->setAlive(true);

	CM.addObj(m_HitBox);
	m_DemonWeapon->Init(CM);
}

void Demon::Update(float deltaTime, sf::Vector2f offset, SkillManager& SM)
{
	performStateChange();
	m_playerOffset = offset;
	m_DemonWeapon->Update(deltaTime, m_playerOffset);
	m_currentState->Update(deltaTime,SM);
}

void Demon::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	m_DemonWeapon->Render(window);
	window->draw(*m_HitBox);
}


HitBox* Demon::getHitBox()
{
	return m_HitBox;
}

sf::Vector2f Demon::getPosition()
{
	return getHitBox()->getPosition();
}

DemonWeapon* Demon::getWeapon()
{
	return m_DemonWeapon;
}

void Demon::FacingCheck()
{
}

void Demon::GetDistanceFromPlayer(HitBox* player_hitbox, CollisionManager& CM)
{
	m_distanceFromPlayer = CM.GetDistance(m_HitBox, player_hitbox);
}

float Demon::ReturnDistanceFromPlayer()
{
	return m_distanceFromPlayer;
}

void Demon::GetPlayerPosition(HitBox* player_hitbox)
{
	m_playerPosition = player_hitbox->getPosition();
}

sf::Vector2f Demon::ReturnPlayerPosition()
{
	return m_playerPosition;
}

void Demon::performStateChange()
{
	if ( m_nextState != IDState::SNULL ) {
		switch ( m_nextState )
		{
		case IDState::IDLE:
			m_currentState = m_idleState;
			break;
		case IDState::RUN:
			m_currentState = m_runState;
			break;
		case IDState::HURT:
			m_currentState = m_hurtState;
			break;
		case IDState::IDLE_DEMON:
			m_currentState = m_idleDState;
			break;
		case IDState::RUN_DEMON:
			m_currentState = m_runDState;
			break;
		case IDState::HURT_DEMON:
			m_currentState = m_hurtDState;
			break;
		case IDState::TRANSFORM:
			m_currentState = m_transformState;
			break;
		case IDState::CLEAVE:
			m_currentState = m_cleaveState;
			break;
		case IDState::SMASH:
			m_currentState = m_smashState;
			break;
		case IDState::FIRE_BREATH:
			m_currentState = m_firebreathState;
			break;
		case IDState::CAST_SPELL:
			m_currentState = m_castspellState;
			break;
		case IDState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			m_currentState = m_idleState;
			break;
		}
		m_nextState = IDState::SNULL;
		m_currentState->Reset();
	}
}

Demon::~Demon()

{
	if ( m_runState != nullptr ) {
		delete m_runState;
	}
	if ( m_runDState != nullptr ) {
		delete m_runDState;
	}
	if ( m_hurtState != nullptr ) {
		delete m_hurtState;
	}
	if ( m_DemonWeapon != nullptr ) {
		delete m_DemonWeapon;
	}
	if ( m_deathState != nullptr ) {
		delete m_deathState;
	}
	if ( m_hurtDState != nullptr ) {
		delete m_hurtDState;
	}
	if ( m_transformState != nullptr ) {
		delete m_transformState;
	}
	if ( m_idleDState != nullptr ) {
		delete m_idleDState;
	}
	if ( m_idleState != nullptr ) {
		delete m_idleState;
	}
	if ( m_cleaveState != nullptr ) {
		delete m_cleaveState;
	}
	if ( m_firebreathState != nullptr ) {
		delete m_firebreathState;
	}
	if ( m_smashState != nullptr ) {
		delete m_smashState;
	}
	if ( m_castspellState != nullptr ) {
		delete m_castspellState;
	}
	m_currentState = nullptr;

}