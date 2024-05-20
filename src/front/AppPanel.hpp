#ifndef APPPANEL_H
#define APPPANEL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputBox.hpp"
#include "Button.hpp"
#include "../appcontroller/AppController.hpp"

using namespace sf;
using namespace std;

class AppPanel {
private:
    AppController appcontroller;
    Font font;
    RenderWindow window;
    Text title;
    Text labelSaison;
    Text labelRallye;
    Text labelSpeciale;
    Text labelCategorie;
    InputBox inputSaison;
    InputBox inputRallye;
    InputBox inputSpeciale;
    InputBox inputCategorie;
    Button seeSeasonListButton;
    Button seeRallyeListButton;
    Button seeSpecialeListButton;

public:
// Initialisation de la fenetre et de ses composants
    AppPanel() {
        config_frame();
        initialize();
    }

    void config_frame() {
        window.create(VideoMode(800, 600), "Rallye",  Style::Close | Style::None);
        window.setFramerateLimit(60);
    }

    void initialize() {
        if (!font.loadFromFile("J:\\Perso\\Rallye 3.0\\assets\\fonts\\Vera.ttf")) {
            cerr << "Police non chargé." << endl;
        }

        title = Text("Classement", font, 30);
        title.setFillColor(Color::Black);
        title.setPosition(300, 50);
        
        labelSaison = Text("Saison", font, 15);
        labelSaison.setFillColor(Color::Black);
        labelSaison.setPosition(50, 155);
        inputSaison = InputBox(150, 150, 150, 35, font);
        seeSeasonListButton =  Button(600, 150, 150, 35, font, "Afficher");
        
        labelRallye = Text("Rallye", font, 15);
        labelRallye.setFillColor(Color::Black);
        labelRallye.setPosition(50, 205);
        inputRallye = InputBox(150, 200, 150, 35, font);
        seeRallyeListButton =  Button(600, 200, 150, 35, font, "Afficher");
        
        labelSpeciale = Text("Speciale", font, 15);
        labelSpeciale.setFillColor(Color::Black);
        labelSpeciale.setPosition(50, 255);
        inputSpeciale = InputBox(150, 250, 150, 35, font);
        seeSpecialeListButton =  Button(600, 250, 150, 35, font, "Afficher");
        
        labelCategorie = Text("Categorie", font, 15);
        labelCategorie.setFillColor(Color::Black);
        labelCategorie.setPosition(325, 205);
        inputCategorie = InputBox(425, 200, 150, 35, font);
    }
// ============================================


// 
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                inputSaison.handleEvent(event);
                inputRallye.handleEvent(event);
                inputSpeciale.handleEvent(event);
                inputCategorie.handleEvent(event);

                addLIstener(window, event);

                if (event.type == Event::Closed) {
                    window.close();
                }
            }

            window.clear(Color::White);
            window.draw(title);
            window.draw(labelSaison);
            window.draw(labelRallye);
            window.draw(labelSpeciale);
            window.draw(labelCategorie);
            inputSaison.draw(window);
            inputRallye.draw(window);
            inputSpeciale.draw(window);
            inputCategorie.draw(window);
            seeSeasonListButton.draw(window);
            seeRallyeListButton.draw(window);
            seeSpecialeListButton.draw(window);
            window.display();
        }
    }

    void addLIstener(RenderWindow& window, Event& event) {
        if (seeSeasonListButton.isClicked(event)) {
            int idSaison = stoi(inputSaison.getContent());
            int idCategorie = stoi(inputCategorie.getContent());

            appcontroller.showRankSeasonList(idSaison, idCategorie);
        }
        if (seeRallyeListButton.isClicked(event)) {
            int idRallye = stoi(inputRallye.getContent());
            int idCategorie = stoi(inputCategorie.getContent());

            appcontroller.showRankRallyeList(idRallye, idCategorie);
        }
        if (seeSpecialeListButton.isClicked(event)) {
            int idSpeciale = stoi(inputSpeciale.getContent());
            int idCategorie = stoi(inputCategorie.getContent());
            
            appcontroller.showRankSpecialeList(idSpeciale, idCategorie);
        }
    }
// ============================================
};

#endif