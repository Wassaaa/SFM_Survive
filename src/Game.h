#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <unordered_set>
#include "Constants.h"
#include "Types.h"

class Player;
class Game;
class GameInput;
class Vampire;

namespace sf {
    class Clock;
}

class Game : public sf::Drawable
{
public:
    Game();
    ~Game();

    bool initialise();
    void update(float deltaTime);
    void resetLevel();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    GameState getState() const
    {
        return m_state;
    }

    void onKeyPressed(sf::Keyboard::Key key);
    void onKeyReleased(sf::Keyboard::Key key);

    Player *getPlayer() const;
    const int getScore() const
    {
        return this->score;
    }

    void vampireSpawner(float deltaTime);
    void addKill();
    void markVampireForDeletion(Vampire *vampire);

private:
    void processDeletions();

    std::unique_ptr<Player> m_pPlayer;

    std::vector<std::unique_ptr<Vampire>> m_pVampires;
    std::unordered_set<Vampire *> m_vampiresToDelete;

    GameState m_state;
    std::unique_ptr<sf::Clock> m_pClock;
    std::unique_ptr<GameInput> m_pGameInput;

    float m_vampireCooldown = 0.0f;
    float m_nextVampireCooldown = 2.0f;
    int m_spawnCount = 0;
    int score;
    bool extraWeapon = true;
    int vampiresPerFrame = 1;

    sf::Font m_font;
};
