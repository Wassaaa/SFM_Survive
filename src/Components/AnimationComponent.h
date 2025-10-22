#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>

#include "../Anim.h"
#include "../Types.h"
#include "../Config/GameConfig.h"
#include "Component.h"
#include "VisualComponent.h"

class AnimationComponent : public Component
{
public:
    AnimationComponent(VisualComponent &visual);
    ~AnimationComponent() = default;

    void addAnimation(EntityState state, const AnimationInfo &animInfo);
    void playAnimation(EntityState anim);
    void playDefaultAnimation();
    void update(float dt);

    // inline getters
    EntityState getCurrentAnimation() const
    {
        return currentAnimation;
    }
    const std::unordered_map<EntityState, Anim> &getAnimations() const
    {
        return animations;
    }
    virtual const char *getName() const override
    {
        return "AnimationComponent";
    }

private:
    void onAnimationComplete();

    VisualComponent &m_visual;
    std::unordered_map<EntityState, Anim> animations;
    std::unordered_map<EntityState, bool> animationFlipX;
    EntityState currentAnimation{EntityState::NOTHING};
    EntityState previousAnimation{EntityState::NOTHING};
    EntityState defaultAnimation{EntityState::NOTHING};
};

struct AnimationData : public Component
{
    std::unordered_map<EntityState, AnimationInfo> animations;

    void addAnimation(EntityState state, const AnimationInfo &info)
    {
        animations.try_emplace(state, info);
    }
    virtual const char *getName() const override
    {
        return "AnimationData";
    }
};
