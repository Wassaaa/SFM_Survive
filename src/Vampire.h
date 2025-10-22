#pragma once
#include "Components/ComponentContainer.h"
#include "Types.h"
#include "Player.h"

class Game;
class Player;

class Vampire : public ComponentContainer
{
public:
    Vampire(Game *game, sf::Vector2f position);
    ~Vampire() = default;

    void update(float deltaTime);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void setIsKilled(bool isKilled)
    {
        m_isKilled = isKilled;
    }
    bool isKilled() const
    {
        return m_isKilled;
    }

private:
    void initComponents();

    Game *m_pGame;
    bool m_isKilled{false};
};
