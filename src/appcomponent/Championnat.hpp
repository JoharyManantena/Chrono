#ifndef CHAMPIONNAT_H
#define CHAMPIONNAT_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Championnat {
private:
    int id;
    string nom;
    int id_saison;

public:
    Championnat() : id(0), nom(""), id_saison(0) {}
    Championnat(int _id, const string& _nom, int _id_saison) : id(_id), nom(_nom), id_saison(_id_saison) {}
// ============================================


// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Championnat", column, data);
    }

    vector<Championnat> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Championnat");
        vector<Championnat> championnats;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);
                int id_saison = atoi(PQgetvalue(result, i, 2));

                championnats.push_back(Championnat(id, nom, id_saison));
            }
            PQclear(result);
        }
        return championnats;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Championnat", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Championnat", condition);
    }

// ============================================


// GETTERS & SETTERS
    // Getters
    int getId() const {
        return id;
    }
    string getNom() const {
        return nom;
    }
    int getIdSaison() const {
        return id_saison;
    }

    // Setters
    void setId(int _id) {
        id = _id;
    }
    void setNom(const string& _nom) {
        nom = _nom;
    }
    void setIdSaison(int _id_saison) {
        id_saison = _id_saison;
    }
// ============================================
};

#endif