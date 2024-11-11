#include "EntManager.h"

void EntityManager::loadEntityData()
{
	// Player configuration
	{
		EntityData& player = entityData[EntityType::PLAYER];
		player.texturePath = "soldier.png";
		player.frameSize = {100.f, 100.f};
		player.spriteScale = {3.f, 3.f};
		player.spriteOrigin = {50.f, 50.f};
		player.spriteRotation = 0.f;
		player.spriteOffset = {0.f, 0.f};
		player.hitboxSize = {50.f, 55.f};
		player.hitboxScale = {1.f, 1.f};
		player.hitboxOrigin = {25.f, 30.f};
		player.hitboxOffset = {0.f, 0.f};
		player.debugColor = sf::Color(0, 255, 0, 128);

		player.animations[EntState::IDLE] =
		{
			"soldier.png",
			{100, 100},		//frameSize
			{0, 0},			//startPos
			6,				//frameCount
			sf::milliseconds(100),
			true
		};
		player.animations[EntState::RIGHT] =
		{
			"soldier.png",
			{100, 100},		//frameSize
			{0, 1},			//startPos
			8,				//frameCount
			sf::milliseconds(100),
			true
		};
		player.animations[EntState::LEFT] = player.animations[EntState::RIGHT];
		player.animations[EntState::UP] = player.animations[EntState::RIGHT];
		player.animations[EntState::DOWN] = player.animations[EntState::RIGHT];
	}

	// Laser weapon configuration
	{
		EntityData& laser = entityData[EntityType::LASER_WEAPON];
		laser.texturePath = "waveform2.png";
		laser.frameSize = {95.f, 32.f};
		laser.spriteScale = {1.0f, 1.0f};
		laser.spriteOrigin = {0.f, 15.f};
		laser.spriteOffset = {0.f, 0.f};
		laser.hitboxSize = {95.f, 32.f};
		laser.hitboxOrigin = {0.f, 15.f};
		laser.hitboxOffset = {0.f, 0.f};
		laser.hitboxRotation = 0.f;
		laser.debugColor = sf::Color(255, 0, 0, 128);
		laser.animations[EntState::WEAPON_1] =
		{
			"waveform2.png",
			{95, 32},		//frameSize
			{0, 0},			//startPos
			1,				//frameCount
			sf::milliseconds(100),
			true
		};
	}
}

const EntityData& EntityManager::getEntityData(EntityType type) const
{
	return entityData.at(type);
}
