#ifndef RALLYE_H
#define RALLYE_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Rallye {
private:
    int id;
    string nom;
    int id_saison;

public:
    Rallye() : id(0), nom(""), id_saison(0) {}
    Rallye(int _id, const string& _nom, int _id_saison) : id(_id), nom(_nom), id_saison(_id_saison) {}
// ============================================

// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Rallye", column, data);
    }

    vector<Rallye> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Rallye");
        vector<Rallye> rallyes;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);
                int id_saison = atoi(PQgetvalue(result, i, 2));

                rallyes.push_back(Rallye(id, nom, id_saison));
            }
            PQclear(result);
        }
        return rallyes;
    }
    
    vector<Rallye> selectBySaison(int saison) {
        PostgreConnection connection;
        PGresult* result = connection.select("Rallye WHERE id_saison = " + to_string(saison));
        vector<Rallye> rallyes;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);
                int id_saison = atoi(PQgetvalue(result, i, 2));

                rallyes.push_back(Rallye(id, nom, id_saison));
            }
            PQclear(result);
        }
        return rallyes;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Rallye", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Rallye", condition);
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