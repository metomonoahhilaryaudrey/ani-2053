Exercice 10 — Le graphe d'un module
# 1. Objectif

L'objectif est d'étudier les dépendances du module NKCanvas sur deux niveaux :

les dépendances directes de NKCanvas ;
les dépendances de ces modules.

On s'arrête volontairement au deuxième niveau, comme demandé dans la consigne.

# 2. Niveau 1 : dépendances directes de NKCanvas

Dans Kernel/Runtime/NKCanvas/NKCanvas.jenga, les dépendances sont regroupées dans la variable _canvasDeps.

On trouve :

NKWindow
NKFont
NKImage
NKGui
NKEvent
NKGlad
NKStream
NKTime
NKThreading
NKFileSystem
NKLogger
NKMath
NKContainers
NKMemory
NKCore
NKPlatform

NKCanvas possède donc 16 dépendances directes.

Une dépendance supplémentaire, NKUI, peut être ajoutée dans certaines conditions. Comme cette condition n'est pas vérifiée ici, je ne la compte pas dans le graphe.

# 3. Niveau 2 : dépendances des dépendances

En regardant les dépendances des 16 modules précédents, on obtient notamment :

Dépendance	Ses dépendances
NKWindow	NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime
NKFont	NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading
NKImage	NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading
NKGui	NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading
NKEvent	NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime
NKGlad	aucune
NKStream	NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading
NKTime	NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading
NKThreading	NKContainers, NKCore, NKMemory, NKPlatform
NKFileSystem	NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading
NKLogger	NKContainers, NKCore, NKMemory, NKPlatform, NKThreading
NKMath	NKContainers, NKCore, NKMemory, NKPlatform
NKContainers	NKCore, NKMemory, NKPlatform
NKMemory	NKCore, NKPlatform
NKCore	NKPlatform
NKPlatform	aucune

On remarque que les dépendances du deuxième niveau sont déjà présentes dans les 16 dépendances directes de NKCanvas.

Il n'y a donc aucun nouveau projet à ajouter au graphe après le deuxième niveau.

# 4. Graphe de NKCanvas sur deux niveaux

Le graphe peut être représenté simplement ainsi :

                         NKCanvas
                            |
        ------------------------------------------------
        |       |       |       |       |       |      |
    NKWindow NKFont NKImage NKGui NKEvent NKGlad NKStream
        |       |       |       |       |       |      |
        ------------------------------------------------
                            |
       NKTime - NKThreading - NKFileSystem - NKLogger
                            |
                NKMath - NKContainers
                            |
                    NKMemory - NKCore
                            |
                       NKPlatform

Les flèches représentent ici les relations de dépendance. Les modules situés au deuxième niveau sont déjà inclus dans la liste des dépendances directes de NKCanvas.

Une représentation plus détaillée des 16 dépendances directes est :

NKCanvas
├── NKWindow
├── NKFont
├── NKImage
├── NKGui
├── NKEvent
├── NKGlad
├── NKStream
├── NKTime
├── NKThreading
├── NKFileSystem
├── NKLogger
├── NKMath
├── NKContainers
├── NKMemory
├── NKCore
└── NKPlatform
# 5. Combien de projets faut-il construire avant NKCanvas ?

Il faut construire 16 projets avant NKCanvas.

Ils sont :

1.  NKPlatform
2.  NKGlad
3.  NKCore
4.  NKMemory
5.  NKContainers
6.  NKThreading
7.  NKMath
8.  NKLogger
9.  NKTime
10. NKFont
11. NKFileSystem
12. NKEvent
13. NKStream
14. NKWindow
15. NKImage
16. NKGui

Ensuite, NKCanvas peut être construit.

# 6. Conclusion

NKCanvas possède 16 dépendances directes.

L'étude du deuxième niveau montre que les dépendances de ces modules sont déjà comprises dans ces 16 projets. Aucun nouveau projet n'apparaît.

Il faut donc construire 16 projets avant NKCanvas.