#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <optional>
#include "../Types.h"

// Data structures for component configurations
struct VisualComponentData
{
    std::string filename;
    sf::Vector2f scale;
    sf::Vector2f origin;
    sf::Vector2f offset;
    float rotation;
};

struct CollisionComponentData
{
    sf::Vector2f size;
    sf::Vector2f scale;
    sf::Vector2f origin;
    sf::Vector2f offset;
    float rotation;
    sf::Color debugColor;
};

struct AnimationInfo
{
    sf::Vector2i frameSize;
    sf::Vector2i startPos;
    size_t frameCount;
    sf::Time frameDuration;
    bool loop;
    bool flipX;
};

struct WeaponComponentData
{
    float baseDamage;
    float baseSpeed;
    float speedInterval;
    float baseRange;
    sf::Vector2f rangeInterval;
    float baseRadius;
    float baseCritChance;
    float baseCritDamage;
    float baseCD;
    float baseDuration;
};

struct EntityConfig
{
    VisualComponentData visual;
    CollisionComponentData collision;
    std::unordered_map<EntityState, AnimationInfo> animations;
    std::optional<WeaponComponentData> weapon;
};

namespace Config {
    extern const EntityConfig PLAYER;
    extern const EntityConfig LASER_WEAPON;
    extern const EntityConfig VAMPIRE;
    extern const std::unordered_map<EntityType, const EntityConfig &> ENTITY_CONFIGS;
} // namespace Config
