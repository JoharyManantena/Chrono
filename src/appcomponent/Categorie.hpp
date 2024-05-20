#ifndef CATEGORIE_H
#define CATEGORIE_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Categorie {
private:
    int id;
    string nom;

public:
    Categorie() : id(0), nom("") {}
    Categorie(int _id, const string& _nom) : id(_id), nom(_nom) {}
// ============================================


// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Categorie", column, data);
    }

    vector<Categorie> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Categorie");
        vector<Categorie> categories;

        if (result) {
            int numRows = PQntuples(result);
            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);

                categories.push_back(Categorie(id, nom));
            }
            PQclear(result);
        }
        return categories;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Categorie", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Categorie", condition);
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

    // Setters
    void setId(int _id) {
        id = _id;
    }
    void setNom(const string& _nom) {
        nom = _nom;
    }
// ============================================
};

#endif