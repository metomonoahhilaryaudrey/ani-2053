
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, C;
    cin >> D >> C;

    int N;
    cin >> N;

    vector<long long> instants(N);

    for (int i = 0; i < N; i++) {
        cin >> instants[i];
    }

    int voixMax = 0;
    long long retardMax = 0;
    int coupes = 0;

    long long finChargementPrecedent = 0;

    for (int i = 0; i < N; i++) {
        long long t = instants[i];

        
        int voix = 0;

        for (int j = 0; j <= i; j++) {
            if (instants[j] + D > t) {
                voix++;
            }
        }

        
        long long debutChargement = max(t, finChargementPrecedent);
        long long finChargement = debutChargement + C;
        long long retard = finChargement - t;

        finChargementPrecedent = finChargement;

        
        string etat = "ENTIER";

        if (i + 1 < N && instants[i + 1] < t + D) {
            etat = "COUPE";
            coupes++;
        }

        cout << t << " "
             << voix << " "
             << retard << " "
             << etat << "\n";

        voixMax = max(voixMax, voix);
        retardMax = max(retardMax, retard);
    }

    cout << "VOIX_MAX " << voixMax << "\n";
    cout << "RETARD_MAX " << retardMax << "\n";
    cout << "COUPES " << coupes << "\n";

    return 0;
}

