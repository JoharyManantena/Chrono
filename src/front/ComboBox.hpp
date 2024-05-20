#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>

using namespace sf;
using namespace std;

class ComboBox {
private:
    Font font;
    RectangleShape box;
    string selectedKey;
    Text selectedText;
    map<string, int> options;
    bool isOpen;

public:
    ComboBox() : isOpen(false) {}
    ComboBox(float x, float y, float width, float height, sf::Font& _font, const map<string, int>& optionsList) : font(_font), isOpen(false) {
        box.setPosition(x, y);
        box.setSize(sf::Vector2f(width, height));
        box.setFillColor(sf::Color::White);
        box.setOutlineThickness(1);
        box.setOutlineColor(sf::Color::Black);

        selectedText.setFont(font);
        selectedText.setCharacterSize(20);
        selectedText.setFillColor(sf::Color::Black);
        selectedText.setPosition(x + 5, y + 5);

        options = optionsList;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(selectedText);

        if (isOpen) {
            float yPos = box.getPosition().y + box.getSize().y;
            for (const auto& option : options) {
                Text optionText;
                optionText.setString(option.first);
                optionText.setFont(font);
                optionText.setCharacterSize(selectedText.getCharacterSize());
                optionText.setPosition(box.getPosition().x, yPos);
                window.draw(optionText);
                yPos += 30;
            }
        }
    }

    void handleEvent(sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (box.getGlobalBounds().contains(mousePos)) {
                isOpen = !isOpen;
            } else if (isOpen) {
                isOpen = false;
            }
        }
    }

    bool isOpened() const {
        return isOpen;
    }

    const map<string, int>& getOptions() const {
        return options;
    }
    
    int getSelectedValue() const {
        auto it = options.find(selectedKey);
        if (it != options.end()) {
            return it->second;
        }
        return 0;
    }

    std::string getSelectedKey() const {
        return selectedKey;
    }

    void setSelectedKey(const std::string& key) {
        selectedKey = key;
    }
};

#endif