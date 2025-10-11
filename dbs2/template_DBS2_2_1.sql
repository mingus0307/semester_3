-- DBS2.2.1.a::
-- Ermitteln Sie die Laufzeit von Kinofilmen (Type=C) aus dem Jahr 1990. Die Laufzeit ist in der Tabelle MOVIECOUNTRY
-- zu finden. Allerdings ist die Tabelle nicht vollständig. Geben Sie daher für Filme ohne einen Eintrag in
-- MOVIECOUNTRY den Wert 1 aus. Für manche Filme sind auch Laufzeiten in unterschiedlichen Ländern angegeben, ver-
-- wenden Sie in diesem Fall die maximale Laufzeit.
-- Hinweise: Verwenden Sie einen passenden OUTER JOIN, die Funktion COALESCE, sowie abschließend eine Gruppierung.
-- Erwartete Spaltennamen: id, title, weeks
SELECT m.id, m.title, COALESCE(MAX(mc.weeks), 1) AS weeks
FROM moviedb2.movie m
LEFT OUTER JOIN moviedb2.moviecountry mc ON m.id = mc.movie 
WHERE m.type='C' AND m.year = 1990 
GROUP BY m.id, m.title; 

-- DBS2.2.1.b::
-- Finden Sie ID und Titel aller Kinofilme (type = 'C') aus dem Jahr 1990 und die Anzahl der darin
-- auftretenden Charaktere. Geben Sie nur Kinofilme aus, für die mindestens 15 Charaktere gespeichert sind.
-- Erwartete Spaltennamen: id, title, chr_count
SELECT m.id, m.title, COUNT(*) AS chr_count
FROM moviedb2.movie m
JOIN moviedb2.plays pl ON m.id = pl.movie
WHERE m.type = 'C' AND m.year = 1990
GROUP BY m.id, m.title
HAVING COUNT(*) >= 15;
-- DBS2.2.1.c::
-- Berechnen Sie das durchschnittliche Rating für Regisseure von Kinofilmen (d.h. Type=C)
-- aus den Jahren 1960 bis 1969. D.h.: selektieren Sie alle Regisseure, die in den Jahren 1960 bis 1969
-- mindestens einen Kinofilm hatten, und berechnen Sie für jeden dieser Regisseure das durchschnittliche
-- Rating über alle Kinofilme des Regisseurs in diesen Jahren.
-- Erwartete Spaltennamen: name, rating
WITH regs AS (
    SELECT p.name, p.id
    FROM moviedb2.person p
    WHERE EXISTS (
        SELECT 1
        FROM moviedb2.directs d
        JOIN moviedb2.movie m ON d.movie = m.id
        WHERE d.director = p.id
          AND m.type = 'C'
          AND m.year BETWEEN 1960 AND 1969
    )
)
SELECT r.name, AVG(ra.rating) AS rating
FROM regs r
JOIN moviedb2.directs d ON r.id = d.director
JOIN moviedb2.movie m ON d.movie = m.id
JOIN moviedb2.rating ra ON m.id = ra.movie
WHERE m.type = 'C'
  AND m.year BETWEEN 1960 AND 1969
GROUP BY r.name;


-- DBS2.2.1.d::
-- Verwenden Sie das Ergebnis aus Aufgabe DBS2.2.1.c, um die Regisseure mit dem besten sowie die mit dem
-- schlechtesten durchschnittlichen Rating in den Jahren 1960 bis 1969 zu ermitteln, d.h. Sie müssen die
-- Lösung zur vorherigen Aufgabe als Unterabfrage verwenden, und diese so einschränken, dass nur die Top
-- bzw. Flop-Regisseure gelistet werden.
-- Hinweise:
-- 1) Verwenden Sie Common Table Expressions, um einen lesbaren und strukturierten Query
-- zu erhalten.
-- 2) Gehen Sie schrittweise vor: Ermitteln Sie zunächst das Maximum und Minimum der durchschnittlichen
-- Bewertungen; selektieren Sie dann die Regisseure, denen Rating einer dieser beiden Werte ist. Sie
-- finden in der Vorlesung ein ähnliches Beispiel; die Lösung zu dieser Aufgabe ist
-- allerdings etwas komplizierter, da sie nicht auf eine Tabelle, sondern das Ergebnis einer anderen
-- Abfrage zugreifen, und da sowohl MIN als auch MAX gesucht werden soll.
-- Erwartete Spaltennamen: name, rating
WITH reg_rat AS (
	WITH regs AS (
		SELECT p.name, p.id
		FROM moviedb2.person p
		WHERE EXISTS (
			SELECT 1
			FROM moviedb2.directs d
			JOIN moviedb2.movie m ON d.movie = m.id 
			WHERE d.director = p.id 
			AND type = 'C' 
			AND m.year BETWEEN 1960 AND 1969
		)
	)
	SELECT r.name, AVG(ra.rating) AS rating
	FROM regs r 
	JOIN moviedb2.directs d ON r.id = d.director 
	JOIN moviedb2.movie m ON d.movie = m.id 
	JOIN moviedb2.rating ra ON m.id = ra.movie
	WHERE m.type = 'C' 
	AND m.year BETWEEN 1960 AND 1969
	GROUP BY r.name 
),
min_max AS (
	SELECT MIN(rating) AS min_rating, MAX(rating) AS max_rating
	FROM reg_rat
)
SELECT rr.name, rr.rating
FROM reg_rat rr
JOIN min_max mm
  ON rr.rating = mm.min_rating OR rr.rating = mm.max_rating;
-- DBS2.2.1.e::
-- Wiederholen Sie Aufgabe DBS2.2.1.d, verwenden Sie jetzt aber die Analytische Funktion RANK, um die Regisseure
-- mit dem besten bzw. schlechtesten durchschnittlichen Rating zu ermitteln. Beachten Sie dabei, dass man
-- jederzeit auch mehrere Analytische Funktionen parallel mit unterschiedlichen Parametern verwenden kann,
-- d.h. sie können einmal den RANK nach Rating aufsteigend und einmal den RANK nach Rating absteigend er-
-- mitteln. Dann können Sie in der letzten Abfrage die Datensätze selektieren, bei denen entweder der erste RANK
-- 1 (Top bzgl. aufsteigender Sortierung) oder der zweite RANK 1 (d.h. Top bzgl. absteigender Sortierung) ist.
-- Erwartete Spaltennamen: name, rating
WITH average_rating AS (
    SELECT p.name, AVG(ra.rating) AS rating
    FROM moviedb2.person p
    JOIN moviedb2.directs d ON p.id = d.director
    JOIN moviedb2.movie m ON d.movie = m.id
    JOIN moviedb2.rating ra ON m.id = ra.movie
    WHERE m.type = 'C'
      AND m.year BETWEEN 1960 AND 1969
    GROUP BY p.name
),
ranks AS (
    SELECT 
        name,
        rating,
        RANK() OVER (ORDER BY rating ASC) AS r1,
        RANK() OVER (ORDER BY rating DESC) AS r2
    FROM average_rating
)
SELECT name, rating
FROM ranks
WHERE r1 = 1
   OR r2 = 1;



