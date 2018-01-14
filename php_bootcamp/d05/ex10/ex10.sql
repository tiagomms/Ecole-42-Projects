SELECT film.titre AS 'Titre', resum AS 'Resume', annee_prod FROM film
INNER JOIN genre ON film.id_genre = genre.id_genre
WHERE genre.nom = 'erotic'
ORDER BY film.annee_prod DESC;