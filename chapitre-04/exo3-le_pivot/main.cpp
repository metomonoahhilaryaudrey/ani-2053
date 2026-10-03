#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    long long refuses = 0;

    for (int i = 0; i < N; i++) {
        std::string nom;
        long long w, h, px, py, ox, oy, sx, sy, angle;
        std::cin >> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angle;

        
        if (angle % 90 != 0) {
            std::cout << nom << " ANGLE REFUSE\n";
            refuses++;
            continue;
        }

        
        long long a = ((angle % 360) + 360) % 360;

        long long c = 0, s = 0;
        if (a == 0)        { c = 1;  s = 0;  }
        else if (a == 90)  { c = 0;  s = 1;  }
        else if (a == 180) { c = -1; s = 0;  }
        else               { c = 0;  s = -1; } // 270

        
        long long lx[4] = {0, w, w, 0};
        long long ly[4] = {0, 0, h, h};

        long long wx[4], wy[4];
        for (int k = 0; k < 4; k++) {
            
            long long ax = (lx[k] - ox) * sx;
            long long ay = (ly[k] - oy) * sy;
            // 3) tourner
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;
            
            wx[k] = px + rx;
            wy[k] = py + ry;
        }

        long long minx = wx[0], maxx = wx[0], miny = wy[0], maxy = wy[0];
        for (int k = 1; k < 4; k++) {
            minx = std::min(minx, wx[k]);
            maxx = std::max(maxx, wx[k]);
            miny = std::min(miny, wy[k]);
            maxy = std::max(maxy, wy[k]);
        }

        std::cout << nom << " COINS "
                  << wx[0] << " " << wy[0] << " "
                  << wx[1] << " " << wy[1] << " "
                  << wx[2] << " " << wy[2] << " "
                  << wx[3] << " " << wy[3] << "\n";
        std::cout << nom << " BOITE "
                  << minx << " " << miny << " "
                  << maxx << " " << maxy << "\n";
    }

    std::cout << "REFUSES " << refuses << "\n";
    return 0;
}