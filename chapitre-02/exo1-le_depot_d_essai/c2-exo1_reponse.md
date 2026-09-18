# Exercice 1 : Le dépôt d'essai
Suite au remarques du prof l'exercice 1 a été refait ce 18 septembre 2026

Objectif

L'objectif de cet exercice est de créer un dépôt Git vide, d'ajouter trois fichiers en réalisant trois commits différents, puis d'afficher l'historique des commits sous forme de liste et de graphe.

# Étape 1 : Création du dépôt

Tout d'abord, je me suis placé dans le dossier du projet, puis j'ai transformé ce dossier en dépôt Git avec la commande :

``git init``

Cette commande crée un nouveau dépôt Git vide dans le dossier courant.

# Étape 2 : Création des trois commits
Premier fichier

J'ai tout d'abord créé un premier fichier nommé :

Fichier1.txt

Après avoir créé le fichier, je l'ai ajouté à la zone de préparation avec la commande :

``git add Fichier1.txt``

Puis j'ai créé le premier commit avec la commande :

``git commit -m "initialisation du projet1"``

Le fichier Fichier1.txt est maintenant enregistré dans l'historique du dépôt.

Deuxième fichier

J'ai ensuite créé un deuxième fichier nommé :

Fichier2.txt

Je l'ai ajouté à la zone de préparation avec la commande :

``git add Fichier2.txt``

Puis j'ai créé le deuxième commit avec la commande :

``git commit -m "initialisation du fichier2"``

Le fichier Fichier2.txt est maintenant enregistré dans un commit distinct du premier.

Troisième fichier

Enfin, j'ai créé un troisième fichier nommé :

Fichier3.txt

Je l'ai ajouté à la zone de préparation avec la commande :

``git add Fichier3.txt``

Puis j'ai créé le troisième commit avec la commande :

``git commit -m "initialisation du projet3"``

Le fichier Fichier3.txt est maintenant enregistré dans un troisième commit distinct.

# Étape 3 : Affichage de l'historique en une ligne par commit

Pour afficher l'historique des commits sous forme d'une ligne par commit, j'ai utilisé la commande :

``git log --oneline``

J'obtiens alors :

50198cf (HEAD -> main) initialisation du projet3
c75a2eb initialisation  du fichier2
8d8f8d7 initialisation du projet1

Cette commande permet d'afficher de manière concise l'identifiant abrégé de chaque commit ainsi que son message.

On peut également constater que HEAD -> main indique que le commit le plus récent correspond actuellement à la branche main.

# Étape 4 : Affichage du graphe des commits

Pour afficher l'historique sous forme de graphe, j'ai utilisé la commande :

``git log --oneline --graph``

La sortie obtenue est :

* 50198cf (HEAD -> main) initialisation du projet3
* c75a2eb initialisation du fichier2
* 8d8f8d7 initialisation du projet1

Dans cet exemple, les trois commits sont réalisés successivement sur la même branche. Le graphe est donc linéaire et se présente simplement sous la forme d'une colonne d'étoiles.

La commande`` --graph`` permet cependant de représenter visuellement les différentes branches, les divergences et les fusions lorsqu'elles existent.

# Étape 5 : Création d'un graphe avec une branche et une fusion

Afin de mieux mettre en évidence l'intérêt de l'affichage graphique de Git, j'ai également créé une branche à partir de main.

J'ai créé une nouvelle branche avec :

``git branch nouvelle-branche``

Puis je me suis placé sur cette branche :

``git switch nouvelle-branche``


Je suis ensuite revenu sur la branche principale :

git switch main

Je l'ai ajouté avec :

git addionné la branche nouvelle-branche dans main avec la commande :

``git merge nouvelle-branche``

Enfin, j'ai affiché le graphe complet avec :

À ce stade, les branches main et nouvelle-branche ont évolué séparément.


Le résultat permet alors de visualiser la séparation des branches et leur jonction après la fusion. Contrairement au premier graphe, on peut observer des lignes verticales et obliques représentant les différentes branches.

Conclusion

Cet exercice m'a permis de mettre en pratique les principales commandes de base de Git.

J'ai tout d'abord créé un dépôt Git avec git init, puis j'ai créé trois fichiers et réalisé trois commits distincts. Lors de chaque ajout, j'ai utilisé git add afin de placer le fichier dans la zone de préparation avant de créer le commit avec git commit.

J'ai ensuite utilisé git log --oneline pour consulter l'historique des commits sous une forme concise.

Enfin, j'ai utilisé git log --oneline --graph pour représenter graphiquement l'historique. Avec trois commits successifs sur une seule branche, le graphe est naturellement linéaire. La création d'une branche, suivie de commits différents et d'une fusion, permet de mieux comprendre l'intérêt de cette représentation graphique : elle permet de visualiser les divergences et les jonctions entre les différentes branches.

Cet exercice permet ainsi de mieux comprendre le fonctionnement des commits, des branches et des fusions, ainsi que le suivi de l'évolution d'un projet avec Git.
