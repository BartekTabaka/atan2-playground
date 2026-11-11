#pragma once
#include <SFML/Graphics.hpp>

class Crosshair : public sf::Transformable, public sf::Drawable {
public:
	Crosshair(const sf::Texture& texture);

	void setPosition(const sf::Vector2f& position);

	sf::Vector2f getPosition() const { return sf::Transformable::getPosition(); }
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite m_Sprite;

	static constexpr sf::Vector2f m_BaseScale = { 5.f, 5.f };
};
