#include "Projectile.h"

#include <cmath>

#include "Application.h"

Projectile::Projectile(const sf::Texture& texture, const sf::Vector2f& startPos, const sf::Vector2f& targetPos)
	: m_Sprite(texture)
{
	setScale(m_BaseScale);

	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });

	setPosition(startPos);

	// -- Direction ------------
	
	// delta - difference between points coordinates, represented by an arrow pointing from startPos to targetPos
	const sf::Vector2f directionVector = targetPos - startPos; 

	// Vector length, distance between points
	const float distance = std::hypot(directionVector.x, directionVector.y);

	if (distance > 0.f) {
		m_Direction = directionVector / distance; // Normalize vector

		// Calculate the angle between the positive X-axis and our vector
		const float angleRad = std::atan2(directionVector.y, directionVector.x);
		setRotation(sf::radians(angleRad));
	}
	else {
		m_Direction = { 0.f, 1.f };
		setRotation(sf::degrees(90.f));
	}
}

void Projectile::update(float dT)
{
	move(m_Direction * m_Speed * dT);

	// Mark for removal
	const sf::FloatRect bounds = getGlobalBounds();
	const sf::Vector2f windowSize = static_cast<sf::Vector2f>(Application::get().getWindow().getSize());
	if (bounds.position.x + bounds.size.x < 0.f ||
		bounds.position.y + bounds.size.y < 0.f ||
		bounds.position.x > windowSize.x ||
		bounds.position.y > windowSize.y) {
		m_MarkedForRemoval = true;
	}
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_Sprite, states);
}
