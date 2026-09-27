## Exercice 3: Les bornes

L’exercice permet  de comprendre comment une application contrôle les dimensions minimales de sa fenêtre et comment le système réagit lorsqu’on essaie de dépasser cette contrainte.

Pour commencer, j'ai fait des modifications dans mon code en ajoutant:

   cfg.minWidth = 450;
     cfg.minHeight = 300;

    ensuite, en ce qui concerne les tailles minimales de ma fenetre j'ai ajouté:


                auto size = window.GetSize();
                logger.Info("X = {}", size.x);
                logger.Info("Y = {}", size.y);

    Puis il etait question pour moi de fixer une taille minimale

     1-Fixation de la taille minimale:   
     j'ai pris comme taille:
     ``450`` et ``300``

     J'ai fait la compilation avec la commande (jenga build) et j'ai fait l'exécution avec (jenga run)
     enfin j'ai réduit la hauteur et la largeur le plus possible
     Resultat:


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window.exe
     C:\Users\HP\Desktop\hihi\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-27 19:54:03.283] [INF] [default] [main.cpp:32 in nkmain] -> X = 428
[2026-09-27 19:54:03.283] [INF] [default] [main.cpp:33 in nkmain] -> Y = 244

On constate donc que la largeur est (428) et la hauteur est (244). Or au départ d'apres mes données inserer au départ, le resultat devait etre: ``450``et ``300``

Il est donc maintenant question de trouver la plus petite taille que le systeme accepte:

## 2-Obtention de la plus petite taille que le systeme accepte

J'ai retirer les tailles minimales puis je suis passer a la compilation et a l'execution.
enfin j'ai réduit la hauteur et la largeur le plus possible.
Resultat:

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window.exe
     C:\Users\HP\Desktop\hihi\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-27 20:01:38.265] [INF] [default] [main.cpp:31 in nkmain] -> X = 176
[2026-09-27 20:01:38.266] [INF] [default] [main.cpp:32 in nkmain] -> Y = 34

## Conclusion: La taille minimale que le systeme accepte:
Largeur: ``176`` et Hauteur: ``34``