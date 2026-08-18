#include "Application.h"
#include <algorithm>

const sf::Time Application::m_TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application()
	: m_Window(sf::VideoMode({ m_WindowWidth, m_WindowHeight }), "atan2-playground", sf::Style::Titlebar | sf::Style::Close),
	m_Textures(loadTextures()),
	m_Player(m_Textures.get(TextureID::Player), sf::Vector2f({ m_WindowWidth, m_WindowHeight })),
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
		if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			m_Window.close();
		if (event->is<sf::Event::MouseButtonPressed>() && event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
			sf::Vector2f mouseWorldPos = m_Window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(m_Window)));
			m_Crosshair.setPosition(mouseWorldPos);
		}
		if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space) {
			if (m_Projectiles.size() <= 5)
				m_Projectiles.emplace_back(
					m_Textures.get(TextureID::Projectile),
					m_Player.getPosition(),
					m_Crosshair.getPosition(),
					sf::Vector2f({ m_WindowWidth, m_WindowHeight })
				);
		}
	}
}

void Application::update(sf::Time dT)
{
	// Player
	sf::Vector2f direction(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) direction.y -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) direction.y += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) direction.x -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) direction.x += 1.f;

	// Normalize
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0.f)
		direction /= length;

	m_Player.setMovementDirection(direction);
	m_Player.update(dT);

	// Projectiles
	for (auto& projectile : m_Projectiles) {
		projectile.update(dT);
	}
	
	m_Projectiles.erase(
		std::remove_if(m_Projectiles.begin(), m_Projectiles.end(), [](const Projectile& projectile) {
			return projectile.isMarkedForRemoval();
			}),
		m_Projectiles.end()
	);
}

void Application::render()
{
	m_Window.clear();

	m_Player.render(m_Window);
	m_Crosshair.render(m_Window);
	for (auto& projectile : m_Projectiles) {
		projectile.render(m_Window);
	}

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
