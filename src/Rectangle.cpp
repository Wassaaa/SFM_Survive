#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "RectangularBoundaryCollision.hpp"

bool Rectangle::s_debugDraw = false;

Rectangle::Rectangle(sf::Vector2f size, sf::Vector2f position) :
    m_size(size),
    m_debugRect(size)
{
    m_debugRect.setFillColor(m_debugColor);

    // Initialize both sprite and debug rect with same properties
    setOrigin(size * 0.5f);
    setPosition(position);
}

bool Rectangle::collidesWith(Rectangle *pOther)
{
    return collision::areColliding(this->m_debugRect, pOther->m_debugRect);
}

void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (m_sprite.getTexture())
        target.draw(m_sprite, states);
    if (s_debugDraw)
        target.draw(m_debugRect, states);
}

void Rectangle::setSize(sf::Vector2f size)
{
    m_size = size;
    m_debugRect.setSize(size);
    setOrigin(size * 0.5f);
}
