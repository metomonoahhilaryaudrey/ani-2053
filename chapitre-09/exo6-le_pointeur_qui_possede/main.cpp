#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Instruction {
    std::string commande;
    std::string source;
    std::string destination;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Instruction> instructions;
    std::vector<int> lignesCopie;

    std::unordered_map<std::string, int> identifiants;
    std::vector<std::string> variables;

    auto enregistrerVariable = [&](const std::string& nom) {
        if (identifiants.find(nom) == identifiants.end()) {
            int id = static_cast<int>(variables.size());
            identifiants[nom] = id;
            variables.push_back(nom);
        }
    };

    for (int k = 1; k <= n; ++k) {
        Instruction instruction;
        std::cin >> instruction.commande;

        if (instruction.commande == "NEW"
            || instruction.commande == "RESET"
            || instruction.commande == "USE") {
            std::cin >> instruction.source;
            enregistrerVariable(instruction.source);
        } else if (instruction.commande == "MOVE"
                   || instruction.commande == "COPY") {
            std::cin >> instruction.source >> instruction.destination;

            enregistrerVariable(instruction.source);
            enregistrerVariable(instruction.destination);

            if (instruction.commande == "COPY") {
                lignesCopie.push_back(k);
            }
        }

        instructions.push_back(instruction);
    }

    if (!lignesCopie.empty()) {
        for (int ligne : lignesCopie) {
            std::cout << "REFUSE " << ligne << '\n';
        }
        return 0;
    }

    std::vector<int> possessions(variables.size(), 0);

    int crees = 0;
    int detruits = 0;
    int nuls = 0;

    auto detruire = [&](int objet) {
        if (objet != 0) {
            std::cout << "DETRUIT " << objet << '\n';
            ++detruits;
        }
    };

    for (int k = 0; k < n; ++k) {
        const Instruction& instruction = instructions[k];
        int source = identifiants[instruction.source];

        if (instruction.commande == "NEW") {
            ++crees;
            int nouvelObjet = crees;

            detruire(possessions[source]);
            possessions[source] = nouvelObjet;
        } else if (instruction.commande == "MOVE") {
            int destination = identifiants[instruction.destination];

            int objet = possessions[source];
            possessions[source] = 0;

            detruire(possessions[destination]);
            possessions[destination] = objet;
        } else if (instruction.commande == "RESET") {
            detruire(possessions[source]);
            possessions[source] = 0;
        } else if (instruction.commande == "USE") {
            if (possessions[source] == 0) {
                std::cout << "NUL " << k + 1 << " "
                          << instruction.source << '\n';
                ++nuls;
            }
        }
    }

    for (auto it = variables.rbegin(); it != variables.rend(); ++it) {
        int id = identifiants[*it];
        detruire(possessions[id]);
        possessions[id] = 0;
    }

    std::cout << "CREES " << crees << '\n';
    std::cout << "DETRUITS " << detruits << '\n';
    std::cout << "NULS " << nuls << '\n';

    return 0;
}