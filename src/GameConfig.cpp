#include "GameConfig.h"

namespace Config {
	// Player Configuration
	const EntityConfig PLAYER = {
		// Visual Component
		{
			"soldier.png",         // filename
			{100.f, 100.f},       // frameSize
			{3.f, 3.f},           // scale
			{50.f, 50.f},         // origin
			{0.f, 0.f},           // offset
			0.f                    // rotation
		},
		// Collision Component
		{
			{50.f, 55.f},         // size
			{1.f, 1.f},           // scale
			{25.f, 30.f},         // origin
			{0.f, 0.f},           // offset
			0.f,                   // rotation
			{0, 255, 0, 128}      // debugColor
		},
		// Animations
		{
			{EntityState::IDLE, {
				"soldier.png",
				{100, 100},
				{0, 0},
				6,
				sf::milliseconds(100),
				true
			}},
			{EntityState::MOVE_RIGHT, {
				"soldier.png",
				{100, 100},
				{0, 0},
				6,
				sf::milliseconds(100),
				true
			}}
		}
	};

	// Weapon Configurations
	const EntityConfig LASER_WEAPON = {
		// Visual Component
		{
			"waveform2.png",
			{95.f, 32.f},
			{1.0f, 1.0f},
			{0.f, 15.f},
			{0.f, 0.f},
			0.f
		},
		// Collision Component
		{
			{95.f, 32.f},
			{1.f, 1.f},
			{0.f, 15.f},
			{0.f, 0.f},
			0.f,
			{255, 0, 0, 128}
		},
		// Animations
		{
			{EntityState::WEAPON_1, {
				"waveform2.png",
				{95, 32},
				{0, 0},
				1,
				sf::milliseconds(100),
				true
			}}
		}
	};

	// Map to access configurations
	const std::unordered_map<EntityType, const EntityConfig&> ENTITY_CONFIGS = {
		{EntityType::PLAYER, PLAYER},
		{EntityType::LASER_WEAPON, LASER_WEAPON}
	};
}
