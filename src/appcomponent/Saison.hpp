#ifndef SAISON_H
#define SAISON_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Saison {
private:
    int id;
    int annee;

public:
    Saison() : id(0), annee(0) {}
    Saison(int _id, int _annee) : id(_id), annee(_annee) {}
// ============================================


// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Saison", column, data);
    }

    vector<Saison> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Saison");
        vector<Saison> saisons;

        if (result) {
            int numRows = PQntuples(result);
            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                int annee = atoi(PQgetvalue(result, i, 1));
                saisons.push_back(Saison(id, annee));
            }
            PQclear(result);
        }
        return saisons;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Saison", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Saison", condition);
    }
// ============================================


// GETTERS & SETTERS
    // Getters
    int getId() const {
        return id;
    }
    int getAnnee() const {
        return annee;
    }

    // Setters
    void setId(int _id) {
        id = _id;
    }
    void setAnnee(int _annee) {
        annee = _annee;
    }
// ============================================
};

#endif