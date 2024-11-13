#pragma once
#include "GameConfig.h"

class EntityConfigBuilder {
public:
	EntityConfigBuilder& setVisual(const VisualComponentData& visual) {
		m_visual = visual;
		return *this;
	}

	EntityConfigBuilder& setCollision(const CollisionComponentData& collision) {
		m_collision = collision;
		return *this;
	}

	EntityConfigBuilder& addAnimation(EntityState state, const AnimationInfo& info) {
		m_animations[state] = info;
		return *this;
	}

	EntityConfigBuilder& setWeapon(const WeaponComponentData& weapon) {
		m_weapon = weapon;
		return *this;
	}

	EntityConfig build() const {
		return {m_visual, m_collision, m_animations, m_weapon};
	}

private:
	VisualComponentData m_visual{"", {1.f, 1.f}, {0.f, 0.f}, {0.f, 0.f}, 0.f};
	CollisionComponentData m_collision{{0.f, 0.f}, {1.f, 1.f}, {0.f, 0.f}, {0.f, 0.f}, 0.f, {255, 0, 0, 128}};
	std::unordered_map<EntityState, AnimationInfo> m_animations;
	std::optional<WeaponComponentData> m_weapon;
};
