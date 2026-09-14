## Exercice 7 — Le temps que ça prend
1. Objectif

Le but de cet exercice est de comparer le temps nécessaire pour effectuer une première construction du workspace avec celui d'une deuxième construction réalisée immédiatement après, sans aucune modification des fichiers.

Cette comparaison permet d'observer concrètement le fonctionnement de la construction incrémentale de Jenga.

## 2. Première construction

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

## 3. Deuxième construction

Sans modifier le projet ni les fichiers sources, j'ai immédiatement exécuté la même commande une deuxième fois :

Measure-Command { jenga build --config Debug }

La mesure obtenue est :

Minutes      : 0
Seconds      : 22
Milliseconds : 104
TotalSeconds : 22.1048635

La deuxième construction a donc duré environ :

22,10 secondes.

## 4. Comparaison des deux mesures

Les deux temps obtenus sont :

Construction	Temps
Première construction	157,12 s
Deuxième construction	22,10 s
Différence	135,02 s

Le gain de temps est donc :

157,12 − 22,10 = 135,02 secondes

La première construction est environ 7,1 fois plus longue que la deuxième.

Autrement dit, après la première construction, le temps nécessaire est fortement réduit lorsque le projet n'a subi aucune modification.