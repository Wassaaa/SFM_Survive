#include "Weapon.h"

Weapon::Weapon(EntityType type):
	Rectangle(EntityManager::getInstance().getEntityData(type).hitboxSize),
	type(type),
	data(&WeaponManager::getInstance().getWeaponData(type)),
	config(&EntityManager::getInstance().getEntityData(type)),
	animations(m_sprite)
{
	this->initSprite();
	this->initAnim();
	this->initStats();
}

Weapon::~Weapon()
{
}

void Weapon::update(float &dt, sf::Vector2f playerPos)
{
	setPosition(playerPos + this->config->hitboxOffset);
	//temp
	rotate(100.f * dt);

	setPosition(getPosition());
	setRotation(getRotation());
	// m_sprite.setPosition(getPosition());
	// m_sprite.setRotation(getRotation());
	this->animations.update(dt);
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Rectangle::draw(target, states);
}

void Weapon::initStats()
{
	this->currentDamage = data->baseDamage;
	this->currentSpeed = data->baseSpeed;
	this->currentCritChance = data->baseCritChance;
	this->currentCritDamage = data->baseCritDamage;
	this->currentRange = data->baseRange;
}

void Weapon::initSprite()
{
	setOrigin(config->spriteOrigin);
	setRotation(config->hitboxRotation);
	m_sprite.setOrigin(config->spriteOrigin);
	m_sprite.setRotation(config->spriteRotation);
}

void Weapon::initAnim()
{
	this->animations.loadTexture(config->texturePath);
	this->animations.addAnim(config->animations);
}
