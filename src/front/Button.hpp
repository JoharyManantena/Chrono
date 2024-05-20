#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Button {
private:
    RectangleShape box;
    Text text;

public:
    Button() {}
    Button(float x, float y, float width, float height, Font& font, std::string buttonText) {
        box.setPosition(x, y);
        box.setSize(Vector2f(width, height));
        box.setFillColor(colorFromHex("#3585CD"));

        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(Color::White);
        text.setString(buttonText);
        text.setPosition(x + width/4, y +  + height/5);
    }

    bool isClicked(Event& event) {
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (box.getGlobalBounds().contains(mousePos)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    void draw(RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }
    
    Color colorFromHex(const std::string& hex) {
        unsigned r = std::stoi(hex.substr(1, 2), nullptr, 16);
        unsigned g = std::stoi(hex.substr(3, 2), nullptr, 16);
        unsigned b = std::stoi(hex.substr(5, 2), nullptr, 16);
        return sf::Color(r, g, b);
    }
};

#endif