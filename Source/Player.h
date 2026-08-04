#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(const sf::Texture& texture);

	void update(sf::Time dT);
	void render(sf::RenderTarget& target);

	void setMovementDirection(const sf::Vector2f& direction);

	sf::Vector2f getPosition() const { return m_Sprite.getPosition(); }
private:
	sf::Sprite m_Sprite;
	static constexpr sf::Vector2f m_BaseScale = { 5.f, 5.f };

	sf::Vector2f m_Direction;
	float m_Speed = 400.f; // Px/s
};
