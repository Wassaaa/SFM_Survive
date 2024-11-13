#pragma once

enum class GameState
{
	WAITING,
	ACTIVE,
};

enum EntityState
{
	NOTHING = -1,
	IDLE,
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT,
	WEAPON_1
};

enum class EntityType
{
	PLAYER,
	LASER_WEAPON,
	EXPLOSION_WEAPON,
	CONE_WEAPON,
	VAMPIRE
};
