#pragma once
#include "GameStateBase.h"
class GSSetting : public GameStateBase {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_Background;
	sf::Text m_Title, a, b, c, d;
	std::list<GameButton*> m_ListBtn;

};
