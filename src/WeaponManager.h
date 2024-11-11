#pragma once
#include <unordered_map>
#include <memory>
#include "WeaponData.h"
#include "EntData.h"

class WeaponManager {

private:
	std::unordered_map<EntityType, WeaponData> weaponData;
	WeaponManager() {this->loadWeaponData();}

public:
	static WeaponManager &getInstance(){
		static WeaponManager instance;
		return instance;
	}

	void loadWeaponData();
	const WeaponData& getWeaponData(EntityType type) const;

	WeaponManager(const WeaponManager&) = delete;
	WeaponManager& operator=(const WeaponManager&) = delete;
};
