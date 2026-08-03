#pragma once
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

enum class TextureID { Player, Crosshair, Projectile };

using TextureManager = ResourceManager<sf::Texture, TextureID>;
