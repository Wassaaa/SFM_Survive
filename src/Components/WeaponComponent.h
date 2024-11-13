#pragma once
#include "Component.h"
#include "../Config/GameConfig.h"

class WeaponComponent : public Component
{
public:
	WeaponComponent(const WeaponComponentData& data);
	~WeaponComponent() = default;

	void update(float dt);
	virtual const char* getName() const override { return "WeaponComponent"; }

	// Getters
	float getDamage() const { return currentDamage; }
	float getSpeed() const { return currentSpeed; }
	float getCritChance() const { return currentCritChance; }
	float getCritDamage() const { return currentCritDamage; }
	float getRange() const { return currentRange; }
	float getRotation() const { return currentRotation; }

	// Upgrade methods
	void addSpeed();
	void addRange();

private:
	const WeaponComponentData& m_data;

	float currentDamage;
	float currentSpeed;
	float currentCritChance;
	float currentCritDamage;
	float currentRange;
	float currentRotation{0.f};
};
