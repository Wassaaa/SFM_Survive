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


// #include "AnimComponent.h"
// #include "ResourceManager.h"

// AnimComponent::AnimComponent(sf::Sprite &sprite) : sprite(sprite)
// {
// 	this->currentAnimation = EntityState::NOTHING;
// }

// AnimComponent::~AnimComponent()
// {
// }

// bool AnimComponent::loadTexture(const std::string &fileName)
// {
// 	if (this->animSheet.loadFromFile(ResourceManager::getFilePath(fileName)))
// 	{
// 		this->sprite.setTexture(this->animSheet);
// 		std::cout << "Texture loaded and set to sprite\n";
// 		return true;
// 	}
// 	return false;
// }

// void AnimComponent::addAnim(
// 	const EntityState animState,
// 	const sf::Vector2i &frameSize,
// 	const sf::Vector2i &startPos,
// 	size_t frameCount,
// 	sf::Time frameDuration,
// 	bool loop = true
// 	)
// {
// 	animations.try_emplace(animState, frameDuration, loop);
// 	for (size_t i = 0; i < frameCount; i++)
// 	{
// 		sf::IntRect frame(
// 			startPos.x + i * frameSize.x,
// 			startPos.y * frameSize.y,
// 			frameSize.x,
// 			frameSize.y);
// 		animations[animState].addFrame(frame);
// 	}
// 	if (currentAnimation == EntityState::NOTHING)
// 	{
// 		currentAnimation = animState;
// 		sprite.setTextureRect(animations[animState].getCurrentFrame());
// 	}
// }

// void AnimComponent::addAnim(const EntityState animState, AnimInfo animInfo)
// {
// 	this->addAnim(
// 		animState,
// 		animInfo.frameSize,
// 		animInfo.startPos,
// 		animInfo.frameCount,
// 		animInfo.frameDuration,
// 		animInfo.loop
// 		);
// }

// void AnimComponent::addAnim(const std::unordered_map<int, AnimInfo> &animations)
// {
// 	for (auto& [state, animData] : animations)
// 	{
// 		this->addAnim(static_cast<EntityState>(state), animData);
// 	}
// }

// void AnimComponent::playAnimation(EntityState anim)
// {
// 	if (this->currentAnimation != anim)
// 	{
// 		animations[this->currentAnimation].stop();
// 		this->currentAnimation = anim;
// 	}
// 	animations[anim].play();
// 	sprite.setTextureRect(animations[anim].getCurrentFrame());
// }

// void AnimComponent::update(float dt)
// {
// 	if (currentAnimation)
// 	{
// 		if (animations[currentAnimation].update(dt))
// 		{
// 			sprite.setTextureRect(animations[currentAnimation].getCurrentFrame());
// 		}
// 	}
// }
