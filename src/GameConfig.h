#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Types.h"

// Data structures for component configurations
struct VisualComponentData {
	const std::string filename;
	const sf::Vector2f frameSize;
	const sf::Vector2f scale;
	const sf::Vector2f origin;
	const sf::Vector2f offset;
	const float rotation;
};

struct CollisionComponentData {
	const sf::Vector2f size;
	const sf::Vector2f scale;
	const sf::Vector2f origin;
	const sf::Vector2f offset;
	const float rotation;
	const sf::Color debugColor;
};

struct AnimationInfo {
	const std::string texturePath;
	const sf::Vector2i frameSize;
	const sf::Vector2i startPos;
	const size_t frameCount;
	const sf::Time frameDuration;
	const bool loop;
};


struct EntityConfig {
	const VisualComponentData visual;
	const CollisionComponentData collision;
	std::unordered_map<EntityState, AnimationInfo> animations;
};

namespace Config {
	extern const EntityConfig PLAYER;
	extern const EntityConfig LASER_WEAPON;
	extern const std::unordered_map<EntityType, const EntityConfig&> ENTITY_CONFIGS;
}
