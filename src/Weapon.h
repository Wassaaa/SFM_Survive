#pragma once
#include "Components/ComponentContainer.h"
#include "Types.h"

class Game;

class Weapon : public ComponentContainer {
public:
	Weapon(EntityType type);
	~Weapon() = default;

	void update(float dt, sf::Vector2f playerPos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Upgrade methods
	void addSpeed();
	void addRange();

	EntityType getType() const { return m_type; }

private:
	void initComponents();

	const EntityType m_type;
};
