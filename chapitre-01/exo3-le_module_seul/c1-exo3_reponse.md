### 1-Pour commencer j'ai lancer `NKMath` avec:

``` jenga build --project NKMath ```

### 2-L'ordre de construction affiché par jengsa est:

#### .NKPlatorm
#### .NKCore
#### .NKMemory
#### .NKContenairs
#### .NKMath

### 3- Construction de l'arbre

         
                            
                          ________________  
                         |                |\
                       / |     NKMath     | \
                     /   |________________|  \______________
                    /        |           |                   \
                             |           |                    \
           dépend de    dépend de        dépend de           dépend de
                |              |             \                  |
          _____________     ___________      _________        ________               
         |             |   |           |    |         |      |           |
         | NKContenairs|   | NKMemory  |    | NKCore  |      | NKPlatform|   
         |_____________|   |___________|    |_________|      |___________| 
         /       |      \
        /        |       \
        |        |        \
    dépend de  dépend de    dépend de
        |          |            |
    _________     _______      __________
   |         |   |       |    |          |
   |NKMemory |   |NKCore |    |NKPlatform|            
   |_________|   |_______|    |__________|            
    /        \
  dépend de   dépend de
       |             |
   _________      ____________
  |         |    |            |
  | NKCore  |    | NKPlatform |
  |_________|    |____________|
       |
     ___________
    |           |
    |NKPlatform |
    |___________|



    ###  4-la sortie complete de jenga
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.85s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           1.56s
Status:         ✓ SUCCESS





NKMath
  |
NKContainers



 ______________
|              |
|              |
|______________|
