#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Groupe {
    string nom;
    long long n, w, h;
};

int main() {
    long long P = 0, L = 0;
    int G = 0;
    cin >> P >> L >> G;

    vector<Groupe> g;
    for (int i = 0; i < G; i++) {
        Groupe x;
        if (!(cin >> x.nom >> x.n >> x.w >> x.h)) break;
        g.push_back(x);
    }
    if (g.empty()) {
        cout << "AUCUN\n";
        return 0;
    }

    long long W = L, occupe = 0;
    if (L == 0) {
        W = 512;
        long long besoin = 0;
        for (auto& x : g) besoin += x.n * (x.w + P) * (x.h + P);
        while (W * W < 2 * besoin && W < 4096) W *= 2;
    }
    for (auto& x : g) occupe += x.n * x.w * x.h;
    long long H = W;

    for (int essai = 1; essai <= 8; essai++) {
        long long cx = P, cy = P, e = 0;
        bool ok = true;
        vector<long long> pos(g.size() * 4, 0);

        for (size_t k = 0; k < g.size() && ok; k++) {
            long long rw = g[k].w + P, rh = g[k].h + P;
            for (long long i = 0; i < g[k].n; i++) {
                if (cx + rw > W - P) {
                    cx = P;
                    cy += e + P;
                    e = 0;
                    if (cx + rw > W - P) { ok = false; break; }
                }
                if (cy + rh > H - P) { ok = false; break; }
                if (i == 0) { pos[4 * k] = cx; pos[4 * k + 1] = cy; }
                pos[4 * k + 2] = cx;
                pos[4 * k + 3] = cy;
                cx += rw;
                e = max(e, rh);
            }
        }

        if (ok) {
            cout << "ESSAIS " << essai << "\nTEXTURE " << W << " " << H << "\n";
            for (size_t k = 0; k < g.size(); k++)
                cout << g[k].nom << " " << pos[4 * k] << " " << pos[4 * k + 1]
                     << " " << pos[4 * k + 2] << " " << pos[4 * k + 3] << "\n";
            cout << "OCCUPE " << occupe << "\n";
            cout << "PERDU " << (W * H - occupe) * 100 / (W * H) << "\n";
            return 0;
        }

        if (essai == 8) break;
        if (W == H) W *= 2;
        else H = W;
    }

    cout << "ESSAIS 8\nECHEC\n";
    return 0;
}