#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Game.h"
#include "InputHandler.h"
#include "Types.h"
#include "Components/ComponentContainer.h"
#include "EntityManager.h"


class Player : public ComponentContainer
{
public:
	Player(Game *pGame);
	~Player() = default;

	void update(float &dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void reset();

	//movement
	void updateDrag();
	void move(const InputData& inputData);
	EntityState determineState();

	//weapons
	void addWeapon(EntityType weaponType);
	std::vector<std::unique_ptr<Weapon>> &getWeapon() { return weapons; }

	//states
	const bool isDead() const { return m_isDead; }
	void setIsDead(bool isDead) { m_isDead = isDead; }

	// Position/Transform getters
	sf::Vector2f getPosition() const;
	sf::Vector2f getCenter() const;


private:
	//init functions
	void initVariables();
	void initComponents();

	//update functions
	void updateAnimation(float &dt);

	Game* m_pGame;
	std::vector<std::unique_ptr<Weapon>> weapons;
	bool m_isDead{false};
	EntityState currentState{EntityState::IDLE};
	sf::Vector2f velocity{0.f, 0.f};

	//physics
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
};
