#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "Component.h"
#include "../GameConfig.h"

class VisualComponent : public Component, public sf::Drawable, public sf::Transformable
{
public:
	VisualComponent(const VisualComponentData& data);
	~VisualComponent() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//handle texture loading
	void loadTexture();

	//setters
	void setTextureRect(const sf::IntRect& rect) { m_sprite.setTextureRect(rect); }

	//getters
	const sf::Sprite& getSprite() const { return m_sprite; }
	virtual const char* getName() const override { return "VisualComponent"; }


private:
	//members
	sf::Sprite m_sprite;
	sf::Texture	m_texture;

	//member functions
	void applyTransforms();

	// data
	const VisualComponentData& m_data;
};
