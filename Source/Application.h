#pragma once
#include "ResourceIdentifiers.h"
#include "Player.h"
#include "Crosshair.h"
#include "Projectile.h"
#include <vector>

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
	static constexpr unsigned int m_WindowWidth = 1280;
	static constexpr unsigned int m_WindowHeight = 920;	

	TextureManager m_Textures;

	Player m_Player;
	Crosshair m_Crosshair;
	std::vector<Projectile> m_Projectiles;
	
	static const sf::Time m_TimePerFrame;
};
