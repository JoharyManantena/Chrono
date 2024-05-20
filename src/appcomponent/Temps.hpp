#ifndef TEMPS_H
#define TEMPS_H

#include "PostgreConnection.hpp"
#include <string>
#include <vector>

using namespace std;

class Temps {
private:
    int id;
    int id_concurrent;
    int id_speciale;
    string temps;

public:
    Temps() : id(0), id_concurrent(0), id_speciale(0), temps("") {}
    Temps(int _id, int _id_concurrent, int _id_speciale, const string& _temps) : id(_id), id_concurrent(_id_concurrent), id_speciale(_id_speciale), temps(_temps) {}
// ============================================


// CRUD
    bool insert(const string& column, const string& data) {
        PostgreConnection connection;
        return connection.insert("Temps", column, data);
    }

    vector<Temps> select() {
        PostgreConnection connection;
        PGresult* result = connection.select("Temps");
        vector<Temps> tempsList;

        if (result) {
            int numRows = PQntuples(result);

            for (int i = 0; i < numRows; ++i) {
                int id = atoi(PQgetvalue(result, i, 0));
                int id_concurrent = atoi(PQgetvalue(result, i, 1));
                int id_speciale = atoi(PQgetvalue(result, i, 2));
                string temps = PQgetvalue(result, i, 3);

                tempsList.push_back(Temps(id, id_concurrent, id_speciale, temps));
            }
            PQclear(result);
        }
        return tempsList;
    }

    bool update(const string& newData, const string& condition) {
        PostgreConnection connection;
        return connection.update("Temps", newData, condition);
    }

    bool deleteData(const string& condition) {
        PostgreConnection connection;
        return connection.deleteData("Temps", condition);
    }

// ============================================


// GETTERS & SETTERS
    // Getters
    int getId() const {
        return id;
    }
    int getIdConcurrent() const {
        return id_concurrent;
    }
    int getIdSpeciale() const {
        return id_speciale;
    }
    string getTemps() const {
        return temps;
    }

    // Setters
    void setId(int _id) {
        id = _id;
    }
    void setIdConcurrent(int _id_concurrent) {
        id_concurrent = _id_concurrent;
    }
    void setIdSpeciale(int _id_speciale) {
        id_speciale = _id_speciale;
    }
    void setTemps(const string& _temps) {
        temps = _temps;
    }
// ============================================
};

#endif