## Exercice 6: Le conflit provoqué

Pour commencer, J'ai creé un dossier permettant de regrouper les deux clones:

TP Git
├── clone1
└── clone2
j'ai cloné le dépot Github dans le clone1.
`git clone https://github.com/metomonoahhilaryaudrey/ani-2053.git clone1`
ensuite j'ai tapé `cd clone1`
j'ai fait pareil pour le clone2.
`git clone https://github.com/metomonoahhilaryaudrey/ani-2053.git clone2`
ensuite, j'ai tapé: cd `clone2`

j'ai modifié la meme ligne du fichier `c1-exo11_reponse.md`dans les deux clones.

## Modification et push dans le clone1

J'ai travaillée dans un premier temps dans le clone1:
j'ai effectué une modification:
PS C:\Users\HP\Desktop\TP Git\clone1> git add c1-exo11_reponse.md
PS C:\Users\HP\Desktop\TP Git\clone1> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   c1-exo11_reponse.md
 j'ai vérifié avec la commande `git diff`

 Apres avoir vérifié la modification, j'ai crée le premier commit avec la commande:
 `git commit -m "Modification dans le clone1"`
 J'ai obtenu:
 [main 68681fa] Modification dans le clone 1
 1 file changed, 1 insertion(+), 1 deletion(-)

 Ensuite j'ai envoyé le commit vers Github.

 Par la suite j'ai fais un premier push:
 `git push origin main`

 PS C:\Users\HP\Desktop\TP Git\clone1> git push origin main
info: please complete authentication in your browser...
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 312 bytes | 156.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
   b1cc96d..68681fa  main -> main
   le premier push a été accepté car le depot distant etait compatible avec l'historique local de clone1.


## Modification dans le clone2
j'ai modifié le meme fichier avec la commande:
PS C:\Users\HP\Desktop\TP Git\clone2> "Version du clone 2" | Set-Content "conflit.txt"
PS C:\Users\HP\Desktop\TP Git\clone2> Get-Content conflit.txt
Version du clone 2. Ensuite j'ai enregistré cette modification avec: `git add conflit.txt`
## Ensuite j'ai crée le deuxieme commit:
PS C:\Users\HP\Desktop\TP Git\clone2> git commit -m "Modification du fichier depuis le clone 2"
[main ba26f1e] Modification du fichier depuis le clone 2
 1 file changed, 1 insertion(+)
 create mode 100644 conflit.txt

 ## Par la suite j'ai fais le deuxieme push:
 PS C:\Users\HP\Desktop\TP Git\clone2> git push origin main
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/metomonoahhilaryaudrey/ani-2053.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.

Le push a étét refusé car le dépot distant avait déja recu un nouveau commit provenant du clone1.Le clone2 ne possedait donc pas donc pas les dernieres modifications du dépot distant. 

Afin de recupérer les changements présents sur Github, j'ai utilisée la commande:

`git pull origin main`
# Resultat:
remote: Enumerating objects: 8, done.
remote: Counting objects: 100% (8/8), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 6 (delta 3), reused 5 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (6/6), 547 bytes | 15.00 KiB/s, done.
From https://github.com/metomonoahhilaryaudrey/ani-2053
 * branch            main       -> FETCH_HEAD
   b1cc96d..544d727  main       -> origin/main
Auto-merging conflit.txt
CONFLICT (add/add): Merge conflict in conflit.txt
Automatic merge failed; fix conflicts and then commit the result.

## Passage a l'identification du conflit:
PS C:\Users\HP\Desktop\TP Git\clone2> Get-Content conflit.txt
<<<<<<< HEAD
Version du clone 2
=======
Version initiale
>>>>>>> 544d727e695d53a140c86aefc3ac089e3fd9c3c4
PS C:\Users\HP\Desktop\TP Git\clone2> @"
>> Version du clone 2
>> Version initiale

## Résolution du conflit

Afin de résoudre le conflit,j'ai tapé la commande:
`Get-Content conflit.txt`
# Resultat:
Version du clone 2
Version initiale

J'ai décidé de supprimer les marqueurs, parce que la résolution consiste a choisir le contenu final qui doit etre conservé. 

Une fois le conflit résolu j'ai executé la commande: `git add conflit.txt` et j'ai vérifié avec `git status` 

## Resultat:
Your branch and 'origin/main' have diverged,
and have 1 and 2 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   c1-exo11_reponse.md
        modified:   conflit.txt

J'ai crée le commit de resolution

` git commit -m "Résolution du conflit entre les deux clones"`
[main 5d6d4aa] Résolution du conflit entre les deux clones.
## Push final et vérification finale

PS C:\Users\HP\Desktop\TP Git\clone2> git push origin main
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (6/6), 636 bytes | 212.00 KiB/s, done.
Total 6 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
   544d727..5d6d4aa  main -> main
PS C:\Users\HP\Desktop\TP Git\clone2> git status
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean.

## Conclusion
Ce travail pratique avait donc  pour objectif de mettre en œuvre Git à travers l’utilisation de deux clones d’un même dépôt GitHub. 