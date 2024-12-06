#include "Frog.h"
#include "FSLick.h"
#include "FSHurt.h"
#include "FSIdle.h"
#include "FSRun.h"
#include "FSSpit.h"
#include "FSDeath.h"
#include "FSHeal.h"

Frog::Frog()
{
	m_nextState = IFState::SNULL;
	m_idleState = new FSIdle(this);
	m_hurtState = new FSHurt(this);
	m_runState = new FSRun(this);
	m_attackState = new FSLick(this);
	m_spitState = new FSSpit(this);
	m_healState = new FSHeal(this);
	m_deathState = new FSDeath(this);

	m_currentState = m_idleState;

	m_FrogWeapon = new FrogWeapon();

}

Frog::~Frog()
{
	if ( m_runState != nullptr ) {
		delete m_runState;
	}
	if ( m_idleState != nullptr ) {
		delete m_idleState;
	}
	if ( m_hurtState != nullptr ) {
		delete m_hurtState;
	}
	if ( m_attackState != nullptr ) {
		delete m_attackState;
	}
	if ( m_spitState != nullptr ) {
		delete m_spitState;
	}
	if ( m_healState != nullptr ) {
		delete m_healState;
	}
	if ( m_deathState != nullptr ) {
		delete m_deathState;
	}
	if ( m_FrogWeapon != nullptr ) {
		delete m_FrogWeapon;
	}
	m_currentState = nullptr;

}

void Frog::changeNextState(IFState::STATE nextState)
{
	m_nextState = nextState;
}

void Frog::Init(CollisionManager& CM, SkillManager& SM)
{

	m_runState->Init();
	m_idleState->Init();
	m_attackState->Init();
	m_hurtState->Init();
	m_spitState->Init();
    m_deathState->Init();
	m_healState->Init();

	m_skill = new Skill();
	m_skill->SetType(FROG_SKILL_HEAL);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(FROG_SKILL_LICK);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;
	m_skill = new Skill();
	m_skill->SetType(FROG_SKILL_SPIT);
	m_skill->UnlockSkill();
	SM.AddSkill(m_skill);
	//delete m_skill;

	m_HitBox = new HitBox(sf::Vector2i(64, 64));
	m_HitBox->setPosition(screenWidth - 300, groundY - m_HitBox->getSize().y / 2);
	m_HitBox->Init(sf::Vector2f(100, 500));
	m_HitBox->SetTag(FROG);
	m_HitBox->setAlive(true);

	CM.addObj(m_HitBox);
	m_FrogWeapon->Init(CM);
}

void Frog::Update(float deltaTime, sf::Vector2f offset, SkillManager& SM)
{
	MFacingCheck(getHitBox()->getPosition().x, ReturnPlayerPosition().x);
	performStateChange();
	m_playerOffset = offset;
	m_FrogWeapon->Update(deltaTime, offset);
	m_currentState->Update(deltaTime, SM);
}
void Frog::FacingCheck() {

}
void Frog::Render(sf::RenderWindow* window)
{
	m_FrogWeapon->Render(window);
	m_currentState->Render(window);
	window->draw(*m_HitBox);

}

HitBox* Frog::getHitBox()
{
	return m_HitBox;
}

void Frog::GetDistanceFromPlayer(HitBox* player_hitbox, CollisionManager& CM)
{
	m_distanceFromPlayer = CM.GetDistance(m_HitBox, player_hitbox);
}

float Frog::ReturnDistanceFromPlayer()
{
	return m_distanceFromPlayer;
}

void Frog::GetPlayerPosition(HitBox* player_hitbox)
{
	m_playerPosition = player_hitbox->getPosition();
}

sf::Vector2f Frog::ReturnPlayerPosition()
{
	return m_playerPosition;
}

FrogWeapon* Frog::getWeapon()
{
	return m_FrogWeapon;
}

void Frog::performStateChange()
{
	if ( m_nextState != IFState::SNULL ) {
		switch ( m_nextState )
		{
		case IFState::RUN:
			m_currentState = m_runState;
			break;
		case IFState::HURT:
			m_currentState = m_hurtState;
			break;
		case IFState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IFState::IDLE:
			m_currentState = m_idleState;
			break;
		case IFState::SPIT:
			m_currentState = m_spitState;
			break;
		case IFState::HEAL:
			m_currentState = m_healState;
			break;
		case IFState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			m_currentState = m_idleState;
			break;
		}
		m_nextState = IFState::SNULL;
		m_currentState->Reset();
	}
}