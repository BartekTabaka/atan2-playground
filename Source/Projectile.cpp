#include "Projectile.h"

Projectile::Projectile(const sf::Texture& texture, const sf::Vector2f& startPos, const sf::Vector2f& targetPos, const sf::Vector2f& windowSize)
	: m_Sprite(texture), m_WindowSize(windowSize)
{
	m_Sprite.setScale(m_BaseScale);
	m_Sprite.setOrigin({ m_Sprite.getLocalBounds().size.x / 2, m_Sprite.getLocalBounds().size.y / 2 });
	m_Sprite.setPosition(startPos);

	// Direction
	sf::Vector2f delta = targetPos - startPos;
	const float length = std::sqrt(delta.x * delta.x + delta.y * delta.y);
	if (length != 0.f)
		m_Direction = delta / length;
	else
		m_Direction = { 0.f, 1.f };

	if (delta.x == 0.f && delta.y == 0.f) {
		m_Sprite.setRotation(sf::degrees(90.f));
	}
	else {
		const float angleRad = std::atan2(delta.y, delta.x);
		m_Sprite.setRotation(sf::radians(angleRad));
	}
}

void Projectile::update(sf::Time dT)
{
	m_Sprite.move(m_Direction * m_Speed * dT.asSeconds());

	// Mark for removal
	sf::Vector2f pos = m_Sprite.getPosition();
	if (pos.x < 0 || pos.x > m_WindowSize.x || pos.y < 0 || pos.y > m_WindowSize.y)
		m_MarkedForRemoval = true;
}

void Projectile::render(sf::RenderTarget& target)
{
	target.draw(m_Sprite);
}
