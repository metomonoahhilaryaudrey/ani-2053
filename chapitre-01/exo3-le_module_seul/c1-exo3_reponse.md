### 1-Pour commencer j'ai lancer `NKMath` avec:

``` jenga build --project NKMath ```

### 2-L'ordre de construction affiché par jengsa est:

#### .NKPlatorm
#### .NKCore
#### .NKMemory
#### .NKContenairs
#### .NKMath

### 3- Construction de l'arbre


         _________________
        |                 |
        |     NKMath      |
        |_________________| 
                |
         _______|_________
        |                 |
        |   NKContenairs  |
        |_________________|
                |
         _______|_________        
        |                 |
        |   NKMemory      | 
        |_________________|
                |
         _______|__________         
        |                  |
        |       NKCore     |
        |__________________|
                 |
          ________________
         |                |
         |   NKPlatform   |   
         |________________|