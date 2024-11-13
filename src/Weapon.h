#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.h"
#include "Rectangle.h"
#include "Components/AnimationComponent.h"
#include "WeaponManager.h"
#include "EntityManager.h"
#include "WeaponData.h"
#include "EntityData.h"



class Weapon : public Rectangle
{
public:
	Weapon(EntityType type);
	~Weapon();

	void update(float& dt, sf::Vector2f playerPos, Game *pGame);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters
	float getDamage() const { return this->currentDamage; }
	float getAttackSpeed() const { return this->currentSpeed; }
	float getCritChance() const { return this->currentCritChance; }
	float getCritDamage() const { return this->currentCritDamage; }
	float getCurrentRange() const { return this->currentRange; }
	const EntityType getType() const { return this->type; }

	void addSpeed();
	void addRange();
	void initStats();
	void initSprite();
	void initAnim();

private:
	const EntityType type;
	const WeaponData *data;
	const EntityData *config;
	AnimationComponent animations;

	void getUpgrades(Game *pGame);
	int lastUpgrade;

	// Base stats
	float currentDamage;
	float currentSpeed;
	float currentCritChance;
	float currentCritDamage;
	float currentRange;
};
