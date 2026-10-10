#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Fmt {
    int octets;
    bool couleur, transp, flottant;
};

int main() {
    const map<string, Fmt> table = {
        {"GRAY8",    {1,  false, false, false}},
        {"GRAY_A16", {2,  false, true,  false}},
        {"RGB24",    {3,  true,  false, false}},
        {"RGBA32",   {4,  true,  true,  false}},
        {"RGB96F",   {12, true,  false, true}},
        {"RGBA128F", {16, true,  true,  true}},
    };

    long long w = 0, h = 0;
    int N = 0;
    cin >> w >> h >> N;

    long long total = 0, sansPerte = 0, refuses = 0;

    while (N-- > 0) {
        string s, c;
        if (!(cin >> s >> c)) break;

        auto is = table.find(s), ic = table.find(c);
        if (is == table.end() || ic == table.end()) {
            cout << s << " " << c << " REFUSE\n";
            refuses++;
            continue;
        }
        const Fmt& a = is->second;
        const Fmt& b = ic->second;

        long long os = w * h * a.octets;
        long long oc = w * h * b.octets;

        string pertes;
        auto ajouter = [&](const string& p) {
            if (!pertes.empty()) pertes += "+";
            pertes += p;
        };
        if (a.transp && !b.transp) ajouter("TRANSPARENCE");
        if (a.couleur && !b.couleur) ajouter("COULEUR");
        if (a.flottant && !b.flottant) ajouter("ETENDUE");
        if (pertes.empty()) {
            pertes = "AUCUNE";
            sansPerte++;
        }

        cout << s << " " << c << " " << os << " " << oc << " " << pertes << "\n";
        total += oc;
    }

    cout << "TOTAL " << total << "\nSANS_PERTE " << sansPerte
         << "\nREFUSES " << refuses << "\n";
    return 0;
}