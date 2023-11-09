#include <iostream>
#include <cmath>
#include <iterator>
#include <math.h>
#include <tuple>
#include <stdlib.h>

std::tuple<float, float> getComponents(float vectorComponents[][2], int length) {
    float horizontal = 0;
    float vertical = 0;
    
    for (int i = 0; i < length; i++) {
        horizontal = horizontal + (vectorComponents[i][0] * cos(vectorComponents[i][1] * (M_PI/180)));
        vertical = vertical + (vectorComponents[i][0] * sin(vectorComponents[i][1] * (M_PI/180)));
    } 


    return {roundf(horizontal * 10000) / 10000, roundf(vertical * 10000) / 10000};
}

float getResultantMagnitude(std::tuple<float, float> components) {
    float a = std::get<0>(components);
    float b = std::get<1>(components);
    float resultant = sqrt(pow(a, 2) + pow(b, 2));
    return roundf(resultant * 10000) / 10000;
}

float getAngle(std::tuple<float, float> components) {
    float horizontal = std::get<0>(components);
    float vertical = std::get<1>(components);
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

    std::tuple<float, float> components = getComponents(vectorAngles, numVectors);
    
    float resultantAngle = getAngle(components);
    float resultantMagnitude = getResultantMagnitude(components);
    std::cout << resultantMagnitude << "\n";


}
