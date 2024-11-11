#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>

class Rectangle : public sf::Drawable, public sf::Transformable
{
public:
    Rectangle(sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0));
    virtual ~Rectangle() {}

    bool collidesWith(Rectangle* pOther);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // Setters
    void setSize(sf::Vector2f size);
    void setColor(sf::Color color) { m_color = color; }
    void setDebugColor(sf::Color color) { m_debugColor = color; m_debugRect.setFillColor(color); }

    // Override transformable functions to keep sprite and debug rect in sync
    void setOrigin(float x, float y) {
        sf::Transformable::setOrigin(x, y);
        m_sprite.setOrigin(x, y);
        m_debugRect.setOrigin(x, y);
    }

    void setOrigin(const sf::Vector2f& origin) {
        setOrigin(origin.x, origin.y);
    }

    void setPosition(float x, float y) {
        sf::Transformable::setPosition(x, y);
        m_sprite.setPosition(x, y);
        m_debugRect.setPosition(x, y);
    }

    void setPosition(const sf::Vector2f& position) {
        setPosition(position.x, position.y);
    }

    void setScale(float x, float y) {
        sf::Transformable::setScale(x, y);
        m_sprite.setScale(x, y);
        m_debugRect.setScale(x, y);
    }

    void setScale(const sf::Vector2f& scale) {
        setScale(scale.x, scale.y);
    }

    void setRotation(float angle) {
        sf::Transformable::setRotation(angle);
        m_sprite.setRotation(angle);
        m_debugRect.setRotation(angle);
    }

    // Getters
    sf::Vector2f getSize() const { return m_size; }
    sf::Color getColor() const { return m_color; }
    sf::Vector2f getCenter() const { return getPosition() + (m_size * 0.5f); }

protected:
    sf::Sprite m_sprite;
    sf::Color m_color{sf::Color::White};
    sf::Color m_debugColor{sf::Color(255, 0, 0, 128)};
    sf::Vector2f m_size;
    sf::RectangleShape m_debugRect;
    static bool s_debugDraw;
};
