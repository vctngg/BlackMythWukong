#pragma once
#include "Layer.h"
enum BGTYPE {
	GLACIAL_MOUNTAIN,
	FOREST,
	AUTUMN_FOREST,
};
class ParallexBackground
{
public:
	void Init(BGTYPE bg_type);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void SwitchBackground(BGTYPE bg_type);
private:
	std::list<Layer*> m_Background;
	float y_pos;
	sf::Vector2f m_scaling;
	BGTYPE m_backgroundType;
};
