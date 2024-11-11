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
	this->lastUpgrade = 0;
}

Weapon::~Weapon()
{
}

void Weapon::update(float &dt, sf::Vector2f playerPos, Game *pGame)
{
	this->getUpgrades(pGame);
	setPosition(playerPos);
	rotate(this->currentSpeed * dt);

	setPosition(getPosition());
	setRotation(getRotation());
	this->animations.update(dt);
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Rectangle::draw(target, states);
}

void Weapon::addSpeed()
{
	this->currentSpeed += this->data->speedInterval;
	std::cout << "Weapon Speed increased\n";
}

void Weapon::addRange()
{
	setScale(getScale() + this->data->rangeInterval);
	std::cout << "Weapon Range increased\n";
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
	setScale(config->spriteScale);
}

void Weapon::initAnim()
{
	this->animations.loadTexture(config->texturePath);
	this->animations.addAnim(config->animations);
}

void Weapon::getUpgrades(Game *pGame)
{
	if (this->lastUpgrade == pGame->getScore())
		return;
	this->lastUpgrade = pGame->getScore();
	if (pGame->getScore() % 2)
		addSpeed();
	if (pGame->getScore() % 3)
		addRange();
}
