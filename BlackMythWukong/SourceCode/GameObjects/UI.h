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
private:
	int m_frameCount;
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	sf::Vector2i m_rectUV;
	sf::Vector2i m_rectSize;
	sf::IntRect m_rect;
	bool do_flip;

	float m_currentTime;
};