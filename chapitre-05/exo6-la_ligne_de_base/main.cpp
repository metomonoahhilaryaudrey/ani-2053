#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Glyphe {
    long long avance, x0, y0, x1, y1;
};

int main() {
    int G = 0, K = 0;
    cin >> G;
    map<char, Glyphe> table;
    for (int i = 0; i < G; i++) {
        string c;
        Glyphe g;
        cin >> c >> g.avance >> g.x0 >> g.y0 >> g.x1 >> g.y1;
        table[c[0]] = g;
    }

    cin >> K;
    map<string, long long> crenage;
    for (int i = 0; i < K; i++) {
        string ab;
        long long k;
        cin >> ab >> k;
        crenage[ab] = k;
    }

    string texte;
    long long ox = 0, oy = 0;
    cin >> texte >> ox >> oy;

    long long x = ox, absents = 0;
    bool dessine = false;
    long long minx = 0, miny = 0, maxx = 0, maxy = 0;

    for (size_t i = 0; i < texte.size(); i++) {
        char c = texte[i];
        auto it = table.find(c);
        if (it == table.end()) {
            cout << c << " ABSENT\n";
            absents++;
            continue;
        }
        const Glyphe& g = it->second;
        cout << c << " " << x << "\n";

        if (g.x1 > g.x0 && g.y1 > g.y0) {
            long long rx0 = x + g.x0, ry0 = oy + g.y0;
            long long rx1 = x + g.x1, ry1 = oy + g.y1;
            if (!dessine) {
                minx = rx0; miny = ry0; maxx = rx1; maxy = ry1;
                dessine = true;
            } else {
                minx = min(minx, rx0); miny = min(miny, ry0);
                maxx = max(maxx, rx1); maxy = max(maxy, ry1);
            }
        }

        x += g.avance;
        if (i + 1 < texte.size()) {
            auto k = crenage.find(string() + c + texte[i + 1]);
            if (k != crenage.end()) x += k->second;
        }
    }

    cout << "CURSEUR " << x << "\n";
    if