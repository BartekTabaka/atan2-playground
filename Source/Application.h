#pragma once
#include "ResourceIdentifiers.h"
#include "Player.h"
#include "Crosshair.h"

class Application {
public:
	Application();

	void run();
private:
	void processEvents();
	void update(sf::Time dT);
	void render();

	static TextureManager loadTextures();
private:
	sf::RenderWindow m_Window;
	TextureManager m_Textures;

	Player m_Player;
	Crosshair m_Crosshair;
	
	static const sf::Time m_TimePerFrame;
};
