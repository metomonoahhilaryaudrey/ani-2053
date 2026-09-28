# Exercice 10 : la fenêtre sans bordure

## Création de la fenêtre

L’objectif de cet exercice est de créer une fenêtre sans bordure native et de reproduire manuellement les principales fonctionnalités d’une barre de titre.

Pour commencer, j’ai désactivé le cadre fourni automatiquement par le système en utilisant :


``NkWindowConfig cfg;``

``cfg.frame = false;``


Avec cette configuration, la fenêtre ne possède plus sa barre supérieure ni ses bordures habituelles. Il faut donc gérer nous-mêmes les différentes interactions qui étaient normalement prises en charge par le système.

## Mise en place de la barre personnalisée

L’objectif de cet exercice est de reproduire le comportement principal d’une barre de fenêtre classique, mais cette fois en utilisant notre propre logique.

 **Le nom de la fenêtre** : j’ai défini le titre avec `window.SetTitle("Ma barre de titre a moi")`. Même si le titre n'est plus affiché directement par une barre native, il peut toujours être utilisé par le système, notamment dans la barre des tâches.

 **Les trois commandes** : j’ai prévu trois emplacements correspondant aux actions de réduction, d’agrandissement/restauration et de fermeture. La fonction `ZoneAt()` permet de déterminer sur quelle partie de la barre l’utilisateur a cliqué. Ces zones sont placées du côté droit et utilisent une hauteur de 32 pixels.

 **Le déplacement de la fenêtre** : lorsqu’un clic gauche est effectué sur la partie libre de la barre, le déplacement est activé. Lors des événements `NkMouseMoveEvent`, je récupère la position de la souris avec `GetScreenX()` et `GetScreenY()` afin de modifier la position de la fenêtre en fonction du déplacement effectué.

 **L’agrandissement avec un double-clic** : lorsqu’un double-clic est détecté dans la partie destinée au déplacement, `NkMouseDoubleClickEvent` vérifie l’état actuel de la fenêtre. Si celle-ci est déjà agrandie grâce à `IsMaximized()`, elle revient à sa taille précédente avec `Restore()`. Dans le cas contraire, `Maximize()` est appelé.

## Gestion des différentes zones

J’ai choisi de déterminer les zones interactives au moment où l’utilisateur effectue une action plutôt que de conserver des coordonnées fixes.
Ensuite nous avons:

``ZoneAt()`` utilise notamment la largeur obtenue avec ``window.GetSize().x`` pour positionner correctement les boutons. Ainsi, si la taille de la fenêtre change, les emplacements des boutons restent automatiquement adaptés à sa nouvelle largeur.

## Temps consacré

J’ai consacré environ **2h 00** à cet exercice. La réalisation m’a demandé du temps, notamment parce que je ne maîtrise pas encore très bien le C++. J’ai également dû me familiariser avec l’API utilisée dans le projet et comprendre le fonctionnement de certaines fonctions.

En conclusion la fenetre sans bordure a été creer.