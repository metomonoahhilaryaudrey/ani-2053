
Fichier choisi : ``Applications/Sandbox/Sandbox.jenga``
#!/usr/bin/env python3
### Indique que le fichier est exécuté avec Python 3.

# -*- coding: utf-8 -*-
### Indique l’encodage utilisé pour le fichier.

"""
Sandbox — Application de démonstration multi-plateformes
=========================================================
Illustre l'utilisation complète du framework Nkentseu :
  • Création de fenêtre et boucle principale cross-platform
  • Gestion des événements : clavier, souris, touch, drag & drop
  • Rendu pixel software via NKCanvas (NkSoftwareRenderer)
  • Gamepad, safe area, transforms 2D
 
Un seul fichier src/main.cpp compile pour TOUTES les plateformes.
Le point d'entrée natif est abstrait par NkEntry.h / NkMain.h.

Orchestrateur : ce fichier ne définit plus aucun projet directement. Chaque
catégorie de démos vit dans son propre .jenga (clarté = 1 catégorie par fichier)
et est rassemblée ici via include(). Les variables graphiques/Wayland partagées
sont fournies par useconfig (config/graphics.jenga + config/wayland.jenga),
chargées au niveau du workspace et propagées automatiquement.

  FontSandbox.jenga      → sandboxnkfont (NKFont)
  ContextSandbox.jenga   → sandboxusenkcontext (NKContext/NKCanvas)
  RhiSandbox.jenga       → sandboxusenkrhi (NKRHI + UI RHI)
  RendererSandbox.jenga  → sandboxusenkrenderer (NKRenderer)
"""
### Présente le projet Sandbox, ses fonctionnalités et son organisation.

from Jenga import *
### Importe les éléments de Jenga utilisés dans le fichier.

from jengaconfig import *
### Importe les éléments de configuration utilisés dans le fichier.

# include() est un context manager -> il FAUT le `with ... : pass` pour qu'il
# s'execute (un appel nu ne fait rien). Cf. le root qui inclut en `with include(...)`.

### Explique la manière dont include() doit être utilisé dans ce fichier.

# Chemins relatifs a CE fichier (Applications/Sandbox/) : juste le nom.

### Indique que les chemins utilisés sont relatifs au fichier Sandbox.jenga.

with include("FontSandbox.jenga"):     pass
### Inclut le fichier FontSandbox.jenga.

with include("ContextSandbox.jenga"):  pass
### Inclut le fichier ContextSandbox.jenga.

with include("RhiSandbox.jenga"):      pass
### Inclut le fichier RhiSandbox.jenga.

with include("RendererSandbox.jenga"): pass
### Inclut le fichier RendererSandbox.jenga.

   

 