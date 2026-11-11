#include "Crosshair.h"

Crosshair::Crosshair(const sf::Texture& texture)
	: m_Sprite(texture)
{
	setScale(m_BaseScale);
	
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
}

void Crosshair::setPosition(const sf::Vector2f& position)
{
	sf::Transformable::setPosition(position);
}

void Crosshair::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Sprite, states);
}
