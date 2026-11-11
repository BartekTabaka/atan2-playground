#pragma once

#include <vector>

#include "ResourceIdentifiers.h"
#include "Player.h"
#include "Crosshair.h"
#include "Projectile.h"

class Application {
public:
	Application();

	void run();
	void stop();

	const sf::RenderWindow& getWindow() { return m_Window; }

	static Application& get(); // Get instance

private:
	void update(float dT);
	void render();

	static TextureManager loadTextures();
private:
	bool m_Running = false;

	sf::RenderWindow m_Window;
	static constexpr unsigned int m_WindowWidth = 1280;
	static constexpr unsigned int m_WindowHeight = 920;

	TextureManager m_Textures;

	Player m_Player;
	Crosshair m_Crosshair;
	std::vector<Projectile> m_Projectiles;
};
