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