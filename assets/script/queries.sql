-- Par saison
-- Meilleurs temps d'une Saison
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOIN Rallye ON rallye.id = Speciale.id_rallye
JOIN Saison ON  Saison.id = rallye.id_saison
WHERE Saison.id = 1 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;
-- Par catégorie
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOiN Categorie ON Categorie.id = Concurrent.id_categorie
JOIN Rallye ON rallye.id = Speciale.id_rallye
JOIN Saison ON  Saison.id = rallye.id_saison
WHERE Saison.id = 1 AND Categorie.id = 1 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;


-- Par rallye
-- Meilleurs temps d'un Rallye
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOIN Rallye ON rallye.id = Speciale.id_rallye
WHERE Rallye.id = 1 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;
-- Par catégorie
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOiN Categorie ON Categorie.id = Concurrent.id_categorie
JOIN Rallye ON rallye.id = Speciale.id_rallye
WHERE Rallye.id = 1 AND Categorie.id = 3 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;


-- Par speciale
-- Meilleurs temps d'un Spéciale
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
WHERE Speciale.id =6-- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time limit 5;

-- Par catégorie
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOiN Categorie ON Categorie.id = Concurrent.id_categorie
WHERE Speciale.id = 1 AND Categorie.id = 2 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;


---powerstage 
-- Meilleurs temps d'un Spéciale
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
WHERE Speciale.id in (SELECT max(id) from speciale where id_rallye = 1)
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time limit 5;


-- Par catégorie
SELECT Concurrent.nom, id_concurrent, (SUM(temps::interval)) AS total_time
FROM Temps
JOIN Speciale ON Speciale.id = Temps.id_speciale
JOiN Concurrent ON Concurrent.id = Temps.id_concurrent
JOiN Categorie ON Categorie.id = Concurrent.id_categorie
WHERE Speciale.id  in (SELECT max(id) from speciale where id_rallye = 1)  AND Categorie.id = 2 -- Variable
GROUP BY Temps.id_concurrent, Concurrent.nom
ORDER BY total_time;



--dernier speciale par rally
; 