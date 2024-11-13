#include "VisualComponent.h"
#include "../ResourceManager.h"
#include <iostream>

VisualComponent::VisualComponent(const VisualComponentData &data) : m_data(data)
{
	this->loadTexture();
}

void VisualComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_sprite, states);
}

void VisualComponent::loadTexture()
{
	if (!m_data.filename.empty())
	{
		if (!m_texture.loadFromFile(ResourceManager::getFilePath(m_data.filename)))
		{
			std::cerr << "Unable to load texture, creating a bank texture" << std::endl;
			m_texture.create(1, 1);
			sf::Color color = sf::Color::White;
			sf::Uint8 whitePixel[4] = {color.r, color.g, color.b, color.a};
			m_texture.update(whitePixel);
			m_texture.setRepeated(true);
		}
		m_sprite.setTexture(m_texture);
	}
}

void VisualComponent::applyTransforms()
{
	setScale(m_data.scale);
	setOrigin(m_data.origin);
	setPosition(m_data.offset);
	setRotation(m_data.rotation);
}
