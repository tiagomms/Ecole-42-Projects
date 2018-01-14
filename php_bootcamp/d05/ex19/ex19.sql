SELECT DATEDIFF(MAX(date), MIN(date)) AS uptime FROM historique_membre
GROUP BY id_film;