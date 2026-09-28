## Exercice 5: le_titre_qui_informe

On me demande d'afficher dans la barre de titre de la fenêtre :

le nom du document 
un astérisque * si le document a été modifié 
la taille actuelle de la fenêtre.

## Pour commencer je n'ai preque rien changer a mon code ,j'ai juste ajouter un nom au titre:

cfg.title = "devoir.txt - 1280x720";

Ensuite j'ai compilé et executer avec ``jenga build`` et ``jenga run``, je constate donc que la fenetre s'ouvre avec le titre "devoir.txt - 1280x720"

## Deuxieme étape: mettre à jour la taille au redimensionnement

Le but ici c'est que la fentre affiche une nouvelle taille lorsqu'on tire.
J'ai modifié mon code 

// Redimensionnement de la fenêtre else if (event->Is<nkentseu::NkWindowResizeEvent>()) { auto size = window.GetSize(); logger.Info("Nouvelle largeur = {}", size.x); logger.Info("Nouvelle hauteur = {}", size.y); // Construction du nouveau titre char titre[100]; std::snprintf( titre, sizeof(titre), "devoir.txt - %dx%d", size.x, size.y ); window.SetTitle(titre);

Resultat

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  Window.exe
     C:\Users\HP\Desktop\hihi\FirstWindow\Build\Bin\Debug-Windows\Window\Window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-28 09:39:49.037] [INF] [default] [main.cpp:46 in nkmain] -> X = 1274
[2026-09-28 09:39:49.039] [INF] [default] [main.cpp:47 in nkmain] -> Y = 703

Pendant que je tire, le titre en haut a changé :

devoir.txt - 1274x703

## Étape 3 : ajouter l'astérisque

But : quand l'utilisateur tape une touche, le titre affiche devoir.txt* - 1280x720.
Modification du code:
j'ai Ajouté la fonction en haut du fichier,ensuite j'ai Ajouté la variable avant la boucle er enfin j'ai Ajouté une nouvelle branche pour la touche.

J'ai compilé avec ``jenga build`` et executer avec ``jenga run``
J'ai cliqué d'abord sur la fenêtre du programme pour qu'elle soit active (sinon elle ne reçoit pas le clavier)ensuite j'ai appuyé sur la touche A (au choix).
Enfin j'ai regardé le titre en haut : il est passer de ``devoir.txt - 1280x720`` à ``devoir.txt* - 1280x720``.



## Conclusion

Dans cet exercice, j'ai affiché dans le titre de la fenêtre le nom du document, un astérisque quand il est modifié, et la taille courante de la fenêtre.

Le titre n'est pas recalculé à chaque image : il est mis à jour seulement quand un événement arrive (redimensionnement ou touche pressée).

