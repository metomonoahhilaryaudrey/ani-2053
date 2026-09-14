Exercice 8 — Debug contre Release
# 1. Objectif de l'expérience

L'objectif est de construire le projet NKMath dans deux configurations différentes : Debug et Release.

Pour chacune des configurations, deux éléments sont relevés :

le temps nécessaire à la construction ;
la taille de la bibliothèque NKMath.lib produite.

L'objectif final est ensuite de retrouver dans NKMath.jenga les paramètres qui permettent d'expliquer les différences entre les quatre valeurs obtenues.

# 2. Construction de NKMath en Debug

La construction du projet est chronométrée avec la commande :

Measure-Command { jenga build --project NKMath --config Debug }

La mesure obtenue est :

Seconds         : 11
Milliseconds    : 317
TotalSeconds    : 11.3171049

La construction en configuration Debug dure donc environ 11,32 secondes.

La taille de la bibliothèque produite est ensuite vérifiée avec :

Get-Item "Build\Lib\Debug-Windows\NKMath.lib" | Select-Object Name, Length

Résultat :

Name        Length
----        ------
NKMath.lib  905138

Le fichier Debug possède donc une taille de 905 138 octets, soit environ 884 Ko.

# 3. Construction de NKMath en Release

La même opération est réalisée avec la configuration Release :

Measure-Command { jenga build --project NKMath --config Release }

Le temps mesuré est :

Seconds         : 12
Milliseconds    : 987
TotalSeconds    : 12.9872567

La construction Release prend donc environ 12,99 secondes.

La taille du fichier produit est vérifiée avec :

Get-Item "Build\Lib\Release-Windows\NKMath.lib" | Select-Object Name, Length

Résultat :

Name        Length
----        ------
NKMath.lib  178124

La bibliothèque Release fait donc 178 124 octets, soit environ 174 Ko.

# 4. Comparaison des résultats

Les mesures obtenues sont les suivantes :

Configuration	Temps de construction	Taille de NKMath.lib
Debug	11,32 s	905 138 octets (~884 Ko)
Release	12,99 s	178 124 octets (~174 Ko)

La différence de taille est particulièrement importante.

905 138 - 178 124 = 727 014 octets

Le fichier Debug contient donc 727 014 octets de plus que le fichier Release.

En rapportant les deux tailles :

905 138 / 178 124 ≈ 5,08

La bibliothèque Debug est donc environ 5,1 fois plus volumineuse que la bibliothèque Release.

Pour le temps de construction :

12,99 - 11,32 = 1,67 seconde

La construction Release a donc pris 1,67 seconde de plus que la construction Debug dans cette expérience.

# 5. Recherche des paramètres dans NKMath.jenga

Les différences entre les deux configurations sont définies par les filtres présents dans NKMath.jenga.

Les parties importantes du fichier sont :

with filter("config:Debug"):
    defines(["_DEBUG", "DEBUG"])
    optimize("Off")
    symbols(True)

with filter("config:Release"):
    defines(["NDEBUG"])
    optimize("Speed")
    symbols(False)

Ce sont principalement les instructions optimize(...) et symbols(...) qui permettent d'interpréter les différences de taille et de temps.

# 6. Explication du résultat obtenu en Debug

En Debug, le fichier contient :

optimize("Off")
symbols(True)
optimize("Off")

Cette instruction désactive les optimisations du compilateur.

Le compilateur cherche donc moins à transformer le code pour obtenir un résultat plus compact ou plus performant. Le travail de compilation est ainsi moins orienté vers l'optimisation du programme.

symbols(True)

Cette instruction active les informations de débogage.

Ces informations permettent au débogueur de relier le code compilé au code source et facilitent notamment l'analyse du programme pendant une session de débogage.

Ces informations supplémentaires participent à la taille importante du fichier obtenu.

Cela permet donc d'expliquer pourquoi :

NKMath.lib Debug = 905 138 octets

est beaucoup plus grand que le fichier Release.

# 7. Explication du résultat obtenu en Release

La configuration Release utilise au contraire :

optimize("Speed")
symbols(False)
optimize("Speed")

Cette option demande au compilateur d'optimiser le code afin de favoriser les performances à l'exécution.

Pour cela, le compilateur doit analyser davantage le code et effectuer différentes transformations possibles afin d'obtenir une version plus efficace.

Cette phase d'analyse supplémentaire permet notamment d'expliquer pourquoi la construction Release est légèrement plus longue dans cette expérience :

Debug   : 11,32 s
Release : 12,99 s
symbols(False)

Cette instruction désactive les informations de débogage.

Le fichier final ne contient donc pas les mêmes informations supplémentaires que la version Debug, ce qui contribue fortement à sa taille réduite.

On obtient ainsi :

NKMath.lib Release = 178 124 octets

contre :

NKMath.lib Debug = 905 138 octets
# 8. Les quatre valeurs et les lignes qui les expliquent

Les quatre résultats de l'expérience peuvent être associés aux paramètres du fichier NKMath.jenga :

Valeur mesurée	Configuration	Ligne(s) principalement concernée(s)
11,32 s	Debug	optimize("Off")
12,99 s	Release	optimize("Speed")
905 138 octets	Debug	symbols(True) + optimize("Off")
178 124 octets	Release	symbols(False) + optimize("Speed")

Les deux configurations utilisent également des définitions différentes :

defines(["_DEBUG", "DEBUG"])

en Debug, contre :

defines(["NDEBUG"])

en Release.

Ces définitions permettent au code source de savoir dans quelle configuration il est compilé et peuvent donc modifier certains comportements conditionnels du programme.