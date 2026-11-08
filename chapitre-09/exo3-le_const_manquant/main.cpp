#include <iostream>
#include <string>
#include <vector>

struct Methode
{
    std::string nom;
    bool declareeConst;
    bool modifie;
    std::vector<int> appels;
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<Methode> methodes(n);

    for (int i = 0; i < n; i++)
    {
        std::string declaration;
        int modifie;
        int k;

        std::cin >> methodes[i].nom >> declaration >> modifie >> k;

        methodes[i].declareeConst = (declaration == "const");
        methodes[i].modifie = (modifie == 1);

        for (int j = 0; j < k; j++)
        {
            std::string nomAppel;
            std::cin >> nomAppel;

            for (int p = 0; p < n; p++)
            {
                if (methodes[p].nom == nomAppel)
                {
                    methodes[i].appels.push_back(p);
                    break;
                }
            }
        }
    }

    std::vector<bool> pourrait(n, false);

    
    for (int i = 0; i < n; i++)
    {
        if (!methodes[i].declareeConst && !methodes[i].modifie)
        {
            pourrait[i] = true;
        }
    }

    
    bool changement = true;

    while (changement)
    {
        changement = false;

        for (int i = 0; i < n; i++)
        {
            if (!pourrait[i])
            {
                continue;
            }

            for (int appel : methodes[i].appels)
            {
                if (!methodes[appel].declareeConst && !pourrait[appel])
                {
                    pourrait[i] = false;
                    changement = true;
                    break;
                }
            }
        }
    }

    
    std::cout << "POURRAIT";

    bool existe = false;

    for (int i = 0; i < n; i++)
    {
        if (pourrait[i])
        {
            std::cout << " " << methodes[i].nom;
            existe = true;
        }
    }

    if (!existe)
    {
        std::cout << " AUCUN";
    }

    std::cout << '\n';

    
    std::cout << "RACINES";

    existe = false;

    for (int i = 0; i < n; i++)
    {
        if (!pourrait[i])
        {
            continue;
        }

        bool racine = true;

        for (int appel : methodes[i].appels)
        {
            if (!methodes[appel].declareeConst)
            {
                racine = false;
                break;
            }
        }

        if (racine)
        {
            std::cout << " " << methodes[i].nom;
            existe = true;
        }
    }

    if (!existe)
    {
        std::cout << " AUCUN";
    }

    std::cout << '\n';

    
    std::vector<bool> corrigee(n, false);

    for (int i = 0; i < n; i++)
    {
        if (methodes[i].declareeConst)
        {
            corrigee[i] = true;
        }
    }

    int passes = 0;
    int nombreRestant = 0;

    for (int i = 0; i < n; i++)
    {
        if (pourrait[i])
        {
            nombreRestant++;
        }
    }

    while (nombreRestant > 0)
    {
        std::vector<int> aCorriger;

        for (int i = 0; i < n; i++)
        {
            if (!pourrait[i] || corrigee[i])
            {
                continue;
            }

            bool appelsCorriges = true;

            for (int appel : methodes[i].appels)
            {
                if (!corrigee[appel])
                {
                    appelsCorriges = false;
                    break;
                }
            }

            if (appelsCorriges)
            {
                aCorriger.push_back(i);
            }
        }

        
        for (int indice : aCorriger)
        {
            corrigee[indice] = true;
            nombreRestant--;
        }

        passes++;
    }

    std::cout << "PASSES " << passes << '\n';

    return 0;
}