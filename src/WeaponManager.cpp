#include "WeaponManager.h"

void WeaponManager::loadWeaponData() {
	// LASER - Circles around player, grows in length and speed
	{
		WeaponData& laser = weaponData[EntityType::LASER_WEAPON];
		laser.baseDamage = 8.f;
		laser.baseSpeed = 100.f;
		laser.speedInterval = 5.f;
		laser.baseRange = 95.f;
		laser.rangeInterval = {.1f, 0.f};
		laser.baseRadius = 5.f;
		laser.baseCritChance = 0.05f;
		laser.baseCritDamage = 1.5f;
		laser.baseCD = 0.f;
		laser.baseDuration = 0.2f;
	}

	// EXPLOSIONS - Random explosions around player in a radius
	{
		WeaponData& explosion = weaponData[EntityType::EXPLOSION_WEAPON];
		explosion.baseDamage = 25.f;
		explosion.baseSpeed = 1.2f;
		explosion.baseRange = 250.f;
		explosion.baseRadius = 60.f;
		explosion.baseCritChance = 0.1f;
		explosion.baseCritDamage = 2.f;
		explosion.baseCD = 0.5f;
		explosion.baseDuration = 0.4f;
	}

	// CONE_CLEAVE - Medium speed, medium damage, short range, wide area
	{
		WeaponData& cone = weaponData[EntityType::CONE_WEAPON];
		cone.baseDamage = 15.f;
		cone.baseSpeed = 0.8f;
		cone.baseRange = 150.f;
		cone.baseRadius = 45.f;
		cone.baseCritChance = 0.08f;
		cone.baseCritDamage = 1.75f;
		cone.baseCD = 0.2f;
		cone.baseDuration = 0.3f;
	}
}

const WeaponData &WeaponManager::getWeaponData(EntityType type) const
{
	return this->weaponData.at(type);
}
