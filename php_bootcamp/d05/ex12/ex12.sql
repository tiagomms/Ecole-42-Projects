SELECT nom, prenom FROM fiche_personne f
WHERE nom LIKE '%-%' OR
prenom LIKE '%-%' 
ORDER BY nom, prenom ASC;