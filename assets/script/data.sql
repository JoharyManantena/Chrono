-- -- Données pour la table Categorie
-- INSERT INTO Categorie (nom) VALUES 
-- ('A'),
-- ('B'),
-- ('C');


-- -- Données pour la table Concurrent
-- INSERT INTO Concurrent (nom, id_categorie) VALUES
-- -- Catégorie A
-- ('Jean Dupont', 1),
-- ('Sophie Martin', 1),
-- ('Pierre Dubois', 1),
-- ('Marie Leroy', 1),
-- ('Luc Moreau', 1),
-- ('Caroline Lefevre', 1),
-- ('Thomas Laurent', 1),
-- ('Camille Petit', 1),
-- ('Nicolas Rousseau', 1),
-- ('Julie Garcia', 1),
-- ('Alexandre Fernandez', 1),
-- ('Emma Robert', 1),
-- ('Antoine Simon', 1),
-- ('Laura Dubois', 1),
-- ('Mathieu Girard', 1),
-- ('Charlotte Durand', 1),
-- ('Guillaume Lefort', 1),
-- ('Manon Dupuis', 1),
-- ('Maxime Morel', 1),
-- ('Elodie Martinez', 1),
-- ('Vincent Roussel', 1),
-- -- Catégorie B
-- ('Michael Johnson', 2),
-- ('Emily Chen', 2),
-- ('David Kim', 2),
-- ('Samantha Wong', 2),
-- ('Christopher Lee', 2),
-- ('Jennifer Park', 2),
-- ('Daniel Nguyen', 2),
-- ('Matthew White', 2),
-- ('Jessica Taylor', 2),
-- ('Kevin Brown', 2),
-- ('Michelle Anderson', 2),
-- ('Andrew Martinez', 2),
-- ('Amanda Garcia', 2),
-- ('Jason Rodriguez', 2),
-- ('Sarah Smith', 2),
-- ('Ryan Wilson', 2),
-- ('Taylor Thomas', 2),
-- ('Lauren Robinson', 2),
-- ('Justin Harris', 2),
-- ('Stephanie Jackson', 2),
-- ('Brandon Davis', 2),
-- -- Catégorie C
-- ('Hiroshi Tanaka', 3),
-- ('Yuki Yamamoto', 3),
-- ('Aya Suzuki', 3),
-- ('Takashi Watanabe', 3),
-- ('Mai Nakamura', 3),
-- ('Kazuki Sato', 3),
-- ('Yui Ito', 3),
-- ('Alexis Hernandez', 3),
-- ('Elena Lopez', 3),
-- ('Diego Garcia', 3),
-- ('Sofia Martinez', 3),
-- ('Juan Rodriguez', 3),
-- ('Luis Ramirez', 3),
-- ('Maria Perez', 3),
-- ('Carlos Sanchez', 3),
-- ('Laura Flores', 3),
-- ('Fernando Gonzalez', 3),
-- ('Ana Ruiz', 3),
-- ('Pedro Diaz', 3),
-- ('Eva Gomez', 3),
-- ('Javier Fernandez', 3);


-- -- Données pour la table Saison
-- INSERT INTO Saison (annee) VALUES 
-- (2021),
-- (2022),
-- (2023);


-- -- Saison 2021
-- INSERT INTO Rallye (nom, id_saison) VALUES 
-- ('Rallye 1', 1),
-- ('Rallye 2', 1),
-- ('Rallye 3', 1);
-- -- Saison 2022
-- INSERT INTO Rallye (nom, id_saison) VALUES 
-- ('Rallye 1', 2),
-- ('Rallye 2', 2),
-- ('Rallye 3', 2);
-- -- -- Saison 2023
-- INSERT INTO Rallye (nom, id_saison) VALUES 
-- ('Rallye 1', 3),
-- ('Rallye 2', 3),
-- ('Rallye 3', 3);


-- -- Données pour la table Rallye pour chaque Rallye de chaque Saison
-- -- Rallye 1 (2021)
-- INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
-- ('Spéciale 1', 100, '2021-01-01', 1),
-- ('Spéciale 2', 150, '2021-01-02', 1),
-- ('Spéciale 3', 120, '2021-01-03', 1),
-- -- Rallye 2 (2021)
-- ('Spéciale 1', 90, '2021-01-01', 2),
-- ('Spéciale 2', 110, '2021-01-02', 2),
-- ('Spéciale 3', 80, '2021-01-03', 2),
-- -- Rallye 3 (2021)
-- ('Spéciale 1', 120, '2021-01-01', 3),
-- ('Spéciale 2', 100, '2021-01-02', 3),
-- ('Spéciale 3', 130, '2021-01-03', 3);

