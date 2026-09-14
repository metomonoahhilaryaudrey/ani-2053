   ## Pour compter le nombre de fichiers sources(fichier.cpp et .h) et lignes du depot j'ai utilisé Powershell 

pour faire cela ,j'ai tapé les commandes:

```
(Get-ChildItem -Recurse -File -Filter *.cpp).Count
(Get-ChildItem -Recurse -File -Filter *.h).Count
```
Resultats apres l'exécution des commandes 

commande1: 
PS C:\Users\HP\Desktop\nkentseu\Nkentseu> (Get-ChildItem -Recurse -File -Filter *.cpp).Count
1609
commande2:

PS C:\Users\HP\Desktop\nkentseu\Nkentseu> (Get-ChildItem -Recurse -File -Filter *.h).Count
2728

Pour les lignes, j'ai utilisé  ``` Get-Content ```  avec ``` Measure-Object -Line```.
#### soit ``` (Get-ChildItem -Recurse -File -Filter *.cpp | Get-Content | Measure-Object -Line).Lines``` pour les .cpp 
et
#### ``` ((Get-ChildItem -Recurse -File -Filter *.h | Get-Content | Measure-Object -Line).Lines) ``` pour les .h

Résultats :

* Fichiers.cpp : **1609 fichiers**, **917647 lignes** PS C:\Users\HP\Desktop\nkentseu\Nkentseu> (Get-ChildItem -Recurse -File -Filter *.cpp | Get-Content | Measure-Object -Line).Lines
917647

*Fichiers .h : **2728 fichiers**, **988601 lignes** PS C:\Users\HP\Desktop\nkentseu\Nkentseu> (Get-ChildItem -Recurse -File -Filter *.h | Get-Content | Measure-Object -Line).Lines
988601
* Total : **4337 fichiers**, **1906248 lignes**

 Pourtant, dans le cours/chapitre , on nous parle de 2641 fichiers et 1 193 385 lignes. On voit bien qu'il y a une grosse difference .


Dans le dossier `Externals`, j'ai trouvé **1673 fichiers .cpp/.h**, avec **787518 lignes**.

En dehors de `Externals`, il reste **2662 fichiers**, avec **1117545 lignes**.

Ce qui montre donc que les fichiers externes représentent une grosse partie du dépôt. Aussi, les **2662 fichiers hors `Externals`** sont tres proches des **2641 fichiers** annoncés dans le chapitre.

 ### Apres vérification du dossier Build , il n'existe pas a la racine. Les dossiers de compilation(build,bin,obj) ont juste 10 fichiers .cpp/h pour 3255 lignes. 
 #### les dossiers tests eux contiennent 164 fichiers.
 ### La difference vient donc des bibliotheques externes ou bien de la méthode utilisée pour compter.

