#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class ScrollBar {
private:
    RectangleShape m_scrollBar;
    RectangleShape m_scrollHandle;
    float m_scrollPercentage;
    bool m_isDragging;
    Vector2f m_dragOffset;

public:
    ScrollBar() {}
    ScrollBar(float width, float height): m_isDragging(false), m_scrollPercentage(0.f) {
        // Création de la barre de défilement
        m_scrollBar.setSize(Vector2f(width, height));
        m_scrollBar.setFillColor(Color(200, 200, 200));

        // Création de la poignée de défilement
        m_scrollHandle.setSize(Vector2f(width, height / 5.f));
        m_scrollHandle.setFillColor(Color(100, 100, 100));
    }

    void setPosition(float x, float y) {
        m_scrollBar.setPosition(x, y);
        m_scrollHandle.setPosition(x, y);
    }

    void setSize(float width, float height) {
        m_scrollBar.setSize(Vector2f(width, height));
        m_scrollHandle.setSize(Vector2f(width, height / 5.f));
    }

    void setScrollPercentage(float percentage) {
        m_scrollPercentage = std::max(0.f, std::min(1.f, percentage));
        float handlePosition = m_scrollBar.getPosition().y + m_scrollBar.getSize().y * m_scrollPercentage;
        m_scrollHandle.setPosition(m_scrollBar.getPosition().x, handlePosition);
    }

    void draw(RenderWindow& window) {
        window.draw(m_scrollBar);
        window.draw(m_scrollHandle);
    }

    void handleEvent(const Event& event, const RenderWindow& window) {
        if (event.type == Event::MouseWheelScrolled) {
            if (m_scrollBar.getGlobalBounds().contains(window.mapPixelToCoords({event.mouseWheelScroll.x, event.mouseWheelScroll.y}))) {
                setScrollPercentage(m_scrollPercentage - event.mouseWheelScroll.delta * 0.1f);
            }
        }
    }


    float getScrollPercentage() const {
        return m_scrollPercentage;
    }

    float getScrollAmount() const {
        return m_scrollPercentage * m_scrollBar.getSize().y;
    }

};

#endif