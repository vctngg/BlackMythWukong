#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	y_pos = 0;
	m_scaling = sf::Vector2f(2.4f, 2.4f);

	Layer* layer;
	std::string path = "Bg/";
	//Layer 1
	layer = new Layer();
	layer->Init(path + "sky", 40, y_pos, m_scaling);
	m_Background.push_back(layer);
	//Layer 2
	layer = new Layer();
	layer->Init(path + "cloud_lonely", 45, y_pos, m_scaling);
	m_Background.push_back(layer);
	//Layer 3
	layer = new Layer();
	layer->Init(path + "clouds_bg", 60, y_pos, m_scaling);
	m_Background.push_back(layer);
	//Layer 7
	layer = new Layer();
	layer->Init(path + "glacial_mountains", 50, y_pos, m_scaling);
	m_Background.push_back(layer);
	//Layer 6
	layer = new Layer();
	layer->Init(path + "clouds_mg_3", 100, y_pos+10, m_scaling);
	m_Background.push_back(layer);
	//Layer 5
	layer = new Layer();
	layer->Init(path + "clouds_mg_2", 110, y_pos+10, m_scaling);
	m_Background.push_back(layer);
	//Layer 4
	layer = new Layer();
	layer->Init(path + "clouds_mg_1", 120, y_pos+10, m_scaling);
	m_Background.push_back(layer);


	
	
}

void ParallexBackground::Update(float deltaTime)
{
	for ( auto layer : m_Background ) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for ( auto layer : m_Background ) {
		layer->Render(window);
	}
}