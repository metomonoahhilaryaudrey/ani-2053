#include <iostream>
#include <string>
#include <map>
#include <algorithm>

struct Monde {
    long long x, y, angle, echelle, niveau;
};

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, Monde> objets;
    long long profondeur = 0;

    for (int i = 0; i < N; i++) {
        std::string nom, parent;
        long long tx, ty, angle, echelle;
        std::cin >> nom >> parent >> tx >> ty >> angle >> echelle;

        Monde m;

        if (parent == "-") {
            
            m.x = tx;
            m.y = ty;
            m.angle = ((angle % 360) + 360) % 360;
            m.echelle = echelle;
            m.niveau = 1;
        } else {
            const Monde &p = objets[parent];

            
            long long ax = tx * p.echelle;
            long long ay = ty * p.echelle;

            
            long long c = 0, s = 0;
            if (p.angle == 0)        { c = 1;  s = 0;  }
            else if (p.angle == 90)  { c = 0;  s = 1;  }
            else if (p.angle == 180) { c = -1; s = 0;  }
            else                     { c = 0;  s = -1; } 

            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;

            
            m.x = p.x + rx;
            m.y = p.y + ry;

            
            m.angle = (((p.angle + angle) % 360) + 360) % 360;
            m.echelle = p.echelle * echelle;
            m.niveau = p.niveau + 1;
        }

        objets[nom] = m;
        profondeur = std::max(profondeur, m.niveau);

        std::cout << nom << " " << m.x << " " << m.y << " "
                  << m.angle << " " << m.echelle << "\n";
    }

    std::cout << "PROFONDEUR " << profondeur << "\n";
    return 0;
}