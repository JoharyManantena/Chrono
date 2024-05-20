#ifndef SPECIALE_H
#define SPECIALE_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Speciale {
private:
    int id;
    string nom;
    float distance;
    string date_speciale;

public:
    Speciale() : id(0), nom(""), distance(0.0f), date_speciale("") {}
    Speciale(int _id, const string& _nom, float _distance, const string& _date_speciale) : id(_id), nom(_nom), distance(_distance), date_speciale(_date_speciale) {}
// ============================================


// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Speciale", column, data);
    }

    vector<Speciale> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Speciale");
        vector<Speciale> speciales;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                string nom = PQgetvalue(result, i, 1);
                float distance = atof(PQgetvalue(result, i, 2));
                string date_speciale = PQgetvalue(result, i, 3);

                speciales.push_back(Speciale(id, nom, distance, date_speciale));
            }
            PQclear(result);
        }
        return speciales;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Speciale", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Speciale", condition);
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
    float getDistance() const {
        return distance;
    }
    string getDateSpeciale() const {
        return date_speciale;
    }

    // Setters
    void setId(int _id) {
        id = _id;
    }
    void setNom(const string& _nom) {
        nom = _nom;
    }
    void setDistance(float _distance) {
        distance = _distance;
    }
    void setDateSpeciale(const string& _date_speciale) {
        date_speciale = _date_speciale;
    }
// ============================================
};

#endif