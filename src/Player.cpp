#include <array>

#include "Player.h"
#include "Game.h"
#include "Config/EntityManager.h"
#include "Components/VisualComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/AnimationComponent.h"

Player::Player(Game *pGame)
    : m_pGame(pGame)
{
    initVariables();
    initComponents();
}

void Player::initVariables()
{
    this->acceleration = Constants::PLAYER_ACCELERATION;
    this->velocityMax = Constants::PLAYER_SPEED_MAX;
    this->velocityMin = Constants::PLAYER_SPEED_MIN;
    this->drag = Constants::PLAYER_DRAG;
    this->velocity = sf::Vector2f(0, 0);
    this->m_isDead = false;
    this->currentState = EntityState::IDLE;
}

void Player::initComponents()
{
    const EntityData &entityData = EntityManager::getInstance().getEntityData(EntityType::PLAYER);

    // Add components from entity data
    if (auto *visual = entityData.getComponent<VisualComponent>())
        addComponent<VisualComponent>(*visual);
    if (auto *collision = entityData.getComponent<CollisionComponent>())
        addComponent<CollisionComponent>(*collision);
    if (auto *animData = entityData.getComponent<AnimationData>()) {
        auto &animComponent = addComponent<AnimationComponent>(*getComponent<VisualComponent>());
        // Load animations from animation data
        for (const auto &[state, info] : animData->animations)
            animComponent.addAnimation(state, info);
    }
}

void Player::reset()
{
    this->initVariables();

    // hard-code to middle for now
    if (auto *visual = getComponent<VisualComponent>())
        visual->setPosition(Constants::SCREEN_WIDTH / 2.f, Constants::SCREEN_HEIGHT / 2.f);
    if (auto *collision = getComponent<CollisionComponent>())
        collision->setPosition(Constants::SCREEN_WIDTH / 2.f, Constants::SCREEN_HEIGHT / 2.f);

    weapons.clear();
}

void Player::update(float &dt)
{
    updateDrag();
    updateAnimation(dt);

    sf::Vector2f movement = this->velocity * dt;
    if (auto *visual = getComponent<VisualComponent>()) {
        visual->move(movement);

        // Update weapons with player position
        sf::Vector2f playerPos = visual->getPosition();
        for (auto &weapon : weapons) {
            weapon->update(dt, playerPos);
        }
    }

    if (auto *collision = getComponent<CollisionComponent>()) {
        collision->move(movement);
    }
}

void Player::updateAnimation(float &dt)
{
    if (auto *anim = getComponent<AnimationComponent>()) {
        EntityState newState = determineState();
        if (newState != currentState) {
            currentState = newState;
            anim->playAnimation(currentState);
        }
        anim->update(dt);
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw visual component
    if (auto *visual = getComponent<VisualComponent>())
        target.draw(*visual, states);

    // Draw collision debug if enableds
    if (auto *collision = getComponent<CollisionComponent>()) {
        target.draw(*collision, states);
    }

    // Draw weapons
    for (const auto &weapon : weapons) {
        weapon->draw(target, states);
    }
}

void Player::updateDrag()
{
    // deceleration
    this->velocity *= this->drag;
    // set 0 if too low
    if (std::abs(this->velocity.x) < this->velocityMin)
        this->velocity.x = 0.f;
    if (std::abs(this->velocity.y) < this->velocityMin)
        this->velocity.y = 0.f;
}

void Player::move(const InputData &inputData)
{
    sf::Vector2f direction;
    if (inputData.m_movingUp)
        direction.y = -1.f;
    if (inputData.m_movingRight)
        direction.x = 1.f;
    if (inputData.m_movingDown)
        direction.y = 1.f;
    if (inputData.m_movingLeft)
        direction.x = -1.f;
    // acceleration
    this->velocity += (direction * this->acceleration);
    // limit max
    if (std::abs(this->velocity.x) > this->velocityMax)
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ? -1.f : 1.f);
    if (std::abs(this->velocity.y) > this->velocityMax)
        this->velocity.y = this->velocityMax * ((this->velocity.y < 0) ? -1.f : 1.f);
}

EntityState Player::determineState()
{
    if (this->velocity.y < 0.f)
        return EntityState::MOVE_UP;
    if (this->velocity.y > 0.f)
        return EntityState::MOVE_DOWN;
    if (this->velocity.x > 0.f)
        return EntityState::MOVE_RIGHT;
    if (this->velocity.x < 0.f)
        return EntityState::MOVE_LEFT;
    return EntityState::IDLE;
}

void Player::addWeapon(EntityType weaponType)
{
    weapons.emplace_back(std::make_unique<Weapon>(weaponType));
}
