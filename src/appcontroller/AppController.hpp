#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "../appcomponent/Classement.hpp"
#include "../front/ResultPanel.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "../appcomponent/Rallye.hpp"

class AppController {
private:
    Classement classement;

public:
    AppController() {}
// ============================================


// SAISON
    void showRankSeasonList(int idSaison, int idCategorie) {
        Rallye rallye;
        vector<Rallye> rallyes = rallye.selectBySaison(idSaison);
        
        vector<vector<Classement>> listRankList;
        for (Rallye r : rallyes) {
            vector<Classement> rankList = classement.getClassementParRallye(r.getId());  
            vector<Classement> powerStage = classement.getClassementParPowerSatge(r.getId());
            rankList = updatePoints(rankList);
            updatePowerStage(rankList,powerStage);
            listRankList.push_back(rankList);
            
            for (int i = 0; i < rankList.size(); i++) {
                cout << "sdfghjk " << rankList.at(i).getWinRallyeCounter() << endl;
            }
            cout << endl;
        }

        vector<Classement> rankList = classement.getClassementParSaisonInCategorie(idSaison, idCategorie);
        if (idCategorie == 0) {
            rankList = classement.getClassementParSaison(idSaison);
        }

        vector<Classement> newRankList = additionPoints(listRankList, rankList);
        // Triage décroissant par rapport aux points
        sort(newRankList.begin(), newRankList.end(), [](const Classement& a, const Classement& b) {
            return a.getPoints() > b.getPoints();
        });

        for (int i = 0; i < newRankList.size(); i++) {
            cout << "sdfghjk " << newRankList.at(i).getWinRallyeCounter() << endl;
        }

        getExaequo(newRankList);
        
        string title = "Classement par saison";
        ResultPanel resultpanel(newRankList, title);
        resultpanel.run();
    }

    void getExaequo(vector<Classement> rankList) {
        if (rankList.size() > 0) {
            for (int i = 0; i < rankList.size()-1; i++) {
                if (rankList.at(i).getPoints() == rankList.at(i+1).getPoints()) {
                    getChampionBetween(rankList.at(i), rankList.at(i+1));
                }
            }
        }
    }

    void getChampionBetween(Classement c1, Classement c2) {
        cout << "Entre : " << endl;
        cout << " - " << c1.getNom() << endl;
        cout << " - " << c2.getNom() << endl;
        if (c1.getWinRallyeCounter() > c2.getWinRallyeCounter()) {
            cout << "Champion : " << c1.getNom() << endl;
        }
        else if (c1.getWinRallyeCounter() < c2.getWinRallyeCounter()) {
            cout << "Champion : " << c2.getNom() << endl;
        }
        cout << endl;
    }


    vector<Classement> additionPoints(vector<vector<Classement>> listRankList, vector<Classement> rankList) {
        vector<Classement> newRankList;

        for (int i=0; i < rankList.size(); i++) {
            int id = rankList.at(i).getIdConcurrent();
            int points = 0;
            int winRallye = 0;

            for (vector<Classement> listClassement : listRankList) {      
                for (Classement c : listClassement)
                {
                    if (c.getIdConcurrent() == id) {
                        points += c.getPoints();
                        winRallye += c.getWinRallyeCounter();
                        // cout << points << endl;
                        break;
                    }
                }
            }
            rankList.at(i).setPoints(points);
            rankList.at(i).setWinRallyeCounter(winRallye);
            newRankList.push_back(rankList.at(i));
        }

        return newRankList;
    }
// ============================================


// RALLYE
    void showRankRallyeList(int idRallye, int idCategorie) {
        vector<Classement> rankList = classement.getClassementParRallyeInCategorie(idRallye, idCategorie);
        rankList = updatePoints(rankList);
        if (idCategorie == 0) {
            rankList = classement.getClassementParRallye(idRallye);
            vector<Classement> powerStage = classement.getClassementParPowerSatge(idRallye);
            rankList = updatePoints(rankList);
            updatePowerStage(rankList,powerStage);
        }

        string title = "Classement par rallye";
        ResultPanel resultpanel(rankList, title);
        resultpanel.run();
    }
// ============================================


// SPECIALE
    void showRankSpecialeList(int idSpeciale, int idCategorie) {
        vector<Classement> rankList = classement.getClassementParSpecialeInCategorie(idSpeciale, idCategorie);
        if (idCategorie == 0) {
            rankList = classement.getClassementParSpeciale(idSpeciale);
        }

        string title = "Classement par speciale";
        ResultPanel resultpanel(rankList, title);
        resultpanel.run();
    }
// ============================================
    void updatePowerStage(vector<Classement>& rankList,vector<Classement> rankListPower) {
        int points = 5;
        for (int i = 0; i < rankListPower.size(); i++) {
            for (int j = 0; j < rankList.size(); j++) {
                if (rankListPower.at(i).getIdConcurrent() == rankList.at(j).getIdConcurrent()) {
                    rankList.at(j).setPoints(rankList.at(j).getPoints() + points);
                    points--;
                }
            }
        }
    }
    

    vector<Classement> updatePoints(vector<Classement> rankList) {
        vector<Classement> newRank;

        for (int i = 0; i < rankList.size(); i++) {
            if (i <= 9) {
                switch (i) {
                    case 0:
                        rankList.at(i).setPoints(10);
                        rankList.at(i).setWinRallyeCounter(rankList.at(i).getWinRallyeCounter() + 1);
                        break;
                        
                    case 1:
                        rankList.at(i).setPoints(9);
                        break;
                        
                    case 2:
                        rankList.at(i).setPoints(8);
                        break;
                        
                    case 3:
                        rankList.at(i).setPoints(7);
                        break;
                        
                    case 4:
                        rankList.at(i).setPoints(6);
                        break;
                        
                    case 5:
                        rankList.at(i).setPoints(5);
                        break;
                        
                    case 6:
                        rankList.at(i).setPoints(4);
                        break;
                        
                    case 7:
                        rankList.at(i).setPoints(3);
                        break;
                        
                    case 8:
                        rankList.at(i).setPoints(2);
                        break;
                        
                    case 9:
                        rankList.at(i).setPoints(1);
                        break;
                }
            }
            else {
                rankList.at(i).setPoints(0);
            }
            newRank.push_back(rankList.at(i));
        }

        return newRank;
    }
};

#endif