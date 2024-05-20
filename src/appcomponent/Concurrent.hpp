#ifndef CONCURRENT_H
#define CONCURRENT_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Concurrent {
private:
    int id;
    string nom;
    int id_categorie;

public:
    Concurrent() : id(0), nom(""), id_categorie(0) {}
    Concurrent(int _id, const string& _nom, const int _id_categorie) : id(_id), nom(_nom),  id_categorie(_id_categorie) {}
// ============================================


// CRUD
    bool insert(const string& column,const string& data) {
        PostgreConnection connection;
        return connection.insert("Concurrent", column, data);
    }

    vector<Concurrent> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Concurrent"); 
        vector<Concurrent> concurrents;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);
                int id_categorie = atol(PQgetvalue(result, i, 2));

                concurrents.push_back(Concurrent(id, nom, id_categorie));
            }
            PQclear(result);
        }

        return concurrents;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Concurrent", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Concurrent", condition);
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

    int getid_categorie() const {
        return id_categorie;
    }

    // Setters
    void setId(int _id) {
        id = _id;
    }

    void setNom(const string& _nom) {
        nom = _nom;
    }

    void setid_categorie(const int _id_categorie) {
        id_categorie = _id_categorie;
    }
    // ============================================
};

#endif