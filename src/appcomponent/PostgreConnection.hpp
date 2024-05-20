#ifndef CONNECT_H
#define CONNECT_H

#include "../../lib/libpq/libpq-fe.h"
#include <string>

using namespace std;

class PostgreConnection {
    private:
        PGconn *connection;
    public:
        PostgreConnection() : connection(nullptr) {
            string conninfo = "dbname=rallye user=postgres password=johary2003 host=localhost port=5432";
            connection = PQconnectdb(conninfo.c_str());

            if (PQstatus(connection) != CONNECTION_OK) {
                cerr << "La connexion à la base de données a échoué: " << PQerrorMessage(connection) << endl;
            }
        }

        ~PostgreConnection() {
            if (connection != nullptr) {
                PQfinish(connection);
            }
        }

        PGresult*  executeQuery(const string& query) {
            PGresult *result = PQexec(connection, query.c_str());
            if (PQresultStatus(result) != PGRES_TUPLES_OK) {
                cerr << "Erreur lors de l'exécution de la requête : " << PQresultErrorMessage(result) << endl;
                PQclear(result);
                return nullptr;
            }
            return result;
        }
        
        PGresult*  executeUpdate(const string& query) {
            PGresult *result = PQexec(connection, query.c_str());
            if (PQresultStatus(result) != PGRES_COMMAND_OK) {
                cerr << "Erreur lors d'une modification par la requête : " << PQresultErrorMessage(result) << endl;
                PQclear(result);
                return nullptr;
            }
            return result;
        }   

        bool insert(const string& tableName, const string& column, const string& data) {
            string query = "INSERT INTO " + tableName + "(" + column + ") VALUES (" + data + ")";
            PGresult *result = executeUpdate(query);
            if (result) {
                PQclear(result);
                cout << "Insertion effectué avec succès." << endl;
                return true;
            }
            return false;
        }

        PGresult* select(const string& tableName) {
            string query = "SELECT * FROM " + tableName;
            return executeQuery(query);
        }

        bool update(const string& tableName, const string& newData, const string& condition) {
            string query = "UPDATE " + tableName + " SET " + newData + " WHERE " + condition;
            PGresult *result = executeUpdate(query);
            if (result) {
                PQclear(result);
                cout << "Modification effectué avec succès." << endl;
                return true;
            }
            return false;
        }

        bool deleteData(const string& tableName, const string& condition) {
            string query = "DELETE FROM " + tableName + " WHERE " + condition;
            PGresult *result = executeUpdate(query);
            if (result) {
                PQclear(result);
                cout << "Suppression effectué avec succès." << endl;
                return true;
            }
            return false;
        }
};

#endif