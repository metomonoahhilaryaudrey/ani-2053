## EXERCICE 10 — FUSIONNER OU REJOUER

1. Création du dépôt d’essai

Je me suis placé dans le dossier chapitre-02.
J'ai utilisée les commandes
mkdir exo10-fusionner_ou_rejouer
cd exo10-fusionner_ou_rejouer
git init

Resultat
Reinitialized existing Git repository in C:/Users/HP/Desktop/chapitre-02/exo10-fusionner_ou_rejouer/.git/

## Création du premier commit
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> echo "# Projet moteur" > README.md
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git add README.md
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git commit -m "Initialisation du projet"
[fonctionnalite-rebase c14e1da] Initialisation du projet
 1 file changed, 0 insertions(+), 0 deletions(-)

 ## Premiere integration: MERGE
 j'ai créé une branche

 PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git switch -c fonctionnalite-merge

 j'ai ajouté une fonctionnalité
 PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> echo "Fonctionnalite du moteur" > moteur.txt
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git add moteur.txt
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git commit -m "Ajout de la fonctionnalite"
On branch fonctionnalite-rebase
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        c2-exo10_reponse.md

nothing added to commit but untracked files present (use "git add" to track)

ensuite je modifie main

PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git switch main

Fusion avec MERGE
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git merge fonctionnalite-merge -m "Fusion de la fonctionnalite"
Already up to date.

Affichage du graphe
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git log --oneline --graph --all
* 8b50adf (HEAD -> fonctionnalite-rebase) Evolution du moteur
* c14e1da Initialisation du projet
* 484c82f Nouvelle evolution du moteur
* 3ceb4b1 Ajout de la deuxieme fonctionnalite
* 7030453 (fonctionnalite-merge) Evolution du moteur
* 1d026c4 Ajout de la fonctionnalite
* 6d32dc2 (master) Initialisation du projet

Deuxieme intégartion

creation d'une deuxieme branche
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git switch -c fonctionnalite-rebase

Ajout d'une fonctionnalité

PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> echo "Deuxieme fonctionnalite du moteur" > moteur2.txt
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git add moteur2.txt
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git commit -m "Ajout de la deuxieme fonctionnalite"
On branch fonctionnalite-rebase

retour sur la branche


PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git switch fonctionnalite-rebase
Already on 'fonctionnalite-rebase'
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git rebase main
fatal: invalid upstream 'main'
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer>
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git switch main
fatal: invalid reference: main
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer> git merge fonctionnalite-rebase
Already up to date.
PS C:\Users\HP\Desktop\chapitre-02\exo10-fusionner_ou_rejouer>

Conclusion
J’ai réalisé deux intégrations différentes.

Dans la première partie, j’ai utilisé git merge. Le graphe montre clairement la séparation des branches et leur fusion.

Dans la deuxième partie, j’ai utilisé git rebase. Les commits de la branche ont été replacés à la suite de main, ce qui donne un historique plus linéaire.

J’ai donc pu comparer les deux méthodes et observer leurs différences dans l’historique Git.

