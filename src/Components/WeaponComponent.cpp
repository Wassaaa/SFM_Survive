#include "WeaponComponent.h"

WeaponComponent::WeaponComponent(const WeaponComponentData& data) :
	m_data(data),
	currentDamage(data.baseDamage),
	currentSpeed(data.baseSpeed),
	currentCritChance(data.baseCritChance),
	currentCritDamage(data.baseCritDamage),
	currentRange(data.baseRange)
{}

void WeaponComponent::update(float dt) {
	currentRotation += currentSpeed * dt;
}

void WeaponComponent::addSpeed() {
	currentSpeed += m_data.speedInterval;
}

void WeaponComponent::addRange() {
	currentRange += m_data.rangeInterval.x;
}
