#pragma once
#include "Anim.h"
#include "States.h"
#include "EntData.h"
#include <unordered_map>
#include <iostream>

class AnimComponent
{
public:
	AnimComponent(sf::Sprite &sprite);
	~AnimComponent();

	bool loadTexture(const std::string& texturePath);
	void addAnim(const EntState animState, const sf::Vector2i& frameSize,
				const sf::Vector2i& startPos, size_t frames, sf::Time frameDuration,
				bool loop);
	void addAnim(const EntState animState, AnimInfo animInfo);
	void addAnim(const std::unordered_map<int, AnimInfo> &animations);
	void playAnimation(EntState anim);
	void update(float dt);


private:
	sf::Sprite&								sprite;
	sf::Texture								animSheet;
	std::unordered_map<EntState, Anim>		animations;
	EntState								currentAnimation;
};
