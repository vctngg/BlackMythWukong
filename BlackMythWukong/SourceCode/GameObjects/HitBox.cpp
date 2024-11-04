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
	case PLAYER_Bullet: 
	{
		SetTotalHP(-1);
		SetCurrentHP(-1);
		SetDamage(PLAYER_SUMMON);
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