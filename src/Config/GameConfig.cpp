#include "GameConfig.h"
#include "ComponentDataBuilder.h"
#include "EntityConfigBuilder.h"

namespace Config
{
	const EntityConfig PLAYER = EntityConfigBuilder()
		.setVisual(VisualDataBuilder()
			.setFilename("soldier.png")
			.setScale({3.f, 3.f})
			.setOrigin({50.f, 50.f})
			.build())
		.setCollision(CollisionDataBuilder()
			.setSize({50.f, 55.f})
			.setScale({1.f, 1.f})
			.setOrigin({25.f, 30.f})
			.setDebugColor({0, 255, 0, 128})
			.build())
		.addAnimation(EntityState::IDLE, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 0})
			.setFrameCount(6)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.addAnimation(EntityState::MOVE_RIGHT, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 1})
			.setFrameCount(8)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.addAnimation(EntityState::MOVE_LEFT, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 1})
			.setFrameCount(8)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.addAnimation(EntityState::MOVE_UP, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 1})
			.setFrameCount(8)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.addAnimation(EntityState::MOVE_DOWN, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 1})
			.setFrameCount(8)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.addAnimation(EntityState::WEAPON_1, AnimationInfoBuilder()
			.setFrameSize({100, 100})
			.setStartPos({0, 5})
			.setLoop(false)
			.setFrameDuration(sf::milliseconds(100))
			.setFrameCount(4)
			.build())
		.build();

	const EntityConfig LASER_WEAPON = EntityConfigBuilder()
		.setVisual(VisualDataBuilder()
			.setFilename("waveform2.png")
			.setScale({1.0f, 1.0f})
			.setOrigin({0.f, 15.f})
			.build())
		.setCollision(CollisionDataBuilder()
			.setSize({95.f, 32.f})
			.setScale({1.f, 1.f})
			.setOrigin({0.f, 15.f})
			.setDebugColor({255, 0, 0, 128})
			.build())
		.addAnimation(EntityState::WEAPON_1, AnimationInfoBuilder()
			.setFrameSize({95, 32})
			.setStartPos({0, 0})
			.setFrameCount(1)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.setWeapon(WeaponDataBuilder()
			.setBaseDamage(8.f)
			.setBaseSpeed(100.f)
			.setSpeedInterval(5.f)
			.setBaseRange(95.f)
			.setRangeInterval({0.1f, 0.f})
			.setBaseRadius(5.f)
			.setCritChance(0.05f)
			.setCritDamage(1.5f)
			.setBaseCD(0.f)
			.setBaseDuration(0.2f)
			.build())
		.build();

	const EntityConfig VAMPIRE = EntityConfigBuilder()
		.setVisual(VisualDataBuilder()
			.setFilename("vampire.png")
			.setScale({2.f, 2.f})
			.setOrigin({8.f, 8.f})
			.build())
		.setCollision(CollisionDataBuilder()
			.setSize({16.f, 16.f})
			.setScale({2.f, 2.f})
			.setOrigin({8.f, 8.f})
			.setDebugColor({255, 0, 0, 128})
			.build())
		.addAnimation(EntityState::IDLE, AnimationInfoBuilder()
			.setFrameSize({16, 16})
			.setStartPos({0, 0})
			.setFrameCount(1)
			.setFrameDuration(sf::milliseconds(100))
			.setLoop(true)
			.build())
		.build();

	const std::unordered_map<EntityType, const EntityConfig&> ENTITY_CONFIGS = {
		{EntityType::PLAYER, PLAYER},
		{EntityType::LASER_WEAPON, LASER_WEAPON},
		{EntityType::VAMPIRE, VAMPIRE}
	};
}
