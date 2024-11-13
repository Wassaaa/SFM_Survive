#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(const CollisionComponentData& data) : m_data(data)
{
	initShape();
	applyTransforms();
}

void CollisionComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_debugDraw)
	{
		states.transform *= getTransform();
		target.draw(m_shape, states);
	}
}

void CollisionComponent::initShape()
{
	m_shape.setSize(m_data.size);
	m_shape.setFillColor(sf::Color(m_data.debugColor.r,
									m_data.debugColor.g,
									m_data.debugColor.b,
									m_data.debugColor.a / 2));
	m_shape.setOutlineColor(m_data.debugColor);
	m_shape.setOutlineThickness(1.0f);
}

void CollisionComponent::applyTransforms()
{
	setScale(m_data.scale);
	setOrigin(m_data.origin);
	setPosition(m_data.offset);
	setRotation(m_data.rotation);
}

bool CollisionComponent::intersects(const CollisionComponent& other) const
{
	sf::Transform thisTransform = getTransform();
	sf::Transform otherTransform = other.getTransform();

	sf::FloatRect thisBounds = thisTransform.transformRect(m_shape.getLocalBounds());
	sf::FloatRect otherBounds = otherTransform.transformRect(other.m_shape.getLocalBounds());

	return thisBounds.intersects(otherBounds);
}

sf::FloatRect CollisionComponent::getBounds() const
{
	return getTransform().transformRect(m_shape.getLocalBounds());
}
