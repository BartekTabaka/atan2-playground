#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Transformable, public sf::Drawable {
public:
	Player(const sf::Texture& texture);

	void update(float dT);

	void setMovementDirection(const sf::Vector2f& direction);

	sf::Vector2f getPosition() const { return sf::Transformable::getPosition(); }
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite m_Sprite;

	sf::Vector2f m_Direction;

	static constexpr sf::Vector2f m_BaseScale = { 5.f, 5.f };
	static constexpr float m_Speed = 400.f; // Px/s
};
