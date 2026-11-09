#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct TypeInfo {
    std::string nom;
    bool doitInclure = false;
};

int main() {
    int u;
    std::cin >> u;

    std::vector<TypeInfo> types;
    std::unordered_map<std::string, int> identifiants;

    int nombreInclure = 0;
    int nombreAnticiper = 0;

    for (int i = 0; i < u; ++i) {
        std::string nom;
        std::string emploi;

        std::cin >> nom >> emploi;

        auto it = identifiants.find(nom);
        int id;

        if (it == identifiants.end()) {
            id = static_cast<int>(types.size());
            identifiants[nom] = id;
            types.push_back({nom, false});
        } else {
            id = it->second;
        }

        if (emploi == "VALEUR"
            || emploi == "BASE"
            || emploi == "CORPS"
            || emploi == "TAILLE") {
            types[id].doitInclure = true;
        }
    }

    int a;
    std::cin >> a;

    std::unordered_set<std::string> inclusActuellement;

    for (int i = 0; i < a; ++i) {
        std::string nom;
        std::cin >> nom;
        inclusActuellement.insert(nom);
    }

    int inclusionsRetirees = 0;

    for (const TypeInfo& type : types) {
        if (type.doitInclure) {
            std::cout << type.nom << " INCLURE\n";
            ++nombreInclure;
        } else {
            std::cout << type.nom << " ANTICIPER\n";
            ++nombreAnticiper;

            if (inclusActuellement.find(type.nom)
                != inclusActuellement.end()) {
                ++inclusionsRetirees;
            }
        }
    }

    std::cout << "INCLURE " << nombreInclure << '\n';
    std::cout << "ANTICIPER " << nombreAnticiper << '\n';
    std::cout << "INCLUSIONS_RETIREES "
              << inclusionsRetirees << '\n';

    return 0;
}