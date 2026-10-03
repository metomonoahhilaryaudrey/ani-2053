#include <iostream>

int main() {
    long long C, R, W, H, F, D, P;
    std::cin >> C >> R >> W >> H >> F >> D >> P;

    long long N;
    std::cin >> N;

    long long accumule = 0;   
    long long caseCourante = 0;
    long long avances = 0;
    long long plafonnes = 0;

    for (long long i = 0; i < N; i++) {
        long long dt;
        std::cin >> dt;

        
        if (dt > P) {
            dt = P;
            plafonnes++;
        }

        
        accumule += dt;

        
        while (accumule >= D) {
            accumule -= D;
            caseCourante = (caseCourante + 1) % F;
            avances++;
        }

        
        long long x = (caseCourante % C) * W;
        long long y = (caseCourante / C) * H;

        std::cout << caseCourante << " " << x << " " << y << " "
                  << W << " " << H << "\n";
    }

    std::cout << "AVANCES " << avances << "\n";
    std::cout << "PLAFONNES " << plafonnes << "\n";

    return 0;
}