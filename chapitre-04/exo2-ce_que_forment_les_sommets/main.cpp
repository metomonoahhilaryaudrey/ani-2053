#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    long long totalPoints = 0;
    long long totalSegments = 0;
    long long totalTriangles = 0;
    long long totalRefuses = 0;

    for (int i = 0; i < n; i++) {
        std::string type;
        long long s;
        std::cin >> type >> s;

        long long nombre = 0;
        long long restants = 0;
        std::string unite;
        bool refuse = false;

        if (type == "POINTS") {
            nombre = s;
            restants = 0;
            unite = "POINTS";
        } else if (type == "LINES") {
            nombre = s / 2;
            restants = s % 2;
            unite = "SEGMENTS";
        } else if (type == "LINE_STRIP") {
            if (s >= 2) {
                nombre = s - 1;
                restants = 0;
            } else {
                nombre = 0;
                restants = s;
            }
            unite = "SEGMENTS";
        } else if (type == "TRIANGLES") {
            nombre = s / 3;
            restants = s % 3;
            unite = "TRIANGLES";
        } else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") {
            if (s >= 3) {
                nombre = s - 2;
                restants = 0;
            } else {
                nombre = 0;
                restants = s;
            }
            unite = "TRIANGLES";
        } else {
            refuse = true;
        }

        if (refuse) {
            std::cout << type << " " << s << " REFUSE\n";
            totalRefuses++;
        } else {
            std::cout << type << " " << s << " " << nombre << " "
                      << unite << " " << restants << "\n";
            if (unite == "POINTS") totalPoints += nombre;
            else if (unite == "SEGMENTS") totalSegments += nombre;
            else totalTriangles += nombre;
        }
    }

    std::cout << "POINTS " << totalPoints << "\n";
    std::cout << "SEGMENTS " << totalSegments << "\n";
    std::cout << "TRIANGLES " << totalTriangles << "\n";
    std::cout << "REFUSES " << totalRefuses << "\n";

    return 0;
}