#include "Crosshair.h"

Crosshair::Crosshair(const sf::Texture& texture)
	: m_Sprite(texture)
{
	m_Sprite.setScale(m_Scale);
}

void Crosshair::render(sf::RenderTarget& target)
{
	target.draw(m_Sprite);
}

void Crosshair::setPosition(const sf::Vector2f& position)
{
	m_Sprite.setPosition(position);
}
