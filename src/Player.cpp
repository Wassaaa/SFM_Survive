#include "Player.h"

Player::Player(Game *pGame) :
	Rectangle(EntityManager::getInstance().getEntityData(EntityType::PLAYER).hitboxSize),
	config(&EntityManager::getInstance().getEntityData(EntityType::PLAYER)),
	animations(m_sprite)
{
	this->initVariables();
	this->initSprite();
	this->initAnim();
	this->initPhysics();
}

Player::~Player()
{
}

bool Player::initialise()
{
	this->initVariables();
	this->initSprite();
	this->initPhysics();
	this->currentState = EntState::IDLE;
	return true;
}

void Player::update(float &dt)
{
	this->updateMovement();
	this->updatePhysics();
	this->updateSprite();
	this->updateAnim(dt);
	for (auto &weapon : this->weapons)
	{
		weapon.update(dt, this->getPosition());
	}
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Rectangle::draw(target, states);
	//temp
	weapons.at(0).draw(target, states);
}

void Player::updateMovement()
{
	EntState newState = this->determineState();
	this->updateSpriteFacing();
	if (newState != currentState)
	{
		currentState = newState;
		switch (currentState)
		{
		case EntState::IDLE:
			animations.playAnimation(EntState::IDLE);
			break;
		case EntState::UP:
			animations.playAnimation(EntState::UP);
			break;
		case EntState::RIGHT:
			animations.playAnimation(EntState::RIGHT);
			break;
		case EntState::DOWN:
			animations.playAnimation(EntState::DOWN);
			break;
		case EntState::LEFT:
			animations.playAnimation(EntState::LEFT);
			break;

		default:
			break;
		}
	}
}

void Player::updateAnim(float &dt)
{
	animations.update(dt);
}

void Player::updateSprite()
{
	m_sprite.setPosition(getPosition() + config->spriteOffset);
	m_sprite.setRotation(getRotation() + config->spriteRotation);
}

void Player::updatePhysics()
{
	// deceleration
	this->velocity *= this->drag;
	// limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;
	sf::Transformable::move(this->velocity);

	setPosition(
		std::clamp(getPosition().x, 0.0f, (float)ScreenWidth),
		std::clamp(getPosition().y, 0.0f, (float)ScreenHeight)
	);
}

void Player::move(const float dir_x, const float dir_y)
{
	// acceleration
	this->velocity.x += dir_x * this->acceleration;
	this->velocity.y += dir_y * this->acceleration;
	// limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ?
				-1.f : 1.f);
	if (std::abs(this->velocity.y) > this->velocityMax)
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0) ?
				-1.f : 1.f);
}

void Player::move(InputData inputData)
{
	float dir_x = 0.f;
	float dir_y = 0.f;

	if (inputData.m_movingLeft) dir_x -= 1.f;
	if (inputData.m_movingRight) dir_x += 1.f;
	if (inputData.m_movingUp) dir_y -= 1.f;
	if (inputData.m_movingDown) dir_y += 1.f;
	this->move(dir_x, dir_y);
}

void Player::updateSpriteFacing()
{
	// if (velocity.x > 0.f)
	// {
	// 	this->sprite.setOrigin({0, 0});
	// 	this->sprite.setScale(this->scale, this->scale);
	// }
	// else if (velocity.x < 0.f)
	// {
	// 	this->sprite.setOrigin({this->sprite.getGlobalBounds().width / this->scale, 0});
	// 	this->sprite.setScale(-this->scale, this->scale);
	// }
}

EntState Player::determineState()
{
	if (this->velocity.y < 0.f)
		return EntState::UP;
	if (this->velocity.y > 0.f)
		return EntState::DOWN;
	if (this->velocity.x > 0.f)
		return EntState::RIGHT;
	if (this->velocity.x < 0.f)
		return EntState::LEFT;
	return EntState::IDLE;
}

void Player::addWeapon(EntityType type)
{
	this->weapons.emplace_back(type);
}

void Player::initVariables()
{
	setOrigin(this->config->hitboxOrigin);
	setScale(this->config->hitboxScale);
	setPosition(ScreenWidth / 2, ScreenHeight / 2);
	setRotation(this->config->hitboxRotation);
	setIsDead(false);
	this->currentState = EntState::NOTHING;
	setDebugColor(this->config->debugColor);
}

void Player::initSprite()
{
	this->m_sprite.setScale(this->config->spriteScale);
	this->m_sprite.setOrigin(this->config->spriteOrigin);
	this->m_sprite.setRotation(this->config->spriteRotation);
	this->m_sprite.setPosition(getPosition());
}

void Player::initAnim()
{
	if (!animations.loadTexture(this->config->texturePath))
		std::cout << "ERROR::PLAYER::INIT_ANIM::LOAD_TEXTURE\n";
	animations.addAnim(this->config->animations);
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = .1f;
	this->acceleration = 1.f;
	this->drag = 0.72f;
	this->velocity = {0.f, 0.f};
}
