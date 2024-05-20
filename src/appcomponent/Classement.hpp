#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>
#include "Temps.hpp"
#include <iostream>

using namespace std;

class Classement {
private:
    int id_concurrent;
    string nom;
    string temps;
    int point;
    int winRallyeCounter;

public:
    Classement() : id_concurrent(0), nom(""), temps(""), point(0), winRallyeCounter(0) {}
    Classement(int _id_concurrent, string _nom, string _temps) : id_concurrent(_id_concurrent), nom(_nom), temps(_temps), point(0), winRallyeCounter(0) {}
// ============================================


// QUERY
    //SAISON
    vector<Classement> getClassementParSaison(const int saison) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent JOIN Rallye ON rallye.id = Speciale.id_rallye JOIN Saison ON  Saison.id = rallye.id_saison WHERE Saison.id = " + to_string(saison) + " GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }
    
    vector<Classement> getClassementParSaisonInCategorie(const int saison, const int categorie) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent JOiN Categorie ON Categorie.id = Concurrent.id_categorie JOIN Rallye ON rallye.id = Speciale.id_rallye JOIN Saison ON  Saison.id = rallye.id_saison WHERE Saison.id = " + to_string(saison) + " AND Categorie.id = " + to_string(categorie) + " GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }
    // ============================================

    
    //RALLYE
    vector<Classement> getClassementParRallye(const int rallye) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent JOIN Rallye ON rallye.id = Speciale.id_rallye WHERE Rallye.id = "+ to_string(rallye) +" GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }

    vector<Classement> getClassementParPowerSatge(const int rallye) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time"
                        " FROM Temps "
                        " JOIN Speciale ON Speciale.id = Temps.id_speciale "
                        " JOiN Concurrent ON Concurrent.id = Temps.id_concurrent "
                        " WHERE Speciale.id in (SELECT max(id) from speciale where id_rallye ="+ to_string(rallye) +") "
                        " GROUP BY Temps.id_concurrent, Concurrent.nom "
                        " ORDER BY total_time limit 5 ";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }


    // vector<Classement> getClassementParPowerSatgeCategorie(const int rallye, const int categorie) {
    //     PostgreConnection connection;
    //     string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time ";
    //                     + "FROM Temps ";
    //                     +"JOIN Speciale ON Speciale.id = Temps.id_speciale ";
    //                     +"JOiN Concurrent ON Concurrent.id = Temps.id_concurrent ";
    //                     +"JOiN Categorie ON Categorie.id = Concurrent.id_categorie ";
    //                     +"WHERE Speciale.id  in (SELECT max(id) from speciale where id_rallye = "+ to_string(rallye) +")  AND Categorie.id = "+ to_string(categorie) +" ";
    //                     +"GROUP BY Temps.id_concurrent, Concurrent.nom ";
    //                     +"ORDER BY total_time";
    //     PGresult *result = connection.executeQuery(query);
    //     vector<Classement> classementList;

    //     if (result) {
    //         int numRows = PQntuples(result);

    //         for (int i = 0; i < numRows; ++i) {
    //             string nom = PQgetvalue(result, i, 0);
    //             int id_concurrent = atoi(PQgetvalue(result, i, 1));
    //             string total_time = PQgetvalue(result, i, 2);

    //             classementList.push_back(Classement(id_concurrent, nom, total_time));
    //         }
    //         PQclear(result);
    //     }
    //     return classementList;   
    // }
    
    vector<Classement> getClassementParRallyeInCategorie(const int rallye, const int categorie) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent JOiN Categorie ON Categorie.id = Concurrent.id_categorie JOIN Rallye ON rallye.id = Speciale.id_rallye WHERE Rallye.id = "+ to_string(rallye) +" AND Categorie.id = "+ to_string(categorie) +" GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }
    // ============================================


    //SPECIALE
    vector<Classement> getClassementParSpeciale(const int speciale) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent WHERE Speciale.id = " + to_string(speciale) + " GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }
    
    vector<Classement> getClassementParSpecialeInCategorie(const int speciale, const int categorie) {
        PostgreConnection connection;
        string query = "SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent JOiN Categorie ON Categorie.id = Concurrent.id_categorie WHERE Speciale.id = " + to_string(speciale) + " AND Categorie.id = " + to_string(categorie) +" GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time";
        PGresult *result = connection.executeQuery(query);
        vector<Classement> classementList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                string nom = PQgetvalue(result, i, 0);
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                string total_time = PQgetvalue(result, i, 2);

                classementList.push_back(Classement(id_concurrent, nom, total_time));
            }
            PQclear(result);
        }
        return classementList;   
    }
    // ============================================
// ============================================

    
// GETTERS & SETTERS
    // Getters
    int getIdConcurrent() const {
        return id_concurrent;
    }
    string getNom() const {
        return nom;
    }
    string getTemps() const {
        return temps;
    }
    int getPoints() const {
        return point;
    }
    int getWinRallyeCounter() {
        return winRallyeCounter;
    }

    // Setters
    void setIdConcurrent(int _id_concurrent) {
        id_concurrent = _id_concurrent;
    }
    void setNom(const string& _nom) {
        nom = _nom;
    }
    void setTemps(const string& _temps) {
        temps = _temps;
    }
    void setPoints(int _point) {
        point = _point;
    }
    void setWinRallyeCounter(int _winRallyeCounter) {
        winRallyeCounter = _winRallyeCounter;
    }
// ============================================
};

#endif