#pragma once
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"

class GameButton :public sf::RectangleShape {
public:
	GameButton();
	~GameButton();

	void Init(std::string name, sf::Vector2i frame_num, sf::Vector2f pos, int frame_count, sf::Vector2f size, sf::Vector2f scaling);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void CalculateRectUV();
	void CalculateRectSize();
	void ApplyRect();
	void flip(bool do_flip);
	sf::Vector2i GetCurrentFrame();
	void ChangeFrame(int frame_number);
	void Animate(float deltaTime);
	void SetAnimate(float frame_time);

	void HandleTouchEvent();
	bool isHandle();

	void setOnClick(void (*Func)());
private:
	void (*m_btnClickFunc)();
	bool m_isHandling;

	int m_frameCount;
	int m_currentFrameCount;
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	sf::Vector2i m_rectUV;
	sf::Vector2i m_rectSize;
	sf::IntRect m_rect;
	bool do_flip;
	bool m_doAnimate;
	float m_frameTime;
	float m_currentTime;
};
