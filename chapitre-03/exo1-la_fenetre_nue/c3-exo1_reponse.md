## Exercice : La fenetre nue

L’objectif de cet exercice est d’écrire un programme capable d’ouvrir une fenêtre, de la garder ouverte tant que l’utilisateur ne demande pas sa fermeture, puis de terminer proprement le programme.

  On retrouve 32 lignes avec 6 lignes vides.

## Correspondance des lignes avec le chapitre

1	``#include "NKWindow/NKMain.h"`` :	Le plus petit programme — “Vous n'écrivez pas de main. Vous écrivez nkmain.”
2	``#include "NKWindow/NKWindow.h"``:	Le plus petit programme — ouverture et utilisation de la fenêtre
3		
4	``int nkmain(const nkentseu::NkEntryState& state) {`` :	Le plus petit programme — “Vous n'écrivez pas de main. Vous écrivez nkmain.”
5		
6	``nkentseu::NkWindowConfig cfg;`` :	Le plus petit programme — “La configuration se donne au constructeur.” / Configurer et piloter la fenêtre
7	``cfg.title = "MonTitre, etape 02";`` :	Configurer et piloter la fenêtre — “l'identité et la taille (titre, largeur, hauteur)”
8	``cfg.width = 1280; ``:	Configurer et piloter la fenêtre — “l'identité et la taille (titre, largeur, hauteur)”
9	``cfg.height = 720;`` :	Configurer et piloter la fenêtre — “l'identité et la taille (titre, largeur, hauteur)”
10		
11	``nkentseu::NkWindow window;`` :	Le plus petit programme — création et utilisation de NkWindow
12		
13	``if (!window.Create(cfg)) {`` :	Le plus petit programme — vérification de la création de la fenêtre
14	logger.Error("Failed to create window"); :	Le plus petit programme — “On vérifie IsOpen. Une création peut échouer”
15	``return -1;`` :	Le plus petit programme — gestion de l'échec de création
16	}	
17		
18	``bool running = true;`` :	D'où viennent les événements / Trois hauteurs pour lire les entrées — utilisation d'une boucle contrôlée par les événements
19		
20	``while (running) { ``:	Le plus petit programme — boucle qui garde la fenêtre ouverte
21	``nkentseu::NkEvent* event = nullptr;`` :	Trois hauteurs pour lire les entrées — “Première hauteur — la file”
22	``while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) { ``:	Trois hauteurs pour lire les entrées — “Première hauteur — la file. On la vide à chaque tour de boucle”
23	``// Process events`` :	Trois hauteurs pour lire les entrées — traitement des événements
24	``if (event->Is<nkentseu::NkWindowCloseEvent>()) {`` :	Les douze familles — famille WINDOW : “fermeture...”
25	``running = false;`` :	Le plus petit programme — sortie de la boucle lorsque la fenêtre doit être fermée
26	}	
27	}	
28	}	
29		
30	``return 0;`` :	Le plus petit programme — terminaison normale du programme
31	}
32

## Execution et compilation du programme

J'ai utilisé la commande: ``jenga build``
Resultat:

PS C:\Users\HP\Desktop\hihi\FirstWindow> jenga build

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. Window [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Window                                                          Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Window\Window.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.89s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           4.89s
Status:         ✓ SUCCESS
═══════════════════════════════════════════════════════════════════════════════

Ensuite j'ai utilisé la commande ``jenga run``
Resultat:
PS C:\Users\HP\Desktop\hihi\FirstWindow> jenga run  

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.3             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window.exe
     C:\Users\HP\Desktop\hihi\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.73s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
