#include "Player.h"
#include <algorithm>

Player::Player(const sf::Texture& texture, const sf::Vector2f& windowSize)
	: m_Sprite(texture), m_WindowSize(windowSize)
{
	m_Sprite.setScale(m_BaseScale);
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
}

void Player::update(sf::Time dT)
{
	const sf::Vector2f shift = m_Direction * m_Speed * dT.asSeconds();
	const sf::Vector2f pos = m_Sprite.getPosition();

	const float newX = pos.x + shift.x;
	const float newY = pos.y + shift.y;

	const float clampedX = std::clamp(newX, 0.f, m_WindowSize.x);
	const float clampedY = std::clamp(newY, 0.f, m_WindowSize.y);
	m_Sprite.setPosition({ clampedX, clampedY });
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
