#pragma once

#include "Game.h"
#include "InputHandler.h"
#include "AnimComponent.h"
#include "EntManager.h"
#include "States.h"
#include "EntData.h"
#include "Rectangle.h"
#include "Weapon.h"

class Player : public Rectangle
{
public:
	Player(Game *pGame);
	~Player();

	bool initialise();

	//functions
	void update(float &dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void updatePhysics();
	void updateMovement();
	void updateAnim(float &dt);
	void updateSprite();
	//movement
	void move(const float dir_x, const float dir_y);
	void move(InputData inputData);
	EntState determineState();
	//weapons
	void addWeapon(EntityType type);
	//getters
	const bool isDead() const { return m_isDead; }
	std::vector<std::unique_ptr<Weapon>> &getWeapon() { return weapons; }

	//setters
	void setIsDead(bool isDead) { m_isDead = isDead; }

private:
	sf::Texture textureSheet;
	AnimComponent animations;
	const EntityData *config;
	Game* m_pGame;

	//weapons
	// std::vector<Weapon> weapons;
	std::vector<std::unique_ptr<Weapon>> weapons;

	//variables
	sf::Vector2f playerOrigin;


	//vars
	float scale;
	bool m_isDead;

	//Movement
	EntState currentState;
	//Animation

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;


	void initVariables();
	void initSprite();
	void initAnim();
	void initPhysics();

};
