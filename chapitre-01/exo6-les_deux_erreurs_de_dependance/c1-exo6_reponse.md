Exercice 6 — Les deux erreurs de dépendance
## 1. Configuration de test

Pour réaliser cet exercice, j'ai utilisé le projet MonEssai.

Le programme appelle une fonction réellement compilée de NKMath :

#include <NKMath/NKMath.h>

int main()
{
    auto result = nkentseu::math::NkSqrt(4.0f);
    (void)result;

    return 0;
}

L'objectif est de provoquer une véritable intervention de l'éditeur de liens afin d'observer la différence entre dependson et links.

La dépendance utilisée pour le test est donc :

NKMath
# 2. Test 1 — Retrait de dependson avec links
Modification effectuée

Dans MonEssai.jenga, j'ai retiré la déclaration dependson et conservé le lien vers NKMath.

La configuration de test contient donc :

includedirs([
    ...
])

links(["NKMath"])

Il n'y a pas de dependson dans cette première configuration.

Construction

J'ai lancé :

jenga build --project MonEssai --config Debug
Message obtenu

Le résultat est :

Build Order (1 projects):
  1. MonEssai [CONSOLE_APP]

ld: cannot find -lNKMath: No such file or directory
ld: have you installed the static version of the NKMath library ?
clang++: error: linker command failed with exit code 1
Analyse

Jenga ne considère pas NKMath comme une dépendance de construction de MonEssai.

On voit donc que l'ordre de construction ne contient qu'un seul projet :

Build Order (1 projects):
  1. MonEssai [CONSOLE_APP]

NKMath n'est pas construit avant MonEssai.

Cependant, links(["NKMath"]) demande à l'éditeur de liens de rechercher la bibliothèque NKMath.

Le linker cherche donc une bibliothèque correspondant à NKMath, mais celle-ci n'a pas été produite dans cette construction.

L'erreur obtenue est donc :

cannot find -lNKMath

Cela montre le rôle de dependson dans la construction : il permet à Jenga de connaître la relation entre les projets et donc de déterminer leur ordre de construction.

# 3. Test 2 — Remise de dependson et retrait de links

Modification effectuée

J'ai ensuite remis la dépendance vers NKMath, mais j'ai supprimé links.

La configuration devient donc :

includedirs([
    ...
])

dependson(["NKMath"])

Il n'y a plus de :

links(["NKMath"])
Construction

J'ai lancé à nouveau :

jenga build --project MonEssai --config Debug
Message obtenu

Le résultat observé est :

Build Order (6 projects):
  1. NKPlatform [STATIC_LIB]
  2. NKCore [STATIC_LIB]
  3. NKMemory [STATIC_LIB]
  4. NKContainers [STATIC_LIB]
  5. NKMath [STATIC_LIB]
  6. MonEssai [CONSOLE_APP] (depends: NKMath)

Compiled: main.cpp
Linking...
Built: Build\Bin\Debug-Windows\MonEssai\MonEssai.exe
Build Successful
Analyse

Cette fois, NKMath apparaît bien dans l'ordre de construction.

Jenga construit d'abord les dépendances nécessaires :

NKPlatform
NKCore
NKMemory
NKContainers
NKMath

puis construit :

MonEssai

On constate donc que dependson(["NKMath"]) permet à Jenga de savoir que MonEssai dépend de NKMath et qu'il faut construire NKMath avant MonEssai.

Le résultat est cependant différent de ce que l'on pourrait attendre théoriquement : malgré la suppression de links, l'édition de liens réussit.

Il n'y a donc pas ici d'erreur du type :

undefined reference to ...

La construction se termine par :

Build Successful
4. Différence entre les deux tests

Les deux expériences permettent de distinguer les rôles de dependson et links.

Test 1 : links sans dependson
links(["NKMath"])

mais pas de :

dependson(["NKMath"])

Résultat :

Build Order (1 projects)

Jenga ne construit pas NKMath.

Le linker cherche ensuite la bibliothèque :

NKMath

mais ne la trouve pas.

Erreur :

ld: cannot find -lNKMath

Le problème est donc que la dépendance n'a pas été prise en compte dans l'ordre de construction.

Test 2 : dependson sans links
dependson(["NKMath"])

mais pas de :

links(["NKMath"])

Résultat :

Build Order (6 projects)

Jenga construit bien NKMath avant MonEssai.
# Mon observation
Cet exercice montre que dependson et links ne jouent pas exactement le même rôle dans le modèle conceptuel.

Avec dependson, Jenga connaît la relation entre les projets et peut déterminer leur ordre de construction.

Avec links, on indique normalement à l'éditeur de liens quelle bibliothèque doit être utilisée.