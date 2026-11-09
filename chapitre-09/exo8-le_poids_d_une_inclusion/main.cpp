#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool terminePar(const std::string& nom, const std::string& extension) {
    if (nom.size() < extension.size()) {
        return false;
    }

    return nom.compare(
        nom.size() - extension.size(),
        extension.size(),
        extension
    ) == 0;
}

int compterRecompilations(
    int depart,
    const std::vector<std::vector<int>>& dependants,
    const std::vector<bool>& estCpp
) {
    std::vector<bool> visite(dependants.size(), false);
    std::vector<int> pile;

    pile.push_back(depart);
    visite[depart] = true;

    int total = 0;

    while (!pile.empty()) {
        int courant = pile.back();
        pile.pop_back();

        if (estCpp[courant]) {
            ++total;
        }

        for (int suivant : dependants[courant]) {
            if (!visite[suivant]) {
                visite[suivant] = true;
                pile.push_back(suivant);
            }
        }
    }

    return total;
}

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> identifiants;
    std::vector<std::string> fichiers(n);
    std::vector<std::vector<std::string>> inclusions(n);
    std::vector<bool> estCpp(n, false);
    std::vector<bool> estHeader(n, false);

    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> fichiers[i] >> k;

        identifiants[fichiers[i]] = i;

        estCpp[i] = terminePar(fichiers[i], ".cpp");
        estHeader[i] = terminePar(fichiers[i], ".h");

        for (int j = 0; j < k; ++j) {
            std::string inclusion;
            std::cin >> inclusion;
            inclusions[i].push_back(inclusion);
        }
    }

    std::vector<std::vector<int>> dependants(n);

    for (int i = 0; i < n; ++i) {
        for (const std::string& inclusion : inclusions[i]) {
            auto it = identifiants.find(inclusion);

            if (it != identifiants.end()) {
                int inclus = it->second;
                dependants[inclus].push_back(i);
            }
        }
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::string nom;
        std::cin >> nom;

        auto it = identifiants.find(nom);

        if (it != identifiants.end()) {
            int resultat = compterRecompilations(
                it->second,
                dependants,
                estCpp
            );

            std::cout << nom << " " << resultat << '\n';
        }
    }

    bool trouveHeader = false;
    std::string headerPlusLourd;
    int poidsMaximum = 0;

    for (int i = 0; i < n; ++i) {
        if (!estHeader[i]) {
            continue;
        }

        int poids = compterRecompilations(i, dependants, estCpp);

        if (!trouveHeader || poids > poidsMaximum) {
            trouveHeader = true;
            poidsMaximum = poids;
            headerPlusLourd = fichiers[i];
        }
    }

    if (trouveHeader) {
        std::cout << "PLUS_LOURD " << headerPlusLourd
                  << " " << poidsMaximum << '\n';
    } else {
        std::cout << "PLUS_LOURD AUCUN\n";
    }

    return 0;
}