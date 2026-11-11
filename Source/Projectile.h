#pragma once
#include <SFML/Graphics.hpp>

class Projectile : public sf::Transformable, public sf::Drawable {
public:
	Projectile(const sf::Texture& texture, const sf::Vector2f& startPos, const sf::Vector2f& targetPos);

	void update(float dT);

	bool isMarkedForRemoval() const { return m_MarkedForRemoval; }
	sf::FloatRect getGlobalBounds() const
	{
		return getTransform().transformRect(m_Sprite.getGlobalBounds());
	}
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite m_Sprite;

	sf::Vector2f m_Direction;
	bool m_MarkedForRemoval = false;

	static constexpr sf::Vector2f m_BaseScale = { 5.f, 5.f };
	static constexpr float m_Speed = 600.f; // Px/s
};
