#include <iostream>
#include <string>

int main() {
    long long v;
    int N;
    std::cin >> v >> N;

    long long xe = 0, xi = 0;
    long long sautsEv = 0, sautsInt = 0, manques = 0;

    bool space = false, left = false, right = false;

    for (int i = 1; i <= N; i++) {
        int k;
        std::cin >> k;

        long long plusSpaceCetteImage = 0;

        for (int j = 0; j < k; j++) {
            std::string ev;
            std::cin >> ev;

            char signe = ev[0];
            std::string nom = ev.substr(1);
            bool enfoncee = (signe == '+');

            if (nom == "SPACE") {
                space = enfoncee;
                if (enfoncee) {
                    sautsEv++;             
                    plusSpaceCetteImage++;
                }
            } else if (nom == "RIGHT") {
                right = enfoncee;
                if (enfoncee) xe += v;
            } else if (nom == "LEFT") {
                left = enfoncee;
                if (enfoncee) xe -= v;
            }
            
        }

        
        if (space) sautsInt++;
        if (right) xi += v;
        if (left) xi -= v;

        
        if (plusSpaceCetteImage > 0 && !space) {
            manques += plusSpaceCetteImage;
        }

        std::cout << i << " " << xe << " " << xi << "\n";
    }

    std::cout << "SAUTS EVENEMENTS " << sautsEv << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsInt << "\n";
    std::cout << "MANQUES " << manques << "\n";

    return 0;
}