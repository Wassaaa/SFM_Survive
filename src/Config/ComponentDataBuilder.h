#pragma once
#include <SFML/Graphics.hpp>
#include "GameConfig.h"

class VisualDataBuilder
{
public:
    VisualDataBuilder &setFilename(const std::string &filename)
    {
        m_filename = filename;
        return *this;
    }
    VisualDataBuilder &setScale(const sf::Vector2f &scale)
    {
        m_scale = scale;
        return *this;
    }
    VisualDataBuilder &setOrigin(const sf::Vector2f &origin)
    {
        m_origin = origin;
        return *this;
    }
    VisualDataBuilder &setOffset(const sf::Vector2f &offset)
    {
        m_offset = offset;
        return *this;
    }
    VisualDataBuilder &setRotation(float rotation)
    {
        m_rotation = rotation;
        return *this;
    }
    VisualComponentData build() const
    {
        return {m_filename, m_scale, m_origin, m_offset, m_rotation};
    }

private:
    std::string m_filename;
    sf::Vector2f m_scale{1.f, 1.f};
    sf::Vector2f m_origin{0.f, 0.f};
    sf::Vector2f m_offset{0.f, 0.f};
    float m_rotation{0.f};
};

class CollisionDataBuilder
{
public:
    CollisionDataBuilder &setSize(const sf::Vector2f &size)
    {
        m_size = size;
        return *this;
    }
    CollisionDataBuilder &setScale(const sf::Vector2f &scale)
    {
        m_scale = scale;
        return *this;
    }
    CollisionDataBuilder &setOrigin(const sf::Vector2f &origin)
    {
        m_origin = origin;
        return *this;
    }
    CollisionDataBuilder &setOffset(const sf::Vector2f &offset)
    {
        m_offset = offset;
        return *this;
    }
    CollisionDataBuilder &setRotation(float rotation)
    {
        m_rotation = rotation;
        return *this;
    }
    CollisionDataBuilder &setDebugColor(const sf::Color &color)
    {
        m_debugColor = color;
        return *this;
    }
    CollisionComponentData build() const
    {
        return {m_size, m_scale, m_origin, m_offset, m_rotation, m_debugColor};
    }

private:
    sf::Vector2f m_size;
    sf::Vector2f m_scale{1.f, 1.f};
    sf::Vector2f m_origin{0.f, 0.f};
    sf::Vector2f m_offset{0.f, 0.f};
    float m_rotation{0.f};
    sf::Color m_debugColor{255, 0, 0, 128};
};

class AnimationInfoBuilder
{
public:
    AnimationInfoBuilder &setFrameSize(const sf::Vector2i &size)
    {
        m_frameSize = size;
        return *this;
    }
    AnimationInfoBuilder &setStartPos(const sf::Vector2i &pos)
    {
        m_startPos = pos;
        return *this;
    }
    AnimationInfoBuilder &setFrameCount(size_t count)
    {
        m_frameCount = count;
        return *this;
    }
    AnimationInfoBuilder &setFrameDuration(const sf::Time &duration)
    {
        m_frameDuration = duration;
        return *this;
    }
    AnimationInfoBuilder &setLoop(bool loop)
    {
        m_loop = loop;
        return *this;
    }
    AnimationInfo build() const
    {
        return {m_frameSize, m_startPos, m_frameCount, m_frameDuration, m_loop};
    }

private:
    sf::Vector2i m_frameSize;
    sf::Vector2i m_startPos;
    size_t m_frameCount{1};
    sf::Time m_frameDuration{sf::milliseconds(100)};
    bool m_loop{true};
};

class WeaponDataBuilder
{
public:
    WeaponDataBuilder &setBaseDamage(float damage)
    {
        m_baseDamage = damage;
        return *this;
    }
    WeaponDataBuilder &setBaseSpeed(float speed)
    {
        m_baseSpeed = speed;
        return *this;
    }
    WeaponDataBuilder &setSpeedInterval(float interval)
    {
        m_speedInterval = interval;
        return *this;
    }
    WeaponDataBuilder &setBaseRange(float range)
    {
        m_baseRange = range;
        return *this;
    }
    WeaponDataBuilder &setRangeInterval(const sf::Vector2f &interval)
    {
        m_rangeInterval = interval;
        return *this;
    }
    WeaponDataBuilder &setBaseRadius(float radius)
    {
        m_baseRadius = radius;
        return *this;
    }
    WeaponDataBuilder &setCritChance(float chance)
    {
        m_baseCritChance = chance;
        return *this;
    }
    WeaponDataBuilder &setCritDamage(float damage)
    {
        m_baseCritDamage = damage;
        return *this;
    }
    WeaponDataBuilder &setBaseCD(float cd)
    {
        m_baseCD = cd;
        return *this;
    }
    WeaponDataBuilder &setBaseDuration(float duration)
    {
        m_baseDuration = duration;
        return *this;
    }
    WeaponComponentData build() const
    {
        return {m_baseDamage, m_baseSpeed,      m_speedInterval,  m_baseRange, m_rangeInterval,
                m_baseRadius, m_baseCritChance, m_baseCritDamage, m_baseCD,    m_baseDuration};
    }

private:
    float m_baseDamage{0.f};
    float m_baseSpeed{0.f};
    float m_speedInterval{0.f};
    float m_baseRange{0.f};
    sf::Vector2f m_rangeInterval{0.f, 0.f};
    float m_baseRadius{0.f};
    float m_baseCritChance{0.f};
    float m_baseCritDamage{0.f};
    float m_baseCD{0.f};
    float m_baseDuration{0.f};
};
