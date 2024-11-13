#include "Anim.h"

Anim::Anim() :
	frameDuration(sf::Time::Zero),
	currentTime(sf::Time::Zero),
	currentFrame(0),
	animLooping(true),
	animPlaying(false)
{
}

Anim::Anim(sf::Time frameDuration, bool loop) :
	frameDuration(frameDuration),
	currentTime(sf::Time::Zero),
	currentFrame(0),
	animLooping(loop),
	animPlaying(false)
{
}

Anim::~Anim()
{
}

void Anim::addFrame(const sf::IntRect &frame)
{
	frames.emplace_back(frame);
}

bool Anim::update(float dt)
{
	if (!animPlaying)
	{
		return (false);
	}
	currentTime += sf::seconds(dt);
	if (currentTime >= frameDuration)
	{
		currentTime = sf::Time::Zero;
		if (currentFrame + 1 < frames.size())
		{
			++currentFrame;
			return (true);
		}
		else if (animLooping)
		{
			currentFrame = 0;
			return (true);
		}
		else
		{
			animPlaying = false;
			return (false);
		}
	}
	return (false);
}
