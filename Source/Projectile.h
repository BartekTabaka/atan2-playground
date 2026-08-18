#pragma once
#include <SFML/Graphics.hpp>

class Projectile {
public:
	Projectile(const sf::Texture& texture, const sf::Vector2f& startPos, const sf::Vector2f& targetPos, const sf::Vector2f& windowSize);

	void update(sf::Time dT);
	void render(sf::RenderTarget& target);

	bool isMarkedForRemoval() const { return m_MarkedForRemoval; }
private:
	sf::Sprite m_Sprite;
	static constexpr sf::Vector2f m_BaseScale = { 5.f, 5.f };
	sf::Vector2f m_WindowSize;

	static constexpr float m_Speed = 600.f; // Px/s
	sf::Vector2f m_Direction;
	bool m_MarkedForRemoval = false;
};
