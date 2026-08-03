#include "Application.h"

const sf::Time Application::m_TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
	: m_Window(sf::VideoMode({ 800, 600 }), "atan2-playground"),
	  m_Textures(loadTextures()),
	  m_Player(m_Textures.get(TextureID::Player)),
	  m_Crosshair(m_Textures.get(TextureID::Crosshair))
{
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_Window.isOpen()) {
		sf::Time dT = clock.restart();
		dT = std::min(dT, sf::seconds(0.25f));
		timeSinceLastUpdate += dT;

		while (timeSinceLastUpdate > m_TimePerFrame) {
			timeSinceLastUpdate -= m_TimePerFrame;
			processEvents();
			update(m_TimePerFrame);
		}

		render();
	}
}

void Application::processEvents()
{
	while (const std::optional event = m_Window.pollEvent()) {
		if (event->is<sf::Event::Closed>())
			m_Window.close();
	}
}

void Application::update(sf::Time dT)
{
}

void Application::render()
{
	m_Window.clear();

	m_Player.render(m_Window);
	m_Crosshair.render(m_Window);

	m_Window.display();
}

TextureManager Application::loadTextures()
{
	TextureManager textures;
	textures.load(TextureID::Player, "Assets/player.png");
	textures.load(TextureID::Crosshair, "Assets/crosshair.png");
	textures.load(TextureID::Projectile, "Assets/projectile.png");

	return textures;
}
