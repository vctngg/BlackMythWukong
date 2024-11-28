#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size) :RectangleShape((sf::Vector2f)size)
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	m_Velocity = sf::Vector2f(0, 0);
	m_isAlive = true;
}

HitBox::~HitBox()
{
}

void HitBox::Init(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}
void HitBox::Update(float deltaTime)
{
	if ( m_isVulnerable == false ) {
		m_vulnerability_timer += deltaTime;
		if ( m_vulnerability_timer > 0.4f ) {
			m_vulnerability_timer = 0;
			setVulnerable(true);
		}
	}
}
void HitBox::SetStats()
{
	switch ( m_Tag ) {
	case PLAYER: 
	{
		SetTotalHP(PLAYER_HP);
		SetCurrentHP(PLAYER_HP);
		SetDamage(0);
		break;
	}
	case PLAYER_Summon: 
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(PLAYER_SUMMON);
		break;
	}
	case PLAYER_Attack1:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(PLAYER_ATTACK1);
		break;
	}
	case PLAYER_Attack2:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(PLAYER_ATTACK2);
		break;
	}
	case PLAYER_Attack3:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(PLAYER_ATTACK3);
		break;
	}
	case BOSS: 
	{
		SetTotalHP(BOSS_HP);
		SetCurrentHP(BOSS_HP);
		SetDamage(5);
		break;
	}
	case BOSS_Bullet: 
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(BOSS_ATTACK);
		break;
	}
	case CREEP: 
	{

		break;
	}
	case MONSTER:
	{
		SetTotalHP(MINOTAUR_HP);
		SetCurrentHP(MINOTAUR_HP);
		SetDamage(5);
		break;
	}
	case MONSTER_Attack:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(MINOTAUR_ATTACK);
		break;
	}
	case MONSTER_Swing:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(MINOTAUR_SWING);
		break;
	}
	case FROG:
	{
		SetTotalHP(FROG_HP);
		SetCurrentHP(FROG_HP);
		SetDamage(5);
		break;
	}
	case FROG_Attack:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(FROG_LICK);
		break;
	}
	case FROG_Spit:
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(FROG_SPIT);
		break;
	}
	default: 
	{
		break;
	}
	}
}
sf::Vector2f HitBox::getVelocity()
{
	return m_Velocity;
}

void HitBox::setVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}