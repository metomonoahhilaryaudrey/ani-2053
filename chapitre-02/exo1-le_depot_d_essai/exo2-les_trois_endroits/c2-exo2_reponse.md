## Exercice 2 — Étape par étape

On part du dépôt que tu as créé dans l'exercice 1, avec tes fichiers Fichier1.txt, Fichier2.txt et Fichier3.txt.

J'ai donc modifié le premier fichier et j'ai affiché ``git status`` étape par étape pour bien observer les changements.

## Apres la modification du fichier

PS C:\Users\HP\Desktop\TestGit> git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   Fichier1.txt
        modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\HP\Desktop\TestGit> 

Git détecte que Fichier1.txt a été modifié, mais la modification n'est pas encore préparée pour être enregistrée dans un commit.

## Resultat de git add

On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   Fichier1.txt
  On constate que      
Avant ``git add``,  disait :

Changes not staged for commit

Après ``git add``, Git dit :

Changes to be committed

Cela signifie que la modification de Fichier1.txt est maintenant dans la zone de préparation (staging area).


## Ensuite le ``git commit``

PS C:\Users\HP\Desktop\TestGit> git commit -m "Modification du Fichier1.txt"
On branch main
Your branch is ahead of 'origin/main' by 5 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
PS C:\Users\HP\Desktop\TestGit> git status
On branch main
Your branch is ahead of 'origin/main' by 5 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
PS C:\Users\HP\Desktop\TestGit> 

De ce fait apres le commit , la modification est enregistrée dans le Repository

En conclusion, on observe des changements entre les sorties:
On voit des changements entre les trois endroits de Git:
Working Tree, Index et Repository

Apres la modification le fichier est dans le working Tree, apres le git add la modification se trouve dans l'index et enfin apres le git commit,la modification est enregistrée dans le repository.


## Conclusion

# Cet exercice m'a permis de mieux comprendre les différentes étapes de l'enregistrement d'une modification avec Git.

