#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include "States.h"

enum class EntityType {
	PLAYER,
	LASER_WEAPON,
	EXPLOSION_WEAPON,
	CONE_WEAPON,
	VAMPIRE
};

struct AnimInfo {
	std::string texturePath;
	sf::Vector2i frameSize;
	sf::Vector2i startPos;
	size_t frameCount;
	sf::Time frameDuration;
	bool loop;
};

struct EntityData {
	EntityData(
		const std::string& texPath = "",
		const sf::Vector2f& fSize = {0.f, 0.f},
		const sf::Vector2f& sScale = {1.f, 1.f},
		const sf::Vector2f& sOrigin = {0.f, 0.f},
		const sf::Vector2f& sOffset = {0.f, 0.f},
		float sRotation = 0.f,
		const sf::Vector2f& hSize = {0.f, 0.f},
		const sf::Vector2f& hScale = {1.f, 1.f},
		const sf::Vector2f& hOrigin = {0.f, 0.f},
		const sf::Vector2f& hOffset = {0.f, 0.f},
		float hRotation = 0.f,
		const sf::Color& dColor = sf::Color::White
	) :
		texturePath(texPath),
		frameSize(fSize),
		spriteScale(sScale),
		spriteOrigin(sOrigin),
		spriteOffset(sOffset),
		spriteRotation(sRotation),
		hitboxSize(hSize),
		hitboxScale(hScale),
		hitboxOrigin(hOrigin),
		hitboxOffset(hOffset),
		hitboxRotation(hRotation),
		debugColor(dColor)
	{}

	std::string texturePath;
	sf::Vector2f frameSize;
	sf::Vector2f spriteScale;
	sf::Vector2f spriteOrigin;
	sf::Vector2f spriteOffset;
	float spriteRotation;

	sf::Vector2f hitboxSize;
	sf::Vector2f hitboxScale;
	sf::Vector2f hitboxOrigin;
	sf::Vector2f hitboxOffset;
	float hitboxRotation;
	sf::Color debugColor;

	std::unordered_map<int, AnimInfo> animations;
};
