#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(const sf::Texture& texture);

	void update(sf::Time dT);
	void render(sf::RenderTarget& target);

	sf::Vector2f getPosition() const { return m_Sprite.getPosition(); }
private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Scale = { 5.f, 5.f };
};
