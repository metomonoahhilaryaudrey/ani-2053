#include <iostream>
#include <vector>
#include <string>

int main()
{
    int S, V, F;
    std::cin >> S >> V >> F;

    int N;
    std::cin >> N;

    std::vector<int> tableau;
    std::vector<bool> liberees(1, false);

    int creees = 0;
    bool plantage = false;

    auto liberer = [&](int texture, int nombre, const std::string& moment)
    {
        for (int i = 0; i < nombre; i++)
        {
            if (liberees[texture])
            {
                std::cout << "PLANTAGE "
                          << moment << " TEXTURE "
                          << texture << '\n';

                plantage = true;
                return false;
            }

            liberees[texture] = true;
        }

        return true;
    };

    for (int operation = 1; operation <= N && !plantage; operation++)
    {
        std::string commande;
        std::cin >> commande;

        if (commande == "AJOUTE")
        {
            creees++;
            tableau.push_back(creees);
            liberees.push_back(false);
        }
        else if (commande == "SUPPRIME")
        {
            int index;
            std::cin >> index;

            int texture = tableau[index];

            if (!liberer(texture, S, std::to_string(operation)))
            {
                break;
            }

            tableau.erase(tableau.begin() + index);
        }
        else if (commande == "VIDE")
        {
            for (int texture : tableau)
            {
                if (!liberer(texture, V, std::to_string(operation)))
                {
                    break;
                }
            }

            if (!plantage)
            {
                tableau.clear();
            }
        }
    }

    if (plantage)
    {
        return 0;
    }

    
    for (int texture : tableau)
    {
        if (!liberer(texture, F, "FIN"))
        {
            break;
        }
    }

    if (plantage)
    {
        return 0;
    }

    
    std::vector<int> perdues;

    for (int texture = 1; texture <= creees; texture++)
    {
        if (!liberees[texture])
        {
            perdues.push_back(texture);
        }
    }

    std::cout << "CREEES " << creees << '\n';
    std::cout << "FUITES " << perdues.size() << '\n';

    std::cout << "PERDUES";

    if (perdues.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (int texture : perdues)
        {
            std::cout << " " << texture;
        }
    }

    std::cout << '\n';

    return 0;
}