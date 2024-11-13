#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Types.h"
#include <optional>

// Data structures for component configurations
struct VisualComponentData {
	const std::string filename;
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
	const sf::Vector2i frameSize;
	const sf::Vector2i startPos;
	const size_t frameCount;
	const sf::Time frameDuration;
	const bool loop;
};

struct WeaponComponentData {
	const float baseDamage;
	const float baseSpeed;
	const float speedInterval;
	const float baseRange;
	const sf::Vector2f rangeInterval;
	const float baseRadius;
	const float baseCritChance;
	const float baseCritDamage;
	const float baseCD;
	const float baseDuration;
};


struct EntityConfig {
	const VisualComponentData visual;
	const CollisionComponentData collision;
	std::unordered_map<EntityState, AnimationInfo> animations;
	const std::optional<WeaponComponentData> weapon;
};

namespace Config {
	extern const EntityConfig PLAYER;
	extern const EntityConfig LASER_WEAPON;
	extern const EntityConfig VAMPIRE;
	extern const std::unordered_map<EntityType, const EntityConfig&> ENTITY_CONFIGS;
}
