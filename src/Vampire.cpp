#include "Vampire.h"
#include "Game.h"
#include "EntityManager.h"
#include "Components/VisualComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/AnimationComponent.h"
#include "MathUtils.h"

Vampire::Vampire(Game* game, sf::Vector2f position) : m_pGame(game) {
	initComponents();

	if (auto* visual = getComponent<VisualComponent>()) {
		visual->setPosition(position);
	}
	if (auto* collision = getComponent<CollisionComponent>()) {
		collision->setPosition(position);
	}
}

void Vampire::initComponents() {
	const EntityData& entityData = EntityManager::getInstance().getEntityData(EntityType::VAMPIRE);

	if (auto* visual = entityData.getComponent<VisualComponent>())
		addComponent<VisualComponent>(*visual);
	if (auto* collision = entityData.getComponent<CollisionComponent>())
		addComponent<CollisionComponent>(*collision);
	if (auto* animData = entityData.getComponent<AnimationData>()) {
		auto& animComp = addComponent<AnimationComponent>(*getComponent<VisualComponent>());
		for (const auto& [state, info] : animData->animations) {
			animComp.addAnimation(state, info);
		}
	}
}

void Vampire::update(float deltaTime) {
	if (m_isKilled) return;

	Player* pPlayer = m_pGame->getPlayer();

	// Check weapon collisions
	for (auto& weapon : pPlayer->getWeapon()) {
		if (getComponent<CollisionComponent>()->intersects(*weapon->getComponent<CollisionComponent>())) {
			setIsKilled(true);
			m_pGame->addKill();
			return;
		}
	}

	// Check player collision
	if (getComponent<CollisionComponent>()->intersects(*pPlayer->getComponent<CollisionComponent>())) {
		pPlayer->setIsDead(true);
	}

	// Move towards player
	sf::Vector2f playerCenter = pPlayer->getComponent<VisualComponent>()->getPosition();
	sf::Vector2f vampirePos = getComponent<VisualComponent>()->getPosition();
	sf::Vector2f direction = VecNormalized(playerCenter - vampirePos);
	direction *= Constants::VAMPIRE_SPEED * deltaTime;

	getComponent<VisualComponent>()->move(direction);
	getComponent<CollisionComponent>()->move(direction);
}

void Vampire::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (auto* visual = getComponent<VisualComponent>())
		visual->draw(target, states);
	if (auto* collision = getComponent<CollisionComponent>())
		collision->draw(target, states);
}
