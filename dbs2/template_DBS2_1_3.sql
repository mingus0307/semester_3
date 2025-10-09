-- DBS2.1.3.a::
-- Berechnen Sie die Summe aller Budgets (SUMME) sowie das minimale (MIN) und
-- maximale Budget (MAX) für alle Kinofilme (Type=C) des Jahres 1989, bei denen das Budget
-- in USD angegeben ist. (eine Anfrage!). Hinweis: verwenden Sie ... like '%USD%' ...
-- Erwartete Spaltennamen: summe, min, max
SELECT SUM(b.budget) AS summe, MIN(b.budget) AS min, MAX(b.budget) AS max
FROM moviedb2.budget b 
JOIN moviedb2.movie m ON b.movie = m.id 
WHERE m.type = 'C' AND m.year = 1989 AND b.currency_symbol LIKE '%USD%';

-- DBS2.1.3.b::
-- Ermitteln Sie alle Genres, die in Kinofilmen aus dem Jahr 1960 eingesetzt wurden zusammen mit der Anzahl von
-- Kinofilmen (Type C), in denen sie in dem Jahr verwendet wurden. (Jedes Genre sollte nur einmal auftauchen!).
-- Erwartete Spaltennamen: genre, anzahl
SELECT DISTINCT g.genre AS genre, COUNT(m.id) AS anzahl
FROM moviedb2.genre g 
JOIN moviedb2.movie m ON m.id = g.movie 
WHERE m.year = 1960 AND m.type = 'C'  
GROUP BY g.genre; 

-- DBS2.1.3.c::
-- Ermitteln Sie alle Genres, die in Kinofilmen aus dem Jahr 1960 eingesetzt wurden zusammen mit der Anzahl von
-- Kinofilmen (Type C), in denen sie in dem Jahr verwendet wurden. (Jedes Genre sollte nur einmal auftauchen!).
-- Schränken Sie die Abfrage so ein, dass nur Genres aufgelistet werden, zu denen es in 1960 mindestens
-- 100 Kinofilme gab.
-- Erwartete Spaltennamen: genre, anzahl
SELECT g.genre AS genre, COUNT(m.id) AS anzahl
FROM moviedb2.genre g 
JOIN moviedb2.movie m ON m.id = g.movie 
WHERE m.year = 1960 AND m.type = 'C'
GROUP BY g.genre 
HAVING COUNT(m.id) >= 100; 

-- DBS2.1.3.d::
-- Ermitteln Sie alle Genres, die in Kinofilmen aus dem Jahr 1960 eingesetzt wurden zusammen mit der Anzahl von
-- Kinofilmen (Type C), in denen sie in dem Jahr verwendet wurden. (Jedes Genre sollte nur einmal auftauchen!).
-- Schränken Sie die Abfrage so ein, dass nur Genres aufgelistet werden, zu denen es in 1960 mindestens
-- 100 Kinofilme gab.
-- Sortieren Sie das Ergebnis nach Häufigkeit absteigend.
-- Erwartete Spaltennamen: genre, anzahl
SELECT g.genre AS genre, COUNT(m.id) AS anzahl
FROM moviedb2.genre g 
JOIN moviedb2.movie m ON m.id = g.movie 
WHERE m.year = 1960 AND m.type = 'C'
GROUP BY g.genre 
HAVING COUNT(m.id) >= 100 
ORDER BY anzahl DESC; 

-- DBS2.1.3.e::
-- Finden Sie ID und Titel aller Kinofilme (Type=C), die mind. einen Nachfolger haben, und die mindestens einmal
-- parodiert wurden. Ein Film hat einen Nachfolger, wenn die ID in der Tabelle FOLLOWS in der Spalte MOVIE
-- verwendet wird. Ein Film wurde parodiert, wenn die ID in der Tabelle SPOOFS in der Spalte SPOOFED verwendet
-- wird. Ein Film soll nur maximal einmal im Ergebnis sein, auch wenn er mehrere Nachfolger und Parodien hat.
-- Erwartete Spaltennamen: id, title
SELECT DISTINCT m.id, m.title
FROM moviedb2.movie m
JOIN moviedb2.follows f ON f.movie = m.id
JOIN moviedb2.spoofs s ON s.spoofed = m.id 
WHERE m.type = 'C'; 

-- DBS2.1.3.f::Sie ID und Titel aller Kinofilme, die entweder mind. einen Nachfolger haben, oder mindestens einmal
-- parod
-- Finden iert wurden, für die aber nicht beides zutrifft.
-- Ein Film soll maximal einmal im Ergebnis sein.
-- Hinweis: Es gibt unterschiedliche Lösungsmöglichkeiten. Denken Sie über Full Outer Joins nach, oder alternativ
-- über Mengenoperationen.
-- Erwartete Spaltennamen: id, title
-- Symmetrische Differenz zwischen Filmen mit Nachfolger und Filmen mit Parodie
WITH follow_ids AS (
    SELECT DISTINCT movie AS id FROM moviedb2.follows
),
spoof_ids AS (
    SELECT DISTINCT spoofed AS id FROM moviedb2.spoofs
),
xor_ids AS (
    SELECT id FROM follow_ids
    WHERE id NOT IN (SELECT id FROM spoof_ids)
    UNION
    SELECT id FROM spoof_ids
    WHERE id NOT IN (SELECT id FROM follow_ids)
)
SELECT m.id, m.title
FROM moviedb2.movie m
JOIN xor_ids x ON x.id = m.id
WHERE m.type = 'C';






