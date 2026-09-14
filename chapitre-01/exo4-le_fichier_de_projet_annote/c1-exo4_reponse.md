Fichier choisi : .../NKCore/NKCore.jenga

#!/usr/bin/env python3
## ?

# -*- coding: utf-8 -*-
## Définit l'encodage du fichier en UTF-8.

"""
NKCore — Types, macros, assertions, opérations bit (C++20)
===========================================================
S'appuie sur NKPlatform pour les types fixes et macros fondamentaux
réutilisés par toutes les couches supérieures.
"""
## Présente le rôle de NKCore : il fournit des types, macros, assertions
## et opérations sur les bits. Il s'appuie sur NKPlatform pour certains
## éléments fondamentaux utilisés par les autres couches.

from Jenga import *
## Importe les fonctions de Jenga nécessaires pour définir et configurer
## le projet.

from jengaconfig import *
## Importe les configurations définies pour le workspace et utilisées
## notamment pour les plateformes et les outils de compilation.

with project("NKCore"):
## Définit le projet NKCore.
## Type : StaticLib ?
## Le fichier correspond à un module qui produit une bibliothèque.
## À vérifier avec la déclaration/configuration générale du projet.

    language("C++")
## Définit le langage utilisé pour compiler NKCore : C++.

    cppdialect("C++20")
## Définit le standard C++ utilisé par le projet : C++20.
## Cela permet au code source de NKCore d'utiliser les fonctionnalités
## introduites par cette version du langage.

    location(".")
## Définit le répertoire de référence du projet comme étant le répertoire
## courant contenant le fichier NKCore.jenga.

    nkentseudependson(
## Déclare les dépendances de NKCore vis-à-vis d'autres modules.

        ["NKPlatform"],
## NKCore dépend de NKPlatform. Cela signifie que NKCore peut utiliser
## les éléments fournis par NKPlatform et que cette dépendance doit être
## connue lors de la construction du projet.

        selfexport="NKCore",
## Exporte NKCore comme dépendance utilisable par les autres projets
## qui dépendent de ce module.
## ?

        extra_includes=["src", "pch"],
## Ajoute les répertoires "src" et "pch" aux chemins de recherche des
## fichiers d'en-tête. Les fichiers inclus par le code peuvent donc être
## recherchés dans ces répertoires.
## ?

    )

    pchheader("pch/pch.h")
## Définit le fichier d'en-tête utilisé comme précompiled header (PCH).
## Ce fichier peut être précompilé afin d'éviter de recompilier certaines
## déclarations communes à chaque fichier source.
## ?

    pchsource("pch/pch.cpp")
## Définit le fichier source associé au précompiled header de NKCore.
## ?

    files([
## Déclare les fichiers qui appartiennent au projet NKCore.

        "src/NKCore/**.cpp",
## Inclut les fichiers source C++ présents dans src/NKCore.

        "src/NKCore/**.h",
## Inclut les fichiers d'en-tête présents dans src/NKCore.

    ])
## Fin de la liste des fichiers sources du module.

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
## Définit le répertoire dans lequel Jenga place les fichiers objets
## intermédiaires produits pendant la compilation.
## Le chemin dépend notamment de la configuration, du système et du nom
## du projet.
## ?

    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")
## Définit le répertoire dans lequel est placé le résultat final de la
## compilation de NKCore, ici dans le répertoire des bibliothèques.
## ?

    with filter("system:Windows && options:windows-runtime=uwp"):
## Applique les règles suivantes uniquement lorsque le système est Windows
## et que l'option Windows Runtime UWP est activée.

        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
## Pour cette configuration UWP, les fichiers objets sont placés dans un
## répertoire spécifique afin de les séparer des autres builds Windows.

        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")
## Pour UWP, la bibliothèque produite est placée dans un répertoire
## spécifique à cette configuration.

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
## Applique cette configuration à Windows classique, en excluant UWP
## ainsi que les consoles Xbox.

        usetoolchain(TC_WINDOWS)
## Sélectionne la toolchain utilisée pour compiler NKCore sur Windows
## classique.
## ?

    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):
## Sélectionne cette règle pour UWP ou pour Windows configuré avec
## le runtime Windows UWP.

        usetoolchain("xbox-clang")
## Sélectionne la toolchain "xbox-clang" pour cette configuration.
## ?

    with filter("system:macOS"):
## Applique la règle lorsque la plateforme ciblée est macOS.

        usetoolchain("clang-native")
## Utilise la toolchain clang-native pour compiler NKCore sur macOS.

    with filter("system:Android"):
## Applique la règle lorsque la plateforme ciblée est Android.

        # Workaround: disable PCH on Android (NDK r27 + clang 18 + libc++)
## Explique pourquoi le PCH est désactivé sur Android : une contrainte
## liée à la combinaison du NDK r27, de clang 18 et de libc++.

        pchheader("")
## Désactive le précompiled header pour Android.
## ?
        pchsource("")
## Désactive également le fichier source associé au PCH pour Android.
## ?

        usetoolchain("android-ndk")
## Utilise la toolchain Android NDK pour construire NKCore sur Android.

    with filter("system:HarmonyOS"):
## Applique la règle lorsque la plateforme ciblée est HarmonyOS.

        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android)
## Indique que le PCH est désactivé à cause d'une contrainte similaire
## à celle rencontrée sur Android avec le compilateur clang du NDK OHOS.

        pchheader("")
## Désactive le précompiled header sur HarmonyOS.

        pchsource("")
## Désactive le fichier source du PCH sur HarmonyOS.

        usetoolchain("ohos-ndk")
## Utilise la toolchain OHOS NDK pour compiler NKCore sur HarmonyOS.

    with filter("system:Web"):
## Applique cette règle lorsque la plateforme cible est le Web.

        usetoolchain("emscripten")
## Utilise Emscripten comme toolchain pour compiler NKCore vers le Web.

    with filter("system:XboxSeries || system:XboxOne"):
## Applique cette règle aux consoles Xbox Series et Xbox One.

        usetoolchain("xbox-clang")
## Utilise la toolchain xbox-clang pour compiler NKCore sur les consoles Xbox.

    with filter("config:Debug"):
## Applique les paramètres suivants lorsque la configuration de compilation
## est Debug.

        defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"])
## Définit les macros de compilation utilisées pour identifier une build
## Debug dans le code source.

        optimize("Off")
## Désactive les optimisations du compilateur afin de faciliter le
## débogage.

        symbols(True)
## Active les symboles de débogage pour permettre notamment d'utiliser
## les informations nécessaires au debugger.

    with filter("config:Release"):
## Applique les paramètres suivants lorsque la configuration est Release.

        defines(["NDEBUG", "RELEASE", "NKENTSEU_RELEASE"])
## Définit les macros indiquant que le code est compilé en mode Release.

        optimize("Speed")
## Active une optimisation orientée vers les performances d'exécution.

        symbols(False)
## Désactive les symboles de débogage afin de produire une version destinée
## à l'utilisation finale.

    # Tests unitaires/benchmarks (desktop uniquement)
## Indique que la partie suivante concerne les tests unitaires et les
## benchmarks, principalement pour les plateformes de bureau.

    with filter("(system:Linux || system:macOS || (system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS || system:Web"):
## Active les tests pour Linux, macOS, Windows classique et Web.
## Android et iOS sont exclus, ainsi que UWP et les plateformes Xbox
## dans le cas de Windows.

        with test():
