#include "ParallelBackground.h"

void ParallexBackground::Init(BGTYPE bg_type)
{
	m_backgroundType = bg_type;
	switch ( m_backgroundType )
	{
	case GLACIAL_MOUNTAIN: {
		y_pos = 0;
		m_scaling = sf::Vector2f(2.4f, 2.4f);

		Layer* layer;
		std::string path = "Background/Glacial-mountain/";
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
		layer->Init(path + "clouds_mg_3", 100, y_pos + 10, m_scaling);
		m_Background.push_back(layer);
		//Layer 5
		layer = new Layer();
		layer->Init(path + "clouds_mg_2", 110, y_pos + 10, m_scaling);
		m_Background.push_back(layer);
		//Layer 4
		layer = new Layer();
		layer->Init(path + "clouds_mg_1", 120, y_pos + 10, m_scaling);
		m_Background.push_back(layer);
		break;
	}
	case FOREST: {
		Layer* layer;
		y_pos = -screenHeight - 20;
		m_scaling = sf::Vector2f(1.4f, 1.4f);
		std::string path = "Background/Forest/";
		//Layer 2
		layer = new Layer();
		layer->Init(path + "Layer_0009_2", 50, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 3
		layer = new Layer();
		layer->Init(path + "Layer_0008_3", 60, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 4
		layer = new Layer();
		layer->Init(path + "Layer_0007_Lights", 100, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 5
		layer = new Layer();
		layer->Init(path + "Layer_0006_4", 110, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 6
		layer = new Layer();
		layer->Init(path + "Layer_0005_5", 120, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 7
		layer = new Layer();
		layer->Init(path + "Layer_0004_Lights", 140, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 8
		layer = new Layer();
		layer->Init(path + "Layer_0003_6", 170, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 9
		layer = new Layer();
		layer->Init(path + "Layer_0002_7", 200, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 10
		layer = new Layer();
		layer->Init(path + "Layer_0001_8", 200, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 1
		layer = new Layer();
		layer->Init(path + "Layer_0000_9", 200, y_pos, m_scaling);
		m_Background.push_back(layer);
		break;
	}
	case AUTUMN_FOREST: {
		Layer* layer;
		y_pos = 0;
		m_scaling = sf::Vector2f(3.f, 3.f);
		std::string path = "Background/Autumn-Forest/";
		//Layer 1
		layer = new Layer();
		layer->Init(path + "background_layer_1", 100, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 2
		layer = new Layer();
		layer->Init(path + "background_layer_2", 60, y_pos, m_scaling);
		m_Background.push_back(layer);
		//Layer 3
		layer = new Layer();
		layer->Init(path + "background_layer_3", 50, y_pos, m_scaling);
		m_Background.push_back(layer);
		break;
	}
	default: {
		break;
	}
	}
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

void ParallexBackground::SwitchBackground(BGTYPE bg_type)
{
	if (m_backgroundType != bg_type )
	{
		m_Background.clear();
		Init(bg_type);
	}
}
