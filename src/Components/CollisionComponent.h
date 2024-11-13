#pragma once
#include "Component.h"
#include "../GameConfig.h"
#include <SFML/Graphics.hpp>

class CollisionComponent : public Component, public sf::Drawable, public sf::Transformable
{
public:
	CollisionComponent(const CollisionComponentData& data);
	~CollisionComponent() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// collision detection
	bool intersects(const CollisionComponent& other) const;
	sf::FloatRect getBounds() const;

	// getters and setters
	void setDebugDraw(bool enabled) { m_debugDraw = enabled; }
	bool isDebugDrawEnabled() const { return m_debugDraw; }
	virtual const char* getName() const override { return "CollisionComponent"; }

private:
	// members
	sf::RectangleShape m_shape;
	const CollisionComponentData& m_data;
	bool m_debugDraw{false};

	// member functions
	void initShape();
	void applyTransforms();
};
