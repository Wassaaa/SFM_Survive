#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "EntData.h"
#include "States.h"

class EntityManager
{
public:
	static EntityManager& getInstance() {
		static EntityManager instance;
		return instance;
	}

	void loadEntityData();
	const EntityData& getEntityData(EntityType type) const;

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;

private:
	std::unordered_map<EntityType, EntityData> entityData;
	EntityManager() { this->loadEntityData(); }
};
