#include "EntityManager.h"
#include "GameConfig.h"
#include "Components/VisualComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/AnimationComponent.h"

void EntityManager::loadEntityData()
{
	for (const auto& [type, config] : Config::ENTITY_CONFIGS)
	{
		EntityData& entity = entityData[type];
		entity.addComponent<VisualComponent>(config.visual);
		entity.addComponent<CollisionComponent>(config.collision);
		auto &animComp = entity.addComponent<AnimationComponent>(*entity.getComponent<VisualComponent>());
		for (const auto& [state, info] : config.animations) {
			animComp.addAnimation(state, info);
		}
	}
}

const EntityData& EntityManager::getEntityData(EntityType type) const
{
	return entityData.at(type);
}
