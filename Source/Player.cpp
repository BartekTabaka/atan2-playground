#include "Player.h"

#include <algorithm>

#include "Application.h"

Player::Player(const sf::Texture& texture)
	: m_Sprite(texture)
{
	setScale(m_BaseScale);
	
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
}

void Player::update(float dT)
{
	const sf::Vector2f shift = m_Direction * m_Speed * dT;
	const sf::Vector2f pos = getPosition();

	const float newX = pos.x + shift.x;
	const float newY = pos.y + shift.y;

	sf::Vector2f windowSize = static_cast<sf::Vector2f>(Application::get().getWindow().getSize());
	const float clampedX = std::clamp(newX, 0.f, windowSize.x);
	const float clampedY = std::clamp(newY, 0.f, windowSize.y);
	setPosition({ clampedX, clampedY });
}

void Player::setMovementDirection(const sf::Vector2f& direction)
{
	// Player's texture looks left on default, we make it look in direction it's walking in on X axis 
	// by manipulating player's scale
	if (direction.x > 0)
		setScale({ -m_BaseScale.x, m_BaseScale.y });
	else if (direction.x < 0)
		setScale(m_BaseScale);

	m_Direction = direction;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Sprite, states);
}
