#pragma once
#include <SFML/Graphics.hpp>

class Crosshair {
public:
	Crosshair(const sf::Texture& texture);

	void render(sf::RenderTarget& target);
	void setPosition(const sf::Vector2f& position);

	sf::Vector2f getPosition() { return m_Sprite.getPosition(); }
private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Scale = { 5.f, 5.f };
};
