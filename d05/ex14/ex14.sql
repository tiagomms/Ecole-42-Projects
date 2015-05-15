select etage_salle AS etage, sum(nbr_siege) AS sieges
FROM salle
GROUP BY etage_salle
ORDER BY SUM(nbr_siege) DESC;