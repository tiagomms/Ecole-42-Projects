SELECT COUNT(id_membre) AS 'films' FROM historique_membre
WHERE (date(historique_membre.date) <= '2007-07-27' AND date(historique_membre.date) >= '2006-10-30')
OR (DAY(historique_membre.date) = '24' AND month(historique_membre.date) = '12');
