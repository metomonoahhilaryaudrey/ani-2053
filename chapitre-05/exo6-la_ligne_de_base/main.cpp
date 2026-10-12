
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

struct Glyphe {
    int avance;
    int x0, y0, x1, y1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G;
    cin >> G;

    map<char, Glyphe> glyphes;

    for (int i = 0; i < G; i++) {
        char c;
        Glyphe g;
        cin >> c >> g.avance >> g.x0 >> g.y0 >> g.x1 >> g.y1;
        glyphes[c] = g;
    }

    int K;
    cin >> K;

    map<string, int> crenages;

    for (int i = 0; i < K; i++) {
        char a, b;
        int k;
        cin >> a >> b >> k;
        crenages[string(1, a) + b] = k;
    }

    string texte;
    int ox, oy;
    cin >> texte >> ox >> oy;

    int x = ox;
    int absents = 0;

    bool premierRectangle = true;
    int minx = numeric_limits<int>::max();
    int miny = numeric_limits<int>::max();
    int maxx = numeric_limits<int>::min();
    int maxy = numeric_limits<int>::min();

    for (size_t i = 0; i < texte.size(); i++) {
        char c = texte[i];

        auto it = glyphes.find(c);

        if (it == glyphes.end()) {
            cout << c << " ABSENT\n";
            absents++;
            continue;
        }

        const Glyphe& g = it->second;

        cout << c << " " << x << "\n";

        
        if (g.x1 > g.x0 && g.y1 > g.y0) {
            int gx0 = x + g.x0;
            int gy0 = oy + g.y0;
            int gx1 = x + g.x1;
            int gy1 = oy + g.y1;

            if (premierRectangle) {
                minx = gx0;
                miny = gy0;
                maxx = gx1;
                maxy = gy1;
                premierRectangle = false;
            } else {
                minx = min(minx, gx0);
                miny = min(miny, gy0);
                maxx = max(maxx, gx1);
                maxy = max(maxy, gy1);
            }
        }

        
        x += g.avance;

        
        if (i + 1 < texte.size()) {
            char suivant = texte[i + 1];

            if (glyphes.find(suivant) != glyphes.end()) {
                string paire;
                paire += c;
                paire += suivant;

                auto itK = crenages.find(paire);
                if (itK != crenages.end()) {
                    x += itK->second;
                }
            }
        }
    }

    cout << "CURSEUR " << x << "\n";

    if (premierRectangle) {
        cout << "BOITE AUCUNE\n";
        cout << "MONTE 0\n";
        cout << "DESCEND 0\n";
        cout << "ECRAN RIEN\n";
    } else {
        cout << "BOITE "
             << minx << " "
             << miny << " "
             << maxx << " "
             << maxy << "\n";

        int monte = (miny < oy) ? oy - miny : 0;
        int descend = (maxy > oy) ? maxy - oy : 0;

        cout << "MONTE " << monte << "\n";
        cout << "DESCEND " << descend << "\n";

        if (maxy <= 0) {
            cout << "ECRAN HORS\n";
        } else if (miny < 0) {
            cout << "ECRAN COUPE\n";
        } else {
            cout << "ECRAN VISIBLE\n";
        }
    }

    cout << "ABSENTS " << absents << "\n";

    return 0;
}

