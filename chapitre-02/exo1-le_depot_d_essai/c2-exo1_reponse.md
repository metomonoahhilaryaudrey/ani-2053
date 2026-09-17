# Exercice1: Le dépot d'essai

### L’objectif est de créer un dépôt Git vide, d’ajouter trois fichiers en réalisant trois commits différents, puis d’afficher l’historique des commits sous forme de liste et de graphe.

# Etape 1: Création du dépot
On transforme le dossier en dépôt Git avec la commande :
```git init```
Cette commande crée un dépôt Git vide dans le dossier.
# Etape 2: Création des trois commits

j'ai creer un premier fichier
# Fichier1.txt 
Ensuite j'ai creer un premier commit avec la commande:
```git commit -m "initialisation du projet"```
Le premier fichier est maintenant enregistré dans l'historique du dépôt.

J'ai ensuite creer un deuxieme fichier
# Fichier2.txt
Puis j'ai créer le deuxieme commit avec la commande:
```git commit -m "initialisation du fichier2"```
Le deuxième fichier est maintenant enregistré dans un commit distinct du premier.

Enfin j'ai créer un troisieme fichier
# Fichier3.txt
J'ai de ce fait créer un troisieme commit avec la commande
```git commit -m "initialisation du projet3"```


# Etape 3: Historique en une ligne par commit

Pour afficher l'historique on va utiliser la commande:
```git log --oneline```
On obtient donc:
50198cf(HEAD->main) initialisation du projet 3
c75a2eb initialisation du fichier 2
8d8f8d7 initialisation du projet

# Etape 4: Affichons le graphe des commits
Enfin, on affiche l'historique sous forme de graphe avec :

*50198cf(HEAD-> main) initialisation du projet 3
*c75a2eb initialisation du fichier 2
*8d8f8d initialisation du projet

# Conclusion

Cet exercice nous a permis de mettre en pratique les principales commandes de base de Git. Nous avons créé un dépôt Git vide, ajouté trois fichiers en réalisant trois commits distincts, puis consulté l’historique . Enfin, l’affichage du graphe  nous a permis de visualiser l’enchaînement des différents commits. Cet exercice permet ainsi de mieux comprendre le fonctionnement des commits et le suivi de l’évolution d’un projet avec Git.
