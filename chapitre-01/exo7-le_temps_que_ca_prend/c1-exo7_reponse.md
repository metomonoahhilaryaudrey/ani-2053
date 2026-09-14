Exercice 7 — Le temps que ça prend
Exercice refait apres remarques pertinantes de l'encadreur
# 1. Objectif

Le but de cet exercice est de comparer le temps nécessaire pour effectuer une première construction du workspace avec celui d'une deuxième construction réalisée immédiatement après, sans aucune modification des fichiers.

Cette comparaison permet d'observer concrètement le fonctionnement de la construction incrémentale de Jenga.

# 2. Première construction

J'ai commencé par lancer une construction complète du workspace depuis sa racine.

Sous PowerShell, la commande utilisée est :

Measure-Command { jenga build --config Debug }

Le résultat de la mesure est :

Minutes      : 2
Seconds      : 37
Milliseconds : 120
TotalSeconds : 157.1208435

La première construction a donc duré environ :

157,12 secondes, soit environ 2 minutes et 37 secondes.

Cette première exécution correspond à une construction à froid : les fichiers nécessaires n'ont pas encore été construits ou doivent être générés.

# 3. Deuxième construction

Sans modifier le projet ni les fichiers sources, j'ai immédiatement exécuté la même commande une deuxième fois :

Measure-Command { jenga build --config Debug }

La mesure obtenue est :

Minutes      : 0
Seconds      : 22
Milliseconds : 104
TotalSeconds : 22.1048635

La deuxième construction a donc duré environ :

22,10 secondes.

# 4. Comparaison des deux mesures

Les deux temps obtenus sont :

Construction	Temps
Première construction	157,12 s
Deuxième construction	22,10 s
Différence	135,02 s

Le gain de temps est donc :

157,12 − 22,10 = 135,02 secondes

La première construction est environ 7,1 fois plus longue que la deuxième.

Autrement dit, après la première construction, le temps nécessaire est fortement réduit lorsque le projet n'a subi aucune modification.

J'ai pris en compte la remarque du professeur et j'ai ajouté la 5e section que voici:

# 5. Pourquoi la deuxième construction est-elle plus rapide ?

La différence vient du fonctionnement de la construction incrémentale.

Lors de la première exécution, Jenga doit construire les éléments nécessaires du workspace. Les fichiers sources doivent être compilés afin de produire les fichiers objets, puis les différentes cibles doivent être construites.

Lors de la deuxième exécution, les fichiers produits lors de la première construction sont déjà présents.

Jenga vérifie alors si les fichiers sources ont changé depuis leur dernière compilation.

Comme aucun fichier n'a été modifié, il peut conserver les résultats déjà produits au lieu de recommencer toute la compilation.

On peut résumer le fonctionnement ainsi :

Première construction
        ↓
Analyse des projets
        ↓
Compilation des sources
        ↓
Création des fichiers objets
        ↓
Édition de liens
        ↓
Résultats conservés

Deuxième construction
        ↓
Analyse des projets
        ↓
Vérification des dates/modifications
        ↓
Aucun changement détecté
        ↓
Pas de recompilation inutile
