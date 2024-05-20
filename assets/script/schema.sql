CREATE DATABASE rallye OWNER postgres;

-- drop table Points;
-- drop table Temps;
-- drop table Championnat;
-- drop table Speciale;
-- drop table Rallye;
-- drop table Saison;
-- drop table Concurrent;
-- drop table Categorie;


CREATE TABLE Categorie (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50)
);

CREATE TABLE Concurrent (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50),
    id_categorie INT REFERENCES Categorie(id)
);

CREATE TABLE Saison (
    id SERIAL PRIMARY KEY,
    annee INT
);

CREATE TABLE Rallye (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50),
    id_saison INT REFERENCES Saison(id)
);

CREATE TABLE Speciale (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50),
    distance FLOAT,
    date_speciale DATE,
    id_rallye INT REFERENCES Rallye(id)
);

CREATE TABLE Championnat (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50),
    id_saison INT REFERENCES Saison(id)
);

CREATE TABLE Temps (
    id SERIAL PRIMARY KEY,
    id_concurrent INT REFERENCES Concurrent(id),
    id_speciale INT REFERENCES Speciale(id),
    temps TIME
);

CREATE TABLE Points (
    id SERIAL PRIMARY KEY,
    id_concurrent INT REFERENCES Concurrent(id),
    id_rallye INT REFERENCES Rallye(id),
    points INT
);



SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time FROM Temps JOIN Speciale ON Speciale.id = Temps.id_speciale JOiN Concurrent ON Concurrent.id = Temps.id_concurrent WHERE Speciale.id = 1 GROUP BY Temps.id_concurrent, Concurrent.nom ORDER BY total_time;