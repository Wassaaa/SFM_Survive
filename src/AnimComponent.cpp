#include "AnimComponent.h"
#include "ResourceManager.h"

AnimComponent::AnimComponent(sf::Sprite &sprite) : sprite(sprite)
{
	this->currentAnimation = EntState::NOTHING;
}

AnimComponent::~AnimComponent()
{
}

bool AnimComponent::loadTexture(const std::string &fileName)
{
	if (this->animSheet.loadFromFile(ResourceManager::getFilePath(fileName)))
	{
		this->sprite.setTexture(this->animSheet);
		std::cout << "Texture loaded and set to sprite\n";
		return true;
	}
	return false;
}

void AnimComponent::addAnim(
	const EntState animState,
	const sf::Vector2i &frameSize,
	const sf::Vector2i &startPos,
	size_t frameCount,
	sf::Time frameDuration,
	bool loop = true
	)
{
	animations.try_emplace(animState, frameDuration, loop);
	for (size_t i = 0; i < frameCount; i++)
	{
		sf::IntRect frame(
			startPos.x + i * frameSize.x,
			startPos.y * frameSize.y,
			frameSize.x,
			frameSize.y);
		animations[animState].addFrame(frame);
	}
	if (currentAnimation == EntState::NOTHING)
	{
		currentAnimation = animState;
		sprite.setTextureRect(animations[animState].getCurrentFrame());
	}
}

void AnimComponent::addAnim(const EntState animState, AnimInfo animInfo)
{
	this->addAnim(
		animState,
		animInfo.frameSize,
		animInfo.startPos,
		animInfo.frameCount,
		animInfo.frameDuration,
		animInfo.loop
		);
}

void AnimComponent::addAnim(const std::unordered_map<int, AnimInfo> &animations)
{
	for (auto& [state, animData] : animations)
	{
		this->addAnim(static_cast<EntState>(state), animData);
	}
}

void AnimComponent::playAnimation(EntState anim)
{
	if (this->currentAnimation != anim)
	{
		animations[this->currentAnimation].stop();
		this->currentAnimation = anim;
	}
	animations[anim].play();
	sprite.setTextureRect(animations[anim].getCurrentFrame());
}

void AnimComponent::update(float dt)
{
	if (currentAnimation)
	{
		if (animations[currentAnimation].update(dt))
		{
			sprite.setTextureRect(animations[currentAnimation].getCurrentFrame());
		}
	}
}
