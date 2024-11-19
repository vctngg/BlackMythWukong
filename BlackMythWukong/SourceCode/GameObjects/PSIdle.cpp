#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation(*DATA->getTexture("wukong/wukong_stand"), sf::Vector2i(4, 1), 0.1f);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_Player->FacingCheck();
	if ( m_Player->FacingLeft() )
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::O) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_SKILL_SUMMON) )
			{
				sf::Vector2f pos = m_Player->getHitBox()->getPosition();
				m_Player->getWeapon()->GetDirection(m_Player->FacingLeft());
				m_Player->getWeapon()->Summon(sf::Vector2f(pos.x, pos.y + 4));
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_1) )
			{
				m_Player->changeNextState(ATTACK1);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_2) )
			{
				m_Player->changeNextState(ATTACK2);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_3) )
			{
				m_Player->changeNextState(ATTACK3);
			}
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

	}
	else
	{
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::O) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_SKILL_SUMMON) )
			{
				sf::Vector2f pos = m_Player->getHitBox()->getPosition();
				m_Player->getWeapon()->GetDirection(m_Player->FacingLeft());
				m_Player->getWeapon()->Summon(sf::Vector2f(pos.x, pos.y + 4));
			}
			
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) {
			m_Player->changeNextState(JUMP);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
			m_Player->changeNextState(RUN);
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_1) )
			{
				m_Player->changeNextState(ATTACK1);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_2) )
			{
				m_Player->changeNextState(ATTACK2);
			}
		}
		else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::L) ) {
			if ( LM->AccessSkillManager().IsUnlocked(PLAYER_ATTACK_3) )
			{
				m_Player->changeNextState(ATTACK3);
			}
		}
		if ( !m_Player->getHitBox()->isAlive() ) m_Player->changeNextState(IPState::DEATH);

	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition().x + m_Player->m_offset.x, m_Player->getHitBox()->getPosition().y + 6 + m_Player->m_offset.y);
	m_Animation->flip(m_Player->FacingLeft());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSIdle::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}