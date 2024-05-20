#ifndef RESULTPANEL_H
#define RESULTPANEL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ScrollBar.hpp"
#include "../appcomponent/Classement.hpp"

using namespace sf;
using namespace std;

class ResultPanel {
private:
    Font font;
    RenderWindow window;
    vector<Classement> rankLIst;
    ScrollBar scrollbar;

public:
// Initialisation de la fenetre et de ses composants
    ResultPanel(vector<Classement> _rankLIst, string& title) {
        config_frame(title);
        initialize();

        rankLIst = _rankLIst;
    }

    void config_frame(string& title) {
        window.create(VideoMode(600, 600), title,  Style::Close | Style::None);
        window.setFramerateLimit(60);
    }

    void initialize() {
        if (!font.loadFromFile("J:\\Perso\\Rallye 3.0\\assets\\fonts\\Vera.ttf")) {
            cerr << "Police non chargé." << endl;
        }
        
        scrollbar = ScrollBar(30, 600);
        scrollbar.setPosition(470, 400);
    }
// ============================================
 
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
                scrollbar.handleEvent(event, window);
            }
            
            // Déplacement de la vue de la fenêtre en fonction de la position de la poignée de défilement
            View view = window.getView();
            view.setCenter(view.getSize().x / 2, view.getSize().y / 2 + scrollbar.getScrollAmount());
            window.setView(view);

            window.clear(Color::White);
            drawTable(window);
            scrollbar.draw(window);
            window.display();
        }
    }

    void drawTable(RenderWindow& window) {
        // En-têtes
        Text headerId("id", font, 20);
        Text headerNom("Nom", font, 20);
        Text headerTemps("Temps", font, 20);
        Text headerPoints("Points", font, 20);

        headerId.setPosition(15, 10);
        headerId.setFillColor(Color::Black);
        headerNom.setPosition(75, 10);
        headerNom.setFillColor(Color::Black);
        headerTemps.setPosition(275, 10);
        headerTemps.setFillColor(Color::Black);
        headerPoints.setPosition(450, 10);
        headerPoints.setFillColor(Color::Black);

        window.draw(headerId);
        window.draw(headerNom);
        window.draw(headerTemps);
        window.draw(headerPoints);

        float y = 50;
        for (Classement classement : rankLIst) {
            // Affichage de l'ID concurrent
            Text idText(to_string(classement.getIdConcurrent()), font, 16);
            idText.setPosition(15, y);
            idText.setFillColor(Color::Black);
            window.draw(idText);

            // Affichage du nom
            Text nomText(classement.getNom(), font, 16);
            nomText.setPosition(headerNom.getPosition().x, y);
            nomText.setFillColor(Color::Black);
            window.draw(nomText);

            // Affichage du temps (converti en secondes pour cet exemple)
            Text tempsText(classement.getTemps(), font, 16);
            tempsText.setPosition(headerTemps.getPosition().x, y);
            tempsText.setFillColor(Color::Black);
            window.draw(tempsText);
            
            // Affichage des points
            Text pointsText(to_string(classement.getPoints()), font, 16);
            pointsText.setPosition(headerPoints.getPosition().x, y);
            pointsText.setFillColor(Color::Black);
            window.draw(pointsText);

            y += 30;
        }
    } 
};

#endif