#pragma once

#include <SFML/Graphics.hpp>

class Anim
{
public:
    Anim();
    Anim(sf::Time frameDuration, bool loop = true);
    ~Anim();

    // functions
    void addFrame(const sf::IntRect &frame);
    bool update(float dt);

    // setters
    void play()
    {
        this->animPlaying = true;
    }
    void pause()
    {
        this->animPlaying = false;
    }
    void stop()
    {
        this->animPlaying = false;
        currentFrame = 0;
        currentTime = sf::Time::Zero;
    }

    // getters
    const sf::IntRect getCurrentFrame() const
    {
        return frames[currentFrame];
    }
    const bool isLooping() const
    {
        return animLooping;
    }
    const bool isPlaying() const
    {
        return animPlaying;
    }

private:
    std::vector<sf::IntRect> frames;
    sf::Time frameDuration;
    sf::Time currentTime;
    size_t currentFrame;
    bool animLooping;
    bool animPlaying;
};
