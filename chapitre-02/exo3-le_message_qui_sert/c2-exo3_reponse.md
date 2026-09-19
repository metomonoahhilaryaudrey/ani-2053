# Exercice3: Le message qui sert

1. Affichage de l'historique des commits

Pour commencer, je me suis placé dans le dépôt du moteur et j'ai utilisé la commande suivante afin d'afficher les derniers commits :

``git log --oneline -3``
Voici le resultat:

PS C:\Users\HP\Desktop\nkentseu\Nkentseu> git log --oneline -3
6fb634fc (HEAD -> main, origin/main, origin/HEAD) NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
c1c815ff CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)

## le premier commit est: `6fb634fc`

# "Le message": `NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle`

- Est-ce qu'il dit ce qu'il fait? La réponse est **oui**
- Est-ce qu'il dit pouquoi?**Pas totalement** parce que ici,il menteionne une écheance reelle sans pour autant donner les raisons.
- le commit porte-il sur un seul sujet? **Oui**

## Le deuxieme commit est: `860e9d7f`

# "Le message": Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)

- Est-ce qu'il dit ce qu'il fait? La réponse est **oui**
- Est-ce qu'il dit pouquoi? Non , car aucune explication n'est mentionnée ici.
- le commit porte-il sur un seul sujet? Non,car le commit nous parle de NK3DModeler et de NKCode.

## Le troisieme commit est: `c1c815ff`

 # "Le message": CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)

- Est-ce qu'il dit ce qu'il fait? **Oui, très clairement**.
- Est-ce qu'il dit pouquoi? Oui,Le message indique précisément que les huit épinglages de Jenga passent désormais par ``JENGA_VERSION``. On comprend à la fois le domaine concerné (CI) et la modification effectuée.
- Le commit porte il sur un seul sujet? Oui. Le message décrit une modification cohérente autour de la gestion de ``JENGA_VERSION`` pour les huit épinglages de Jenga.

## Celui que je choisirais comme le plus faible

Parmi les trois, le deuxième est celui qui soulève le plus clairement le problème du sujet unique, car il associe la refonte de NK3DModeler et la signature de NKCode sur certificat.
## Réecriture du message le plus faible:
`NK3DModeler : refonte et mise à jour avec main`
Cette nouvelle formulation est plus courte et permet de comprendre immédiatement le sujet principal du commit. Elle évite également de mélanger la modification de NK3DModeler avec la partie concernant NKCode.