#include "Player.h"
#include <print>
Player::Player(const sf::Texture& texture)
	: m_Sprite(texture)
{
	m_Sprite.setScale(m_BaseScale);
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
}

void Player::update(sf::Time dT)
{
	m_Sprite.move(m_Direction * m_Speed * dT.asSeconds());
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_Sprite);
}

void Player::setMovementDirection(const sf::Vector2f& direction)
{
	// Player's texture looks left on default, we make it look in direction it's walking in on X axis 
	// by manipulating player's scale
	if (direction.x > 0)
		m_Sprite.setScale({ -m_BaseScale.x, m_BaseScale.y });
	else if (direction.x < 0)
		m_Sprite.setScale(m_BaseScale);

	m_Direction = direction;
}
