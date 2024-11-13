#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>

#include "../Anim.h"
#include "../Types.h"
#include "../GameConfig.h"
#include "Component.h"
#include "VisualComponent.h"

class AnimationComponent : public Component
{
public:
	AnimationComponent(VisualComponent &visual);
	~AnimationComponent() = default;

	void addAnimation(EntityState state, const AnimationInfo& animInfo);
	void playAnimation(EntityState anim);
	void update(float dt);

	// inline getters
	EntityState getCurrentAnimation() const { return currentAnimation; }
	const std::unordered_map<EntityState, Anim>& getAnimations() const { return animations; }
	virtual const char* getName() const override { return "AnimationComponent"; }


private:
	VisualComponent &m_visual;
	std::unordered_map<EntityState, Anim> animations;
	EntityState currentAnimation{EntityState::NOTHING};
};

struct AnimationData : public Component
{
	std::unordered_map<EntityState, AnimationInfo> animations;

	void addAnimation(EntityState state, const AnimationInfo& info)
	{
		animations.try_emplace(state, info);
	}
	virtual const char* getName() const override { return "AnimationData"; }
};
