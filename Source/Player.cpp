#include "Player.h"

Player::Player(const sf::Texture& texture)
	: m_Sprite(texture)
{
	m_Sprite.setScale(m_Scale);
}

void Player::update(sf::Time dT)
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_Sprite);
}
