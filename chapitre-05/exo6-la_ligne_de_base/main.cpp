#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Glyphe { ll avance, x0, y0, x1, y1; };


static vector<string> decouper(const string& s) {
    vector<string> r;
    for (size_t i = 0; i < s.size();) {
        unsigned char c = s[i];
        size_t len = 1;
        if (c >= 0xF0) len = 4;
        else if (c >= 0xE0) len = 3;
        else if (c >= 0xC0) len = 2;
        if (i + len > s.size()) len = s.size() - i;
        r.push_back(s.substr(i, len));
        i += len;
    }
    return r;
}

int main() {
    int G = 0, K = 0;
    cin >> G;
    map<string, Glyphe> table;
    for (int i = 0; i < G; i++) {
        string c;
        Glyphe g;
        cin >> c >> g.avance >> g.x0 >> g.y0 >> g.x1 >> g.y1;
        table[c] = g;
    }

    cin >> K;
    map<pair<string, string>, ll> crenage;
    for (int i = 0; i < K; i++) {
        string ab;
        ll k;
        cin >> ab >> k;
        vector<string> p = decouper(ab);
        if (p.size() == 2) crenage[{p[0], p[1]}] = k;
    }

    string brut;
    ll ox = 0, oy = 0;
    cin >> brut >> ox >> oy;
    vector<string> texte = decouper(brut);

    ll x = ox, absents = 0;
    bool dessine = false;
    ll minx = 0, miny = 0, maxx = 0, maxy = 0;

    for (size_t i = 0; i < texte.size(); i++) {
        const string& c = texte[i];
        auto it = table.find(c);
        if (it == table.end()) {
            cout << c << " ABSENT\n";
            absents++;
            continue;
        }
        const Glyphe& g = it->second;
        cout << c << " " << x << "\n";

        if (g.x1 > g.x0 && g.y1 > g.y0) {
            ll rx0 = x + g.x0, ry0 = oy + g.y0;
            ll rx1 = x + g.x1, ry1 = oy + g.y1;
            if (!dessine) {
                minx = rx0; miny = ry0; maxx = rx1; maxy = ry1;
