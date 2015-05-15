SELECT upper(f.nom) AS NOM, f.prenom, a.prix FROM fiche_personne f
INNER JOIN membre m ON f.id_perso = m.id_fiche_perso 
INNER JOIN abonnement a ON m.id_abo = a.id_abo
WHERE a.prix > 42
ORDER BY f.nom, f.prenom ASC;