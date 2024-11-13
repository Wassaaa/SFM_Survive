#include "Weapon.h"
#include "EntityManager.h"
#include "Components/VisualComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/AnimationComponent.h"
#include "Components/WeaponComponent.h"

Weapon::Weapon(EntityType type) : m_type(type) {
	initComponents();
}

void Weapon::initComponents() {
	const EntityData& entityData = EntityManager::getInstance().getEntityData(m_type);

	if (auto* visual = entityData.getComponent<VisualComponent>())
		addComponent<VisualComponent>(*visual);
	if (auto* collision = entityData.getComponent<CollisionComponent>())
		addComponent<CollisionComponent>(*collision);
	if (auto* weapon = entityData.getComponent<WeaponComponent>())
		addComponent<WeaponComponent>(*weapon);
	if (auto* animData = entityData.getComponent<AnimationData>())
	{
		auto& animComp = addComponent<AnimationComponent>(*getComponent<VisualComponent>());
		for (const auto& [state, info] : animData->animations)
			animComp.addAnimation(state, info);
	}
}

void Weapon::update(float dt, sf::Vector2f playerPos)
{
	if (auto weapon = getComponent<WeaponComponent>())
	{
		weapon->update(dt);
		if (auto visual = getComponent<VisualComponent>())
		{
			visual->update(dt);
			visual->setPosition(playerPos);
			visual->setRotation(weapon->getRotation());
		}
		if (auto collision = getComponent<CollisionComponent>())
		{
			collision->setPosition(playerPos);
			collision->setRotation(weapon->getRotation());
		}
	}
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (auto visual = getComponent<VisualComponent>())
		visual->draw(target, states);
	if (auto collision = getComponent<CollisionComponent>())
		collision->draw(target, states);
}

void Weapon::addSpeed()
{
	if (auto weapon = getComponent<WeaponComponent>())
		weapon->addSpeed();
}
void Weapon::addRange()
{
	if (auto weapon = getComponent<WeaponComponent>())
	weapon->addRange();
}
