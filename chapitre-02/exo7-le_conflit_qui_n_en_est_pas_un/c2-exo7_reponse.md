## Exercice7: Le conflit qui n'en ai pas un

j'ai utilisé deux clones d'un meme dépot git:

* clone1 représente le travail de la première personne ;
* clone2 représente le travail de la deuxième personne.

Les deux personnes vont modifier le même fichier fusion-auto.txt, mais elles ne vont pas modifier les mêmes lignes :

* la personne travaillant dans clone1 modifiera la partie 2 ;
* la personne travaillant dans clone2 modifiera la partie 4.

Je passe donc au fichier commun:

## Création du fichier commun
Dans le clone 2, j'ai créé le fichier `fusion-auto.txt`
la commande utiliséé:
 @"
>> Partie 1 : Présentation
>> Partie 2 : Description
>> Partie 3 : Fonctionnement
>> Partie 4 : Résultats
>> Partie 5 : Conclusion
>> "@ | Set-Content "fusion-auto.txt"
le resultat:
Partie 1 : Présentation
Partie 2 : Description
Partie 3 : Fonctionnement
Partie 4 : Résultats
Partie 5 : Conclusion
 Le fichier commun a donc été correctement créé.

 Ensuite,j'ai demandé a gi de suivre le nouveau fichier avec la commande:
 `git add fusion-auto.txt`
 ensuite, j'ai créé le commit: `git commit -m "Création du fichier pour la fusion automatique"`
 le resultat:
 [main 9caabeb] Création du fichier pour la fusion automatique
 1 file changed, 5 insertions(+)
 create mode 100644 fusion-auto.txt

 Ensuite, j'ai envoyé le commit sur Github avec la commande: `git push origin main`
 Resultat:
 Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 388 bytes | 388.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
   ea4018f..9caabeb  main -> main

Le fichier fusion-auto.txt se trouve donc sur Github.

## Récupération du fichier dans clone1:
PS C:\Users\HP\Desktop\TP Git\clone1> `git pull origin main`
remote: Enumerating objects: 8, done.
remote: Counting objects: 100% (8/8), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 6 (delta 3), reused 5 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (6/6), 657 bytes | 17.00 KiB/s, done.
From https://github.com/metomonoahhilaryaudrey/ani-2053
 * branch            main       -> FETCH_HEAD
   6008c22..9caabeb  main       -> origin/main
Updating 6008c22..9caabeb
Fast-forward
 deux-modifications.txt | 2 +-
 fusion-auto.txt        | 5 +++++
 2 files changed, 6 insertions(+), 1 deletion(-)
 create mode 100644 fusion-auto.txt
PS C:\Users\HP\Desktop\TP Git\clone1> 
# Vérification:
`Get-Content fusion-auto.txt`
Resultat:
Partie 1 : Présentation
Partie 2 : Description
Partie 3 : Fonctionnement
Partie 4 : Résultats
Partie 5 : Conclusion

Ensuite ,j'ai fait une premiere modification: Dans le clone 1
La premiere personne travaille désormais dans le clone1.
elle modifie la partie 2 du fichier.
la commande utiliséé:
`(Get-Content "fusion-auto.txt") -replace 'Partie 2 : Description', 'Partie 2 : Description détaillée du projet' | Set-Content "fusion-auto.txt"`

Ensuite j'ai vérifié la modification avec `git diff`
diff --git a/fusion-auto.txt b/fusion-auto.txt
index 32de5ba..a2e080e 100644
--- a/fusion-auto.txt
+++ b/fusion-auto.txt
@@ -1,5 +1,5 @@
 Partie 1 : Pr<E9>sentation
-Partie 2 : Description
+Partie 2 : Description d<E9>taill<E9>e du projet
 Partie 3 : Fonctionnement
 Partie 4 : R<E9>sultats

 Ensuite j'ai ajouté la modification et créé le commit
 Resultat
 `git add fusion-auto.txt`
PS C:\Users\HP\Desktop\TP Git\clone1>` git commit -m "Modification de la partie 2"`
[main eb78d43] Modification de la partie 2
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\HP\Desktop\TP Git\clone1> `git push origin main`
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 317 bytes | 317.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
   9caabeb..eb78d43  main -> main

# ensuite modification de la partie 4 dans le clone 2

PS C:\Users\HP\Desktop\TP Git\clone2> git add fusion-auto.txt
PS C:\Users\HP\Desktop\TP Git\clone2> `git commit -m "Modification de la partie 4"`
[main 6d08bc6] Modification de la partie 4
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\HP\Desktop\TP Git\clone2> `git pull origin main`
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 297 bytes | 14.00 KiB/s, done.
From https://github.com/metomonoahhilaryaudrey/ani-2053
 * branch            main       -> FETCH_HEAD
   9caabeb..eb78d43  main       -> origin/main
Auto-merging fusion-auto.txt
Merge made by the 'ort' strategy.
 fusion-auto.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
 ## ensuite j'ai vérifiéé la fusion
 PS C:\Users\HP\Desktop\TP Git\clone2> Get-Content fusion-auto.txt
Partie 1 : Présentation
Partie 2 : Description détaillée du projet
Partie 3 : Fonctionnement
Partie 4 : Résultats obtenus
Partie 5 : Conclusion

git compare donc les modifications dans les deux versions du fichier donc pas de conflit.

j'ai vérifié l'historique
PS C:\Users\HP\Desktop\TP Git\clone2> `git log --oneline --graph --all -8`
*   65b68b4 (HEAD -> main) Merge branch 'main' of https://github.com/metomonoahhilaryaudrey/ani-2053
|\
| * eb78d43 (origin/main, origin/HEAD) Modification de la partie 2
* | 6d08bc6 Modification de la partie 4
|/
* 9caabeb Création du fichier pour la fusion automatique
* ea4018f Modification de la ligne 6
* 6008c22 Création du fichier commun
* 642ee29 Add files via upload
*   5d6d4aa Résolution du conflit entre les deux clones
## Resultat final:
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
PS C:\Users\HP\Desktop\TP Git\clone2> git push origin main
Enumerating objects: 10, done.
Counting objects: 100% (10/10), done.
Delta compression using up to 12 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 640 bytes | 320.00 KiB/s, done.
Total 6 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), completed with 2 local objects.
To https://github.com/metomonoahhilaryaudrey/ani-2053.git
   eb78d43..65b68b4  main -> main
   ## Conclusion: 
   Aucun conflit n'a été généré parce que les deux personnes ont travaillés sur des parties différentes.