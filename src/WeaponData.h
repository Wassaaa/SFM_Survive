#pragma once
#include <SFML/Graphics.hpp>

struct WeaponData {
	float baseDamage;

	float baseSpeed;
	float speedInterval = 5.f;

	float baseRange;
	sf::Vector2f rangeInterval = {0.f, 5.f};

	float baseRadius;
	float baseCritChance;
	float baseCritDamage;
	float baseCD;
	float baseDuration;
};
