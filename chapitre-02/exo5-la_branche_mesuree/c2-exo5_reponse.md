## Exrecice 5: La branche mesurée
Création d'une branche et réalisation de trois commits avec Git
- Objectif

L'objectif de ce travail est de créer une nouvelle branche Git, d'effectuer trois commits sur cette branche et de mesurer l'évolution de l'espace disque occupé par le dépôt.

Pour commencer,j'ai créer une branche :

## Création de la branche
Le nom de ma branche est `Objet`
J'ai utilisée les commandes:
``git branch objet`` et ``git switch objet``

Apres l'exécution de la commande, la sortie obtenue est la suivante:

Switched to branch 'objet'

J'ai ensuite mesuré la taille du dépot une premiere fois:

Commande utilisée: ``(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum``
La sortie Obtenue est:
**27093**

On observe donc que la taille du depot au départ est de **27 093** octets

## Création du premier commit

J'ai commencé par modifier pour une premiere fois , enssuite j'ai crée le premier commit:

Commandes utilisées:

``git add Fichier.txt``
``git commit -m "Ajoute la premiere modification"``

Le resultat que l'on obtient est:
[objet db4b4fd] Ajoute la premiere modification
 1 file changed, 0 insertions(+), 0 deletions(-)

 ## Création du deuxieme commit

 J'ai ajouté la deuxieme modification, ensuite j'ai doc crée le deuxieme commit:

 Commandes utilisées:
 ``git add Fichier.txt``
 ``git commit -m "Ajoute la deuxieme modification"``

 Le resultat que l'on obtient:
 [objet 62d633a] Ajoute la deuxieme modification
 1 file changed, 0 insertions(+), 0 deletions(-)

 ## Creation du troisieme commit

 Enfin, j'ai ajouté la troisieme modification et j'ai donc creer le troisieme commit:

 Commandes utilisées:
 ``git add Fichier.txt``
 ``git commit -m "Ajoute la troisieme modification"``

 Le resultat que l'on obtient est:
 [objet 36a6c20] Ajoute la troisieme modification
 1 file changed, 0 insertions(+), 0 deletions(-)

Ensuite j'ai mesuré une deuxieme fois:
commande utilisée: ``(Get-ChildItem .git -Recurse -File | Measure-Object -Property Length -Sum).Sum``

Le resultat que j'ai obtenue est:
**29486**
On voit donc que la taille définitive est:
**29 486 octets**

Mesurons maintenant la place que le dépot a gagné
On calcule la différence:
29486-27093= 2393 octets

On conclut donc que le dépot a gagné 2393 octets sur le disque.

Nous allons passer a la vérification de l'historique

## Historique

J'ai utilisée la commande:
``git log --oneline --graph``

Le resultat que l'on obtient est:
* 36a6c20 (HEAD -> objet) Ajoute la troisieme modification
* 62d633a Ajoute la deuxieme modification
* db4b4fd Ajoute la premiere modification
* 1e1ba45 (master) Ajout de Fichier.txt

## Explication du resultat

On constate que la branche `objet` contient donc les trois nouveaux commits.

## Conclusion: La taille du dépot a augmentée apres les commits parce que Git enregistre toutes les modifications utiles apres chaque modification du fichier.
La taille a donc connu une augmentation de **2393** octets.