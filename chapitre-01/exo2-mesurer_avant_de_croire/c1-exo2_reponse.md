## Pour compter le nombre de fichiers sources(fichier.cpp et .h) et lignes du depot j'ai utilisé Powershell 
pour faire cela ,j'ai tapé les commandes:
```
 Get-childItem -Recurse -File -Filter * .cpp 
 Get-childItem -Recurse -File -Filter*  .h
 ```
 ``Get-content`` et ``Measure-object-Line`` m'ont aider pour compter les lignes.
 #### Ce que j'ai trouvé :
 - Fichiers .cpp: 1609 fichiers pour 917647 lignes
 - Fichiers .h: 2728 fichiers pour 988601 lignes
 - Au total : 4337 fichiers et 1 906 248 lignes
 Pourtant, dans le cours/chapitre , on nous parle de 2641 fichiers et 1 193 385 lignes. On voit bien qu'il y a une grosse difference .
 ### Apres vérification du dossier Build , il n'existe pas a la racine. Les dossiers de compilation(build,bin,obj) ont juste 10 fichiers .cpp/h pour 3255 lignes. 
 #### les dossiers tests eux contiennent 164 fichiers.
 ### La difference vient donc des bibliotheques externes ou bien de la méthode utilisée pour compter.