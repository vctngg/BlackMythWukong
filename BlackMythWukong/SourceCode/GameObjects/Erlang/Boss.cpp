#include "Boss.h"
#include "BSAttack.h"
#include "BSHurt.h"
#include "BSIdle.h"
#include "BSRun.h"
#include "BSWaiting.h"
#include "BSFlee.h"

Boss::Boss()
{
	m_nextState = IBState::SNULL;
	m_idleState = new BSIdle(this);
	m_hurtState = new BSHurt(this);
	m_runState = new BSRun(this);
	m_attackState = new BSAttack(this);
	m_waitingState = new BSWaiting(this);
	m_fleeState = new BSFlee(this);

	m_currentState = m_waitingState;

	m_BossWeapon = new BossWeapon();
}

Boss::~Boss()
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
	if ( m_waitingState != nullptr ) {
		delete m_waitingState;
	}
	if ( m_fleeState != nullptr ) {
		delete m_fleeState;
	}
	if ( m_BossWeapon != nullptr ) {
		delete m_BossWeapon;
	}
	m_currentState = nullptr;

}

void Boss::changeNextState(IBState::STATE nextState)
{
	m_nextState = nextState;
}

void Boss::Init()
{
	m_runState->Init();
	m_idleState->Init();
	m_attackState->Init();
	m_hurtState->Init();
	m_waitingState->Init();
	m_fleeState->Init();

	m_HitBox = new HitBox(sf::Vector2i(16, 32));
	m_HitBox->setPosition(screenWidth-300, groundY - m_HitBox->getSize().y / 2);
	m_HitBox->Init(sf::Vector2f(100, 500));
	m_HitBox->SetTag(BOSS);

	CM->addObj(m_HitBox);
	m_BossWeapon->Init();
}
void Boss::FacingCheck() {

}

void Boss::Update(float deltaTime, sf::Vector2f offset)
{
	performStateChange();
	m_playerOffset = offset;
	m_BossWeapon->Update(deltaTime, offset);
	m_currentState->Update(deltaTime);

	if ( m_currentState == m_waitingState ) {
		m_isWaiting = true;
	}
	else {
		m_isWaiting = false;
	}
}

void Boss::Render(sf::RenderWindow* window)
{
	m_BossWeapon->Render(window);
	m_currentState->Render(window);
	window->draw(*m_HitBox);

}

HitBox* Boss::getHitBox()
{
	return m_HitBox;
}

void Boss::GetDistanceFromPlayer(HitBox* player_hitbox)
{
	m_distanceFromPlayer = CM->GetDistance(m_HitBox, player_hitbox);
}

float Boss::ReturnDistanceFromPlayer()
{
	return m_distanceFromPlayer;
}

void Boss::GetPlayerPosition(HitBox* player_hitbox)
{
	m_playerPosition = player_hitbox->getPosition();
}

sf::Vector2f Boss::ReturnPlayerPosition()
{
	return m_playerPosition;
}



BossWeapon* Boss::getWeapon()
{
	return m_BossWeapon;
}

void Boss::performStateChange()
{
	if ( m_nextState != IBState::SNULL ) {
		switch ( m_nextState )
		{
		case IBState::RUN:
			m_currentState = m_runState;
			break;
		case IBState::HURT:
			m_currentState = m_hurtState;
			break;
		case IBState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IBState::IDLE:
			m_currentState = m_idleState;
			break;
		case IBState:: WAITING:
			m_currentState = m_waitingState;
			break;
		case IBState::FLEE:
			m_currentState = m_fleeState;
			break;
		default:
			m_currentState = m_waitingState;
			break;
		}
		m_nextState = IBState::SNULL;
		m_currentState->Reset();
	}
}