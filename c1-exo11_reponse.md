Exercice 11 — Casser exprès
# 1. Faute de syntaxe

J’ai volontairement ajouté une faute de syntaxe au début du fichier :

Kernel\Foundation\NKMath\src\NKMath\NkVec.cpp

La ligne ajoutée était :

CECI_EST_UNE_FAUTE_DE_SYNTAXE +++ ;;;

Puis j’ai lancé :

jenga build --config Debug
# 2. Résultat de la construction

La construction prévoyait 227 projets.

L’erreur apparaît lors de la construction de NKMath :

Compilation Error: NkVec.cpp

error: unknown type name 'CECI_EST_UNE_FAUTE_DE_SYNTAXE'
error: expected unqualified-id

Compilation failed: NkVec.cpp
Build Failed — Time: 0.87s — Errors: 2

BUILD FAILED
Projects Built: 9/227
Not reached: 217
Errors: 2
Time: 5.09s
Temps avant l’arrêt

La construction s’est arrêtée après 5,09 secondes.

Projets construits avant l’erreur

Les 9 projets construits avant l’échec de NKMath sont :

NKPlatform
NKGlad
NKGLSlang
NKSPIRVCross
NKMbedTLS
pybind11
NKCore
NKMemory
NKContainers

Ensuite, Jenga arrive à NKMath, trouve l’erreur dans NkVec.cpp et arrête la construction.

# 3. Ce que cela montre sur l’ordre de construction

Le message du clone 1 :

Not reached: 217

montre que Jenga suit un ordre de construction déterminé à partir des dépendances.

NKMath arrive en 10e position dans l’ordre. Les projets nécessaires avant lui sont donc construits en premier. Lorsque NKMath échoue, Jenga n’essaie pas automatiquement les 217 projets suivants.

Cela montre que l'ordre de construction est important : Jenga construit les projets dans l'ordre calculé et s'arrête au premier échec, sauf si on utilise une option comme --keep-going.

# 4. Restauration

J’ai ensuite remis le fichier dans son état initial et relancé la construction de NKMath :

jenga build --project NKMath --config Debug

Résultat : NKMath est de nouveau construit avec succès, avec ses 12 fichiers sources