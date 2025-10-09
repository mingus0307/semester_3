-- DBS2.1.2.a::
-- Suchen Sie alle Informationen aus der Tabelle MOVIE für Kinofilme aus dem Jahr 1989.
-- Kinofilme sind Einträge in der MOVIE-Tabelle mit Type=C.
-- Erwartete Spaltennamen: id, title, year
SELECT id, title, year
FROM moviedb2.movie 
WHERE type = 'C'
AND year = 1989; 

-- DBS2.1.2.b::
-- Finden Sie die Titel (TITLE) aller Kinofilme (d.h. Type=C), sowie die darin
-- auftretenden Charaktere (CHARACTER) und Namen (NAME) des Schauspielers
-- der Schauspielerin des Charakters.
-- Geben Sie nur die Informationen für Filme aus, die entweder vor dem Jahr 1930
-- oder nach dem Jahr 2020 gedreht wurden.
-- Verwenden Sie UNION/UNION ALL, um die beiden Teilmengen (vor 1930 bzw. nach 2020)
-- zusammenzusetzen.
-- Duplikate im Ergebnis sind erlaubt.
-- Erwartete Spaltennamen: title, character, name
SELECT m.title, p.character, n.name 
FROM moviedb2.movie m 
JOIN moviedb2.plays p ON p.movie = m.id 
JOIN moviedb2.person n ON n.id = p.player
WHERE type = 'C' 
AND m.year < 1930

UNION ALL

SELECT m.title, p.character, n.name 
FROM moviedb2.movie m 
JOIN moviedb2.plays p ON p.movie = m.id 
JOIN moviedb2.person n ON n.id = p.player
WHERE type = 'C' 
AND m.year > 2020; 
-- DBS2.1.2.c::
-- Finden Sie die Titel (TITLE) aller Kinofilme (d.h. Type=C), sowie die darin
-- auftretenden Charaktere (CHARACTER) und Namen (NAME) des Schauspielers
-- der Schauspielerin des Charakters.
-- Geben Sie nur die Informationen für Filme aus, die entweder vor dem Jahr 1930
-- oder nach dem Jahr 2020 gedreht wurden.
-- Verwenden Sie diesmal kein UNION/UNION ALL, um die beiden Teilmengen
-- (vor 1930 bzw. nach 2020) zusammenzusetzen.
-- Duplikate im Ergebnis sind erlaubt.
-- Erwartete Spaltennamen: title, character, name
SELECT m.title, p.character, n.name 
FROM moviedb2.movie m 
JOIN moviedb2.plays p ON p.movie = m.id 
JOIN moviedb2.person n ON n.id = p.player
WHERE type = 'C' 
AND (m.year < 1930 OR m.year > 2020);

-- DBS2.1.2.d::
-- Finden Sie die Titel (TITLE) aller Kinofilme (Type=C), für die es keinen Regisseur in der Datenbank gibt.
-- Formulieren Sie die Anfrage dabei ohne die Verwendung von EXISTS.
-- Es sollen keine Duplikate im Ergebnis enthalten sein.
-- Erwartete Spaltennamen: title
SELECT DISTINCT  m.title 
FROM moviedb2.movie m 
LEFT JOIN moviedb2.directs p ON p.movie = m.id
WHERE m.type = 'C'
AND director IS NULL; 

-- DBS2.1.2.e::
-- Finden Sie die Titel (TITLE) aller Kinofilme (Type=C), für die es keinen Regisseur in der Datenbank gibt.
-- Formulieren Sie die Anfrage diesmal mit EXISTS. Es sollen keine Duplikate im Ergebnis enthalten sein.
-- Falls sie EXISTS nicht kennen, recherchieren Sie ggf. die Verwendung dieser Klausel.
-- Erwartete Spaltennamen: title
SELECT DISTINCT m.title
FROM moviedb2.movie m
WHERE m.type = 'C'
AND NOT EXISTS (
	SELECT 1 
	FROM moviedb2.directs d
	WHERE d.movie = m.id
	);
	
-- DBS2.1.2.f::
-- Geben sie alle Kinofilme des Jahres 1960 (Type=C; Spalten MID für MOVIE.ID und TITLE) mit ihren Regisseuren
-- (PID für PERSON.ID und NAME) und Ratings (RATING) aus. Sortieren Sie das Ergebnis nach Regisseur
-- und pro Regisseur nach Rating absteigend, bei gleichem Regisseur und Rating nach Movie-ID aufsteigend.
-- Erwartete Spaltennamen: mid, title, pid, name, rating
SELECT m.id AS mid, m.title AS title, d.director AS pid, n.name AS name, r.rating AS rating
FROM moviedb2.movie m 
JOIN moviedb2.directs d ON d.movie = m.id 
JOIN moviedb2.person n ON d.director = n.id
JOIN moviedb2.rating r ON r.movie = m.id  
WHERE type = 'C' AND year = 1960
ORDER BY n.name ASC, r.rating DESC, m.id ASC; 

