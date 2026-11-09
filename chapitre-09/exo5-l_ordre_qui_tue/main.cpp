#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Objet {
    std::string nom;
    std::vector<int> dependances;
    bool libere = false;
};

int main() {
    std::vector<Objet> objets;
    std::vector<std::vector<int>> blocs(1);
    std::unordered_map<std::string, int> identifiants;

    std::string commande;
    std::string nom;
    std::string autre;
    bool plantage = false;

    auto liberer = [&](int id, const std::string& action) {
        Objet& objet = objets[id];

        if (objet.libere) {
            return true;
        }

        for (int dependance : objet.dependances) {
            if (objets[dependance].libere) {
                std::cout << "PLANTAGE " << objet.nom << " "
                          << objets[dependance].nom << '\n';
                plantage = true;
                return false;
            }
        }

        objet.libere = true;
        std::cout << action << " " << objet.nom << '\n';
        return true;
    };

    while (!plantage && std::cin >> commande) {
        if (commande == "DECL") {
            std::cin >> nom;

            int id = static_cast<int>(objets.size());
            objets.push_back({nom, {}, false});
            identifiants[nom] = id;
            blocs.back().push_back(id);
        } else if (commande == "DEPEND") {
            std::cin >> nom >> autre;

            int id = identifiants[nom];
            int dependance = identifiants[autre];
            objets[id].dependances.push_back(dependance);
        } else if (commande == "FERME") {
            std::cin >> nom;

            int id = identifiants[nom];
            liberer(id, "FERME");
        } else if (commande == "{") {
            blocs.emplace_back();
        } else if (commande == "}") {
            for (auto it = blocs.back().rbegin();
                 it != blocs.back().rend(); ++it) {
                if (!liberer(*it, "DETRUIT")) {
                    break;
                }
            }

            blocs.pop_back();
        }
    }

    while (!plantage && !blocs.empty()) {
        for (auto it = blocs.back().rbegin();
             it != blocs.back().rend(); ++it) {
            if (!liberer(*it, "DETRUIT")) {
                break;
            }
        }

        blocs.pop_back();
    }

    if (!plantage) {
        std::cout << "PROPRE\n";
    }

    return 0;
}