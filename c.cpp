#include <iostream>
#include <cmath>
#include <iterator>
#include <math.h>
#include <tuple>

std::tuple<float, float> getComponents(float vectorComponents[][2]) {
    float horizontal = 0;
    float vertical = 0;
    int placeholder = sizeof(vectorComponents);
    std::cout << placeholder << "\n";
    for (int i = 0; i < placeholder; i++) {
        horizontal = horizontal + cos(vectorComponents[i][0] * (M_PI/180));
        vertical = vertical + sin(vectorComponents[i][1] * (M_PI/180));
    } 


    return {horizontal, vertical};
}

int main() {
    int numVectors;
    
    std::cout << "Number of vectors: ";
    std::cin >> numVectors;
    float vectorAngles[numVectors][2];
    
    for (int i = 0; i < numVectors; i++) {
        std::cout << "magnitude: ";
        std::cin >> vectorAngles[i][0];
        std::cout << "angle: ";
        std::cin >> vectorAngles[i][1];
    }

    std::tuple<float, float> components = getComponents(vectorAngles);
    std::cout << std::get<0>(components) << "\n";
    std::cout << std::get<1>(components) << "\n";
}