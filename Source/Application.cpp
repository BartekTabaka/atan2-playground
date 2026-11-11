#include "Application.h"

#include <algorithm>

// Instance of the class accessible globally (via Application::Get())
static Application* s_Application = nullptr;

// Timer that tracks the application's runtime
static sf::Clock s_RuntimeClock;

Application::Application()
	: m_Window(sf::VideoMode({ m_WindowWidth, m_WindowHeight }), "atan2-playground", sf::Style::Titlebar | sf::Style::Close),
	m_Textures(loadTextures()),
	m_Player(m_Textures.get(TextureID::Player)),
	m_Crosshair(m_Textures.get(TextureID::Crosshair))
{
	s_Application = this;
	s_RuntimeClock.stop();
}

void Application::run()
{
	m_Running = true;
	s_RuntimeClock.restart();

	float timeSinceLastUpdate = s_RuntimeClock.getElapsedTime().asSeconds();

	while (m_Running) {
		while (m_Window.isOpen()) {
			// Event handling
			while (const std::optional event = m_Window.pollEvent()) {
				if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
					m_Window.close();
					stop();
					break;
				}
				if (event->is<sf::Event::MouseButtonPressed>() && event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
					sf::Vector2f mouseWorldPos = m_Window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(m_Window)));
					m_Crosshair.setPosition(mouseWorldPos);
				}
				if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Space) {
					if (m_Projectiles.size() + 1 <= 5) { // We check if there will be more than 5 projectiles AFTER we create one
						m_Projectiles.emplace_back(
							m_Textures.get(TextureID::Projectile),
							m_Player.getPosition(),
							m_Crosshair.getPosition()
						);
					}
				}
			}

			// DeltaTime
			float currentTime = s_RuntimeClock.getElapsedTime().asSeconds();
			float dT = currentTime - timeSinceLastUpdate;
			timeSinceLastUpdate = currentTime;

			update(dT);

			render();
		}
	}
}

void Application::stop()
{
	m_Running = false;
}

Application& Application::get()
{
	assert(s_Application);
	return *s_Application;
}

void Application::update(float dT)
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

	m_Window.draw(m_Player);
	m_Window.draw(m_Crosshair);
	for (auto& projectile : m_Projectiles) {
		m_Window.draw(projectile);
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
