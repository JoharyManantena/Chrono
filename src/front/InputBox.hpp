#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class InputBox {
private:
    RectangleShape box;
    Text text;
    string content;
    bool isSelected;

public:
    InputBox() : isSelected(false) {}
    InputBox(float x, float y, float width, float height, Font& font) : isSelected(false) {
        box.setPosition(x, y);
        box.setSize(Vector2f(width, height));
        box.setFillColor(Color::White);
        box.setOutlineThickness(1);
        box.setOutlineColor(Color::Black);

        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(Color::Black);
        text.setPosition(x + 5, y + 5);
    }

    void handleEvent(Event& event) {
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (box.getGlobalBounds().contains(mousePos)) {
                    isSelected = true;
                } else {
                    isSelected = false;
                }
            }
        } else if (event.type == Event::TextEntered && isSelected) {
            if (event.text.unicode == '\b') { // Backspace
                if (!content.empty()) {
                    content.pop_back();
                    text.setString(content);
                }
            } else if (event.text.unicode < 128) {
                content += static_cast<char>(event.text.unicode);
                text.setString(content);
            }
        }
    }
    
    void draw(RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }

    string getContent() {
        if (content == "") {
            return "0";
        }
        return content;
    }
};

#endif