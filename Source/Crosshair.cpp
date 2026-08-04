#include "Crosshair.h"

Crosshair::Crosshair(const sf::Texture& texture)
	: m_Sprite(texture)
{
	m_Sprite.setScale(m_BaseScale);
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
}

void Crosshair::render(sf::RenderTarget& target)
{
	target.draw(m_Sprite);
}

void Crosshair::setPosition(const sf::Vector2f& position)
{
	m_Sprite.setPosition(position);
}
