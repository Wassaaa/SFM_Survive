#include "GameConfig.h"

namespace Config
{
	// Player Configuration
	const EntityConfig PLAYER =
	{
		// Visual Component
		{
			"soldier.png",         // filename
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
			{
				EntityState::IDLE,
				{
					{100, 100},
					{0, 0},
					6,
					sf::milliseconds(100),
					true
				}
			},
			{
				EntityState::MOVE_RIGHT,
				{
					{100, 100},
					{0, 1},
					8,
					sf::milliseconds(100),
					true
				}
			},
			{
				EntityState::MOVE_LEFT,
				{
					{100, 100},
					{0, 1},
					8,
					sf::milliseconds(100),
					true
				}
			},
			{
				EntityState::MOVE_UP,
				{
					{100, 100},
					{0, 1},
					8,
					sf::milliseconds(100),
					true
				}
			},
			{
				EntityState::MOVE_DOWN,
				{
					{100, 100},
					{0, 1},
					8,
					sf::milliseconds(100),
					true
				}
			}
		}
	};

	const EntityConfig VAMPIRE =
	{
		// Visual Component
		{
			"vampire.png",         // filename
			{2.f, 2.f},           // scale
			{8.f, 8.f},         // origin
			{0.f, 0.f},           // offset
			0.f                    // rotation
		},
		// Collision Component
		{
			{16.f, 16.f},         // size
			{2.f, 2.f},           // scale
			{8.f, 8.f},         // origin
			{0.f, 0.f},           // offset
			0.f,                   // rotation
			{255, 0, 0, 128}      // debugColor
		},
		// Animations
		{
			{
				EntityState::IDLE,
				{
					{16, 16},
					{0, 0},
					1,
					sf::milliseconds(100),
					true
				}
			}
		}
};

	// Weapon Configurations
	const EntityConfig LASER_WEAPON =
	{
		// Visual Component
		{
			"waveform2.png",
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
			{
				EntityState::WEAPON_1,
				{
					{95, 32},
					{0, 0},
					1,
					sf::milliseconds(100),
					true
				}
			}
		},
		// Weapon Component
		std::make_optional<WeaponComponentData>(
		{
			8.f,    // baseDamage
			100.f,  // baseSpeed
			5.f,    // speedInterval
			95.f,   // baseRange
			{0.1f, 0.f}, // rangeInterval
			5.f,    // baseRadius
			0.05f,  // baseCritChance
			1.5f,   // baseCritDamage
			0.f,    // baseCD
			0.2f    // baseDuration
		}),
	};

	// Map to access configurations
	const std::unordered_map<EntityType, const EntityConfig&> ENTITY_CONFIGS = {
		{EntityType::PLAYER, PLAYER},
		{EntityType::LASER_WEAPON, LASER_WEAPON},
		{EntityType::VAMPIRE, VAMPIRE}
	};
}
