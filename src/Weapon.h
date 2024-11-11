#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Rectangle.h"
#include "AnimComponent.h"
#include "WeaponManager.h"
#include "EntManager.h"
#include "WeaponData.h"
#include "EntData.h"



class Weapon : public Rectangle
{
public:
	Weapon(EntityType type);
	~Weapon();

	void update(float& dt, sf::Vector2f playerPos);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters
	float getDamage() const { return this->currentDamage; }
	float getAttackSpeed() const { return this->currentSpeed; }
	float getCritChance() const { return this->currentCritChance; }
	float getCritDamage() const { return this->currentCritDamage; }
	float getCurrentRange() const { return this->currentRange; }

	void initStats();
	void initSprite();
	void initAnim();

private:
	const EntityType type;
	const WeaponData *data;
	const EntityData *config;
	AnimComponent animations;

	// Base stats
	float currentDamage;
	float currentSpeed;
	float currentCritChance;
	float currentCritDamage;
	float currentRange;
};
