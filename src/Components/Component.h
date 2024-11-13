#pragma once
#include <SFML/Graphics.hpp>

class Component {
public:
	virtual ~Component() = default;

	// required pure virtual
	virtual const char* getName() const = 0;

	// Optional functions
	virtual void init() {}
	virtual void update(float dt) {}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {}

	// non-virtual shared for all components
	void enable() { m_enabled = true; }
	void disable() { m_enabled = false; }
	bool isEnabled() const { return m_enabled; }
	void toggleEnabled() { m_enabled = !m_enabled; }
	void setEnabled(bool enabled) { m_enabled = enabled; }

protected:
	bool m_enabled{true};
};
