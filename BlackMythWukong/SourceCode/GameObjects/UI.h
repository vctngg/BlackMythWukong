#pragma once
#include "../GameManager/ResourceManager.h"
#include "MovementCheck.h"
class UI :public sf::Sprite
{
public: 
	void Init(sf::Texture& texture, sf::Vector2i frame_num, sf::Vector2f pos, int frame_count);
	void Update(float deltaTime);
	void Reset();
	void CalculateRectUV();
	void CalculateRectSize();
	void ApplyRect();
	void flip(bool do_flip);
	sf::Vector2i GetCurrentFrame();
	void ChangeFrame(int frame_number);
	void Animate(float deltaTime);
	void SetAnimate(float frame_time);
private:
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