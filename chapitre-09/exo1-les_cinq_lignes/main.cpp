#include <iostream>
#include <string>
#include <array>
#include <algorithm>



enum Etat {
    ABSENT,
    ECRIT,
    DEFAUT,
    SUPPRIME
};

string nomEtat(Etat etat) {
    switch (etat) {
        case ABSENT: return "ABSENT";
        case ECRIT: return "ECRIT";
        case DEFAUT: return "DEFAUT";
        case SUPPRIME: return "SUPPRIME";
    }
    return "ABSENT";
}

int main() {
    string classe;
    getline(cin, classe);

    array<Etat, 5> etats = {
        ABSENT, ABSENT, ABSENT, ABSENT, ABSENT
    };

    const array<string, 5> noms = {
        "DESTRUCTEUR",
        "COPIE",
        "AFFECTATION_COPIE",
        "DEPLACEMENT",
        "AFFECTATION_DEPLACEMENT"
    };

    string ligne;

    while (getline(cin, ligne)) {
        
        size_t commentaire = ligne.find("//");
        if (commentaire != string::npos) {
            ligne = ligne.substr(0, commentaire);
        }

        
        ligne.erase(
            remove(ligne.begin(), ligne.end(), ' '),
            ligne.end()
        );

        if (ligne.empty()) {
            continue;
        }

        int membre = -1;

        // Reconnaître le destructeur.
        if (ligne.find("~" + classe + "(") != string::npos) {
            membre = 0;
        }

        
        else if (ligne.rfind(classe + "(const" + classe + "&", 0) == 0) {
            size_t pos = (classe + "(const" + classe + "&").size();

            if (pos >= ligne.size() || ligne[pos] != '&') {
                membre = 1;
            }
        }

        
        else if (ligne.rfind(classe + "&operator=(const" + classe + "&", 0) == 0) {
            size_t pos = (classe + "&operator=(const" + classe + "&").size();

            if (pos >= ligne.size() || ligne[pos] != '&') {
                membre = 2;
            }
        }

        
        else if (ligne.rfind(classe + "(" + classe + "&&", 0) == 0) {
            membre = 3;
        }

        
        else if (ligne.rfind(classe + "&operator=(" + classe + "&&", 0) == 0) {
            membre = 4;
        }

        if (membre != -1 && etats[membre] == ABSENT) {
            if (ligne.size() >= 8 &&
                ligne.compare(ligne.size() - 8, 8, "=delete;") == 0) {
                etats[membre] = SUPPRIME;
            }
            else if (ligne.size() >= 9 &&
                     ligne.compare(ligne.size() - 9, 9, "=default;") == 0) {
                etats[membre] = DEFAUT;
            }
            else {
                etats[membre] = ECRIT;
            }
        }
    }

    
    for (int i = 0; i < 5; i++) {
        cout << noms[i] << " " << nomEtat(etats[i]) << '\n';
    }

    
    int declares = 0;

    for (Etat etat : etats) {
        if (etat != ABSENT) {
            declares++;
        }
    }

    
    string regle;

    if (declares == 0) {
        regle = "ZERO";
    }
    else if (declares == 5) {
        regle = "CINQ";
    }
    else if (etats[0] != ABSENT &&
             etats[1] != ABSENT &&
             etats[2] != ABSENT &&
             etats[3] == ABSENT &&
             etats[4] == ABSENT) {
        regle = "TROIS";
    }
    else {
        regle = "INCOMPLETE";
    }

    cout << "REGLE " << regle << '\n';

    
    if (regle == "INCOMPLETE") {
        bool deplacementPresent =
            etats[3] != ABSENT || etats[4] != ABSENT;

        int limite = deplacementPresent ? 5 : 3;

        for (int i = 0; i < limite; i++) {
            if (etats[i] == ABSENT) {
                cout << "MANQUE " << noms[i] << '\n';
            }
        }
    }

    
    cout << "POSSEDE "
         << (etats[0] == ECRIT ? "OUI" : "NON")
         << '\n';

    
    bool unique =
        etats[1] == SUPPRIME &&
        (etats[3] == ECRIT || etats[3] == DEFAUT);

    cout << "UNIQUE " << (unique ? "OUI" : "NON") << '\n';

    return 0;
}