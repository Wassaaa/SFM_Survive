#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(VisualComponent &visual) : m_visual(visual)
{}

void AnimationComponent::addAnimation(EntityState state, const AnimationInfo& animInfo)
{
	animations.try_emplace(state, animInfo.frameDuration, animInfo.loop);
	for (size_t i = 0; i < animInfo.frameCount; i++)
	{
		sf::IntRect frame(
			animInfo.startPos.x + i * animInfo.frameSize.x,
			animInfo.startPos.y * animInfo.frameSize.y,
			animInfo.frameSize.x,
			animInfo.frameSize.y);
		animations[state].addFrame(frame);
	}
	if (currentAnimation == EntityState::NOTHING)
	{
		currentAnimation = state;
		m_visual.setTextureRect(animations[state].getCurrentFrame());
	}

}

void AnimationComponent::playAnimation(EntityState anim)
{
	if (currentAnimation != anim)
	{
		if (this->currentAnimation != anim)
		{
			animations[this->currentAnimation].stop();
			this->currentAnimation = anim;
		}
		animations[anim].play();
		m_visual.setTextureRect(animations[anim].getCurrentFrame());
	}
}

void AnimationComponent::update(float dt)
{
	if (currentAnimation != EntityState::NOTHING)
	{
		if (animations[currentAnimation].update(dt))
		{
			m_visual.setTextureRect(animations[currentAnimation].getCurrentFrame());
		}
	}
}
