#pragma once
#include "../GameManager/ResourceManager.h"
#include "MovementCheck.h"

class Layer {
public:
	void Init(std::string name, float speed, float y_pos);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_image[5];
	float m_Speed;
	MovementCheck m_MovementManager;
	sf::Vector2i m_SizeImage;
	int m_ImageNumber = 0;
};
