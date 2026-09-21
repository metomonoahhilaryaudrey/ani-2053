## Exercice8: Six manieres de défaire

Objectif du devoir

L’objectif de ce devoir est de mettre en pratique les principales commandes Git permettant de corriger des erreurs et de récupérer un travail.

Plus précisément, il s’agit de provoquer volontairement puis de résoudre six situations courantes :

1. annuler une modification non voulue ;
2. retirer un fichier ajouté par erreur avec git restore --staged ;
3. annuler un commit de trop avec git reset ;
4. annuler un commit déjà poussé avec git revert ;
5. mettre temporairement de côté un travail en cours avec git stash ;
6. retrouver un commit qui semble perdu grâce à git reflog.

ce travail se fera dans le clone2.

## 1  Modification non voulue

J'ai modifié volontairement un fichier,ensuite j'ai vérifié et j'ai annulé la modification
**Resultat**

PS C:\Users\HP\Desktop\TP Git\clone2> `Set-Content "tp-annulation.txt" "Modification non voulue"`
PS C:\Users\HP\Desktop\TP Git\clone2> git diff
diff --git a/tp-annulation.txt b/tp-annulation.txt
index 574c7bb..362adcd 100644
--- a/tp-annulation.txt
+++ b/tp-annulation.txt
@@ -1 +1 @@
-Version initiale du fichier
+Modification non voulue
PS C:\Users\HP\Desktop\TP Git\clone2> `git restore tp-annulation.txt`
PS C:\Users\HP\Desktop\TP Git\clone2> `git diff`
Aucune différence ne s'affiche.

## Conclusion: `git restore` permet d'annuler une modification locale non voulue.

## 2 Un add de trop

J'ai créé deux fichiers:


`Set-Content "fichier-correct.txt" "À conserver"
Set-Content "fichier-erreur.txt" "Ajouté par erreur"`

apres je les ai ajouté avec `git add .` les deux fichiers apparaissent dans les changements a valider.
Ensuite j'ai retiré le mauvais fichier.

Resultat:

PS C:\Users\HP\Desktop\TP Git\clone2> `git add .`
PS C:\Users\HP\Desktop\TP Git\clone2> `git status`
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   fichier-correct.txt
        new file:   fichier-erreur.txt

PS C:\Users\HP\Desktop\TP Git\clone2> `git restore --staged fichier-erreur.txt`
PS C:\Users\HP\Desktop\TP Git\clone2> `git status`
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   fichier-correct.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier-erreur.txt

  ## Conclusion: `git restore --staged`peremt d'annuler un git add sans supprimer le fichier.

  ## 3 Un commit de trop

  J'ai créé volontairement un mauvais commit et j'ai  supprimer ce commit  avant de l'envoyer sur Github.
  Resultat:

  PS C:\Users\HP\Desktop\TP Git\clone2> `Set-Content "commit-trop.txt" "Commit inutile"`
PS C:\Users\HP\Desktop\TP Git\clone2> `git add commit-trop.txt`
PS C:\Users\HP\Desktop\TP Git\clone2> `git commit -m "Commit de trop"`
[main 0cdafe8] Commit de trop
 2 files changed, 2 insertions(+)
 create mode 100644 commit-trop.txt
 create mode 100644 fichier-correct.txt
PS C:\Users\HP\Desktop\TP Git\clone2> `git reset --soft HEAD~1`

# Conclusion: `git reset` permet de revenir au commit précédent lorsque le commit n'a pas encore été paratgé.

## 4 Un commit deja poussé qu'il faut annuler

j'ai créé un commit, ensuite je l'ai annulé avec les commandes.
Resultat: 

PS C:\Users\HP\Desktop\TP Git\clone2> Set-Content "commit-pousse.txt" "Modification à annuler"
PS C:\Users\HP\Desktop\TP Git\clone2>` git add commit-pousse.txt`
PS C:\Users\HP\Desktop\TP Git\clone2>` git commit -m "Modification à annuler"`
[main c94c444] Modification à annuler
 3 files changed, 3 insertions(+)
 create mode 100644 commit-pousse.txt
 create mode 100644 commit-trop.txt
 create mode 100644 fichier-correct.txt
PS C:\Users\HP\Desktop\TP Git\clone2> `git push origin main`
To https://github.com/metomonoahhilaryaudrey/ani-2053.git

# Conclusion: `git revert` créé un nouveau commit qui annule les effets d'un commitdéja partagé,

## 5 Mettre un trvail en cours de coté

j'ai modifié un travial,ensuite j'ai mis de coté,puis j'ai vérifié et enfin j'ai recuperer le dit travail.

Resultat:

PS C:\Users\HP\Desktop\TP Git\clone2> `Set-Content "travail-en-cours.txt" "Travail non terminé"`
PS C:\Users\HP\Desktop\TP Git\clone2>` git stash push -m "Travail en cours"`
No local changes to save
PS C:\Users\HP\Desktop\TP Git\clone2> `git stash list`
PS C:\Users\HP\Desktop\TP Git\clone2> `git stash pop`

# Conclusion: `git stash` permet de mettre temporairement un travail de coté sans créér de commit.

## 6 Retrouver un commit perdu

j'ai creer un commit,ensuite j'ai fait disparaitre le commit de la branche ,puis j'ai retrouv. le commit
Resultat:

PS C:\Users\HP\Desktop\TP Git\clone2> Set-Content "commit-perdu.txt" "Commit à retrouver"
PS C:\Users\HP\Desktop\TP Git\clone2> git add commit-perdu.txt
PS C:\Users\HP\Desktop\TP Git\clone2> git commit -m "Commit à retrouver"
[main 8cb2de0] Commit à retrouver
 1 file changed, 1 insertion(+)
 create mode 100644 commit-perdu.txt
PS C:\Users\HP\Desktop\TP Git\clone2> git reset --hard HEAD~1
HEAD is now at 6180acc Revert "Modification à annuler"
PS C:\Users\HP\Desktop\TP Git\clone2> git reflog
6180acc (HEAD -> main) HEAD@{0}: reset: moving to HEAD~1
8cb2de0 HEAD@{1}: commit: Commit à retrouver
6180acc (HEAD -> main) HEAD@{2}: revert: Revert "Modification à annuler"
c94c444 HEAD@{3}: commit: Modification à annuler
a3098b2 HEAD@{4}: reset: moving to HEAD~1
0cdafe8 HEAD@{5}: commit: Commit de trop
a3098b2 HEAD@{6}: commit: Création du fichier pour les annulations
65b68b4 (origin/main, origin/HEAD) HEAD@{7}: pull origin main: Merge made by the 'ort' strategy.
6d08bc6 HEAD@{8}: commit: Modification de la partie 4
9caabeb HEAD@{9}: commit: Création du fichier pour la fusion automatique
ea4018f HEAD@{10}: commit: Modification de la ligne 6
6008c22 HEAD@{11}: pull origin main: Fast-forward
5d6d4aa HEAD@{12}: commit (merge): Résolution du conflit entre les deux clones
ba26f1e HEAD@{13}: commit: Modification du fichier depuis le clone 2
b1cc96d HEAD@{14}: clone: from https://github.com/metomonoahhilaryaudrey/ani-2053.git
on recupere avec `git switch recuperation`

# Conclusion: `git reflog` permet de retrouver un commit qui n'apparait plus dans l'historique normal.