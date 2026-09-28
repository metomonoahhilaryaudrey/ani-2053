# Exercice 9 : les quatre dialogues natifs

## Utilisation des dialogues

Dans cet exercice, j’ai utilisé les quatre types de fenêtres de dialogue disponibles dans l’API afin de permettre à l’utilisateur d’effectuer différentes sélections :

1. ``NkDialogs::OpenFileDialog(filter, title)`` permet de rechercher et sélectionner un fichier déjà présent sur l’ordinateur.

2. ``NkDialogs::SaveFileDialog(defaultExt, title)`` sert à choisir le nom et l’emplacement d’un fichier à enregistrer.

3. ``NkDialogs::OpenFolderDialog(title)`` permet de sélectionner un répertoire.

4. ``NkDialogs::ColorPicker(initial)`` affiche un sélecteur permettant de choisir une couleur.

Ces quatre fonctions renvoient un objet ``NkDialogResult``. Celui-ci permet notamment de savoir si l'utilisateur a confirmé son choix ou s'il a quitté la boîte de dialogue.

## Gestion de l'annulation

Pour éviter les erreurs lorsque l'utilisateur ferme une boîte de dialogue sans effectuer de sélection, j'ai vérifié la valeur de ``confirmed`` avant d'utiliser les informations retournées.

J'ai regroupé cette vérification dans une fonction :


static void LogDialogResult(const NkString &nomDialogue, const NkDialogResult &res) {

    if (!res.confirmed) {
        logger.Info("[exo9] %s : annule par l'utilisateur", nomDialogue.CStr());
        return;
    }

    logger.Info("[exo9] %s : confirme, path=\"%s\", color=%u",
                nomDialogue.CStr(), res.path.CStr(), res.color);
}


Ainsi, lorsqu'une personne clique sur « Annuler » ou ferme directement la fenêtre, le programme détecte que ``confirmed`` est faux et arrête immédiatement le traitement.

Les valeurs contenues dans ``path`` ou ``color`` ne sont donc utilisées que lorsque l'utilisateur a réellement validé son choix. Cela permet d'éviter de manipuler des données qui ne sont pas valides après une annulation.

## Commandes utilisées

J'ai associé chaque dialogue à une touche du clavier afin de pouvoir les tester facilement :

 **O** : ouverture de la fenêtre de sélection d'un fichier ;
 **S** : ouverture du dialogue permettant de choisir un emplacement de sauvegarde ;
 **D** : sélection d'un dossier ;
 **C** : ouverture du choix de couleur ;
 **Échap** : fermeture de la fenêtre principale.

Le programme réagit donc aux événements du clavier et lance le dialogue correspondant lorsque la touche appropriée est détectée.

## Tests effectués

Pour vérifier que la gestion de l'annulation fonctionne correctement, j'ai ouvert chacun des quatre dialogues puis je l'ai fermé sans sélectionner de fichier, de dossier ou de couleur.

Dans chaque situation, le programme reste fonctionnel et ne provoque pas de plantage. L'annulation est simplement indiquée dans les logs, ce qui confirme que les différents cas de fermeture sont correctement pris en compte.