-- -- Rallye 1 (2022)
-- -- INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
-- -- ('Spéciale 1', 110, '2022-01-01', 4),
-- -- ('Spéciale 2', 120, '2022-01-02', 4),
-- -- ('Spéciale 3', 100, '2022-01-03', 4),
-- -- -- Rallye 2 (2022)
-- -- ('Spéciale 1', 130, '2022-01-01', 5),
-- -- ('Spéciale 2', 140, '2022-01-02', 5),
-- -- ('Spéciale 3', 90, '2022-01-03', 5),
-- -- -- Rallye 3 (2022)
-- -- ('Spéciale 1', 120, '2022-01-01', 6),
-- -- ('Spéciale 2', 110, '2022-01-02', 6),
-- -- ('Spéciale 3', 100, '2022-01-03', 6);

-- -- -- Rallye 1 (2023)
-- -- INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
-- -- ('Spéciale 1', 100, '2023-01-01', 7),
-- -- ('Spéciale 2', 110, '2023-01-02', 7),
-- -- ('Spéciale 3', 120, '2023-01-03', 7),
-- -- -- Rallye 2 (2023)
-- -- ('Spéciale 1', 130, '2023-01-01', 8),
-- -- ('Spéciale 2', 140, '2023-01-02', 8),
-- -- ('Spéciale 3', 150, '2023-01-03', 8),
-- -- -- Rallye 3 (2023)
-- -- ('Spéciale 1', 120, '2023-01-01', 9),
-- -- ('Spéciale 2', 130, '2023-01-02', 9),
-- -- ('Spéciale 3', 140, '2023-01-03', 9);


-- -- Données pour la table Championnat
-- INSERT INTO Championnat (nom, id_saison) VALUES 
-- ('Championnat de France', 1),
-- ('Championnat Espagne', 1),
-- ('Championnat Italie', 2);


-- -- Données pour la table Temps
-- -- Temps pour chaque concurrent dans chaque catégorie
-- INSERT INTO Temps (id_concurrent, id_speciale, temps)
-- SELECT 
--     c.id AS id_concurrent,
--     s.id_speciale,
--     TIME '00:00:00' + (random() * (INTERVAL '5 hours') + INTERVAL '30 minutes') AS temps
-- FROM 
--     generate_series(1, 21) AS t
-- CROSS JOIN 
--     Concurrent AS c
-- CROSS JOIN 
--     (SELECT generate_series(1, 9) AS id_speciale) AS s
-- LIMIT 567;


INSERT INTO Categorie (nom) VALUES 
('A'),
('B');

INSERT INTO Concurrent (nom, id_categorie) VALUES
-- Catégorie A
('Concurrent 2', 1),
('Concurrent 3', 1),
('Concurrent 6', 1),
-- Catégorie B
('Concurrent 1', 2),
('Concurrent 4', 2),
('Concurrent 5', 2);

INSERT INTO Saison (annee) VALUES (2023);

INSERT INTO Rallye (nom, id_saison) VALUES 
('Rallye 1', 1),
('Rallye 2', 1),
('Rallye 3', 1);

INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
('Spéciale 1', 110, '2022-01-01', 1),
('Spéciale 2', 120, '2022-01-02', 1),
('Spéciale 3', 100, '2022-01-03', 1),
('Spéciale 4', 130, '2022-01-01', 1),
('Spéciale 5', 140, '2022-01-02', 1),
('Spéciale 6', 90, '2022-01-03', 1);

INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
('Spéciale 1', 110, '2022-01-01', 2),
('Spéciale 2', 120, '2022-01-02', 2),
('Spéciale 3', 100, '2022-01-03', 2),
('Spéciale 4', 130, '2022-01-01', 2),
('Spéciale 5', 140, '2022-01-02', 2),
('Spéciale 6', 90, '2022-01-03', 2);

INSERT INTO Speciale (nom, distance, date_speciale, id_rallye) VALUES 
('Spéciale 1', 110, '2022-01-01', 3),
('Spéciale 2', 120, '2022-01-02', 3),
('Spéciale 3', 100, '2022-01-03', 3),
('Spéciale 4', 130, '2022-01-01', 3),
('Spéciale 5', 140, '2022-01-02', 3),
('Spéciale 6', 90, '2022-01-03', 3);

-- Rallye 1
INSERT INTO Temps (id_concurrent, id_speciale, temps) VALUES
-- Concurrent 1 : 4
(4, 1, '00:12:45.400'),
(4, 2, '00:15:22.300'),
(4, 3, '00:11:09.268'),
(4, 4, '00:26:39.267'),
(4, 5, '00:19:23.280'),
(4, 6, '00:38:59.852'),
-- Concurrent 2 : 1
(1, 1, '00:21:15.275'),
(1, 2, '00:22:18.338'),
(1, 3, '00:12:15.735'),
(1, 4, '00:19:46.186'),
(1, 5, '00:24:06.446'),
(1, 6, '00:17:55.075'),
-- Concurrent 3 : 2
(2, 1, '00:25:13.251'),
(2, 2, '00:14:52.145'),
(2, 3, '00:11:29.113'),
(2, 4, '00:26:10.261'),
(2, 5, '00:28:47.285'),
(2, 6, '00:13:57.136'),
-- Concurrent 4 : 5
(5, 1, '00:16:09.169'),
(5, 2, '00:17:20.172'),
(5, 3, '00:32:29.323'),
(5, 4, '00:22:48.225'),
(5, 5, '00:29:10.291'),
(5, 6, '00:34:19.342'),
-- Concurrent 5 : 6
(6, 1, '00:16:36.164'),
(6, 2, '00:33:13.331'),
(6, 3, '00:11:41.114'),
(6, 4, '00:29:21.292'),
(6, 5, '00:29:57.296'),
(6, 6, '00:31:54.315'),
-- Concurrent 6 : 3
(3, 1, '00:27:48.275'),
(3, 2, '00:16:17.162'),
(3, 3, '00:15:47.155'),
(3, 4, '00:21:53.215'),
(3, 5, '00:27:24.272'),
(3, 6, '00:34:48.345');

-- Rallye 2
INSERT INTO Temps (id_concurrent, id_speciale, temps) VALUES
-- Concurrent 1 : 4
(4, 7, '00:12:45.400'),
(4, 8, '00:15:22.300'),
(4, 9, '00:11:09.000'),
(4, 10, '00:26:39.267'),
(4, 11, '00:19:23.280'),
(4, 12, '00:38:59.852'),
-- Concurrent 2 : 1
(1, 7, '00:21:15.275'),
(1, 8, '00:22:18.000'),
(1, 9, '00:12:15.735'),
(1, 10, '00:19:46.186'),
(1, 11, '00:24:06.446'),
(1, 12, '00:17:55.075'),
-- Concurrent 3 : 2
(2, 7, '00:25:13.251'),
(2, 8, '00:10:52.000'),
(2, 9, '00:11:29.113'),
(2, 10, '00:26:10.261'),
(2, 11, '00:28:47.285'),
(2, 12, '00:13:57.136'),
-- Concurrent 4 : 5
(5, 7, '00:16:09.169'),
(5, 8, '00:17:20.172'),
(5, 9, '00:32:29.323'),
(5, 10, '00:22:48.225'),
(5, 11, '00:29:10.291'),
(5, 12, '00:34:19.342'),
-- Concurrent 5 : 6
(6, 7, '00:16:36.164'),
(6, 8, '00:13:13.000'),
(6, 9, '00:11:41.114'),
(6, 10, '00:29:21.292'),
(6, 11, '00:19:57.000'),
(6, 12, '00:11:54.000'),
-- Concurrent 6 : 3
(3, 7, '00:27:48.275'),
(3, 8, '00:16:17.162'),
(3, 9, '00:15:47.155'),
(3, 10, '00:21:53.215'),
(3, 11, '00:27:24.272'),
(3, 12, '00:34:48.345');

-- Rallye 3
INSERT INTO Temps (id_concurrent, id_speciale, temps) VALUES
-- Concurrent 1 : 4
(4, 13, '00:12:45.400'),
(4, 14, '00:15:22.300'),
(4, 15, '00:12:09.000'),
(4, 16, '00:16:39.000'),
(4, 17, '00:19:23.280'),
(4, 18, '00:38:59.852'),
-- Concurrent 2 : 1
(1, 13, '00:21:15.275'),
(1, 14, '00:22:18.338'),
(1, 15, '00:12:15.735'),
(1, 16, '00:19:46.186'),
(1, 17, '00:24:06.446'),
(1, 18, '00:17:55.075'),
-- Concurrent 3 : 2
(2, 13, '00:25:13.251'),
(2, 14, '00:14:52.145'),
(2, 15, '00:11:29.113'),
(2, 16, '00:22:10.000'),
(2, 17, '00:28:47.285'),
(2, 18, '00:34:48.345'),
-- Concurrent 4 : 5
(5, 13, '00:16:09.169'),
(5, 14, '00:17:20.172'),
(5, 15, '00:32:29.323'),
(5, 16, '00:22:48.225'),
(5, 17, '00:29:10.291'),
(5, 18, '00:34:19.342'),
-- Concurrent 5 : 6
(6, 13, '00:16:36.164'),
(6, 14, '00:33:13.331'),
(6, 15, '00:11:41.114'),
(6, 16, '00:29:21.292'),
(6, 17, '00:29:57.296'),
(6, 18, '00:31:54.315'),
-- Concurrent 6 : 3
(3, 13, '00:20:48.000'),
(3, 14, '00:16:17.162'),
(3, 15, '00:15:47.155'),
(3, 16, '00:21:53.215'),
(3, 17, '00:27:24.272'),
(3, 18, '00:14:48.000');