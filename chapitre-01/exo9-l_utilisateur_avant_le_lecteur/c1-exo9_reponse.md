Exercice 9 — L'utilisateur avant le lecteur

Date : 14 septembre 2026
Durée d'utilisation : environ 10 minutes
Application testée : NkRef
Commande utilisée :

jenga run NkRef --config Debug
# 1. Méthode

Pour cette expérience, j'ai utilisé NkRef uniquement en tant qu'utilisateur, sans consulter son code source.

Pendant environ dix minutes, j'ai essayé les différents menus, boutons, raccourcis et outils disponibles afin de déterminer ce que l'application permet réellement de faire et ce qui reste difficile à comprendre.

Les deux listes ci-dessous correspondent donc à mes impressions au moment de l'utilisation, et non à une analyse du fonctionnement interne du programme.

# 2. Ce que NkRef fait

Observations réalisées le 14 septembre 2026

L'application possède une zone principale permettant de dessiner directement à l'écran.
Un mode crayon permet de tracer des traits avec différentes couleurs.
L'épaisseur du trait peut être réglée, avec des valeurs allant de 1 à 24.
Il est possible d'annuler un tracé et également de supprimer l'ensemble des tracés réalisés.
Le dessin peut être effectué alors que la fenêtre est rendue partiellement transparente.
Un réglage d'opacité permet de rendre la fenêtre plus ou moins transparente. Lorsque l'opacité diminue, le contenu situé derrière NkRef devient visible.
Cette transparence donne l'impression que l'on dessine sur un calque placé au-dessus de l'écran.
Une option permet d'afficher ou de cacher une grille dans la zone de dessin.
L'application possède un mode sombre qui peut être activé ou désactivé.
Un menu contextuel est accessible avec le clic droit dans la zone de dessin.
Ce menu propose notamment des commandes liées à l'enregistrement, au déplacement de la fenêtre, à la grille, au mode crayon et à l'affichage au premier plan.
Une commande Enregistrer est disponible avec le raccourci Ctrl+S.
Une rubrique consacrée aux gestes indique plusieurs interactions : la molette pour zoomer, Espace + glisser pour déplacer la vue et Ctrl + glisser pour dessiner un rectangle.
Une option « toujours devant » est proposée.
Une option « glisser le fond = fenêtre » est également disponible.
Une commande appelée « Origine début », associée au raccourci Ctrl+P, apparaît dans les fonctionnalités disponibles.
L'application comporte également une partie permettant de gérer une image, mais je n'ai pas réussi à faire apparaître une image pendant mon utilisation.
J'ai pu écrire quelques lettres directement avec le crayon, puis supprimer le dessin.
La commande d'enregistrement semble produire un fichier, mais je n'ai pas réussi à déterminer facilement où ce fichier était enregistré ni comment le rouvrir avec NkRef.
Les traits droits sont relativement nets, tandis que les courbes et les cercles apparaissent moins réguliers.
Impression générale après dix minutes

Sans consulter le code ni une documentation détaillée, NkRef m'apparaît principalement comme un outil permettant d'annoter ou de dessiner par-dessus ce qui est affiché à l'écran.

La fonction que j'ai comprise le plus rapidement est l'association entre transparence de la fenêtre et dessin : elle permet de garder visible ce qui se trouve derrière l'application tout en ajoutant des annotations.

# 3. Ce que j'aurais voulu que NkRef fasse

Attentes formulées le 14 septembre 2026, après la même session d'utilisation

Je voudrais que l'option « toujours devant » produise un changement immédiatement visible afin de comprendre sans ambiguïté si elle est activée.
Je voudrais savoir précisément quelle valeur minimale d'opacité peut être atteinte et avoir éventuellement une indication numérique correspondant à la position du curseur.
Je voudrais comprendre immédiatement le fonctionnement de « glisser le fond = fenêtre », car son activation ou sa désactivation ne m'a pas permis d'identifier clairement une différence.
Je voudrais que « Origine début » provoque une action visible ou qu'une indication explique sa fonction.
Je voudrais pouvoir utiliser effectivement le geste Ctrl + glisser pour créer un rectangle, puisque cette possibilité est annoncée dans les gestes.
Je voudrais comprendre comment importer ou activer une image et savoir ce que signifie exactement « aucune image activée ».
Je voudrais disposer d'une méthode simple pour retrouver les fichiers enregistrés avec Ctrl+S.
Je voudrais pouvoir rouvrir un dessin enregistré directement depuis NkRef, sans devoir chercher manuellement le fichier dans le système.
Je voudrais qu'un nouveau utilisateur puisse comprendre rapidement à quoi sert l'application dans son ensemble, par exemple grâce à une courte présentation ou à une aide accessible depuis le menu.
Je voudrais que les fonctions dont le comportement n'est pas immédiatement visible soient accompagnées d'une courte explication.
Je voudrais également que les différents modes de dessin soient plus faciles à identifier, notamment lorsqu'une fonctionnalité est disponible dans un menu mais que son effet n'est pas évident.