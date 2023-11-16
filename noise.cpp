#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>



double vectorLength(const std::vector<double>& v) {
    double sum = 0;
    for (double x : v) {
        sum += x * x;
    }
    return std::sqrt(sum);
}


std::vector<double> randomDirectionVector(int dimensions) {
    std::vector<double> v(dimensions);
    for (int i = 0; i < dimensions; ++i) {
        v[i] = static_cast<double>(rand()) / RAND_MAX * 2 - 1; // random from -1 to 1
    }
    return v;
}

std::vector<double> createRadiusVector(const std::vector<double>& v1, const std::vector<double>& v2) {

    std::vector<double> minVector = vectorLength(v1) < vectorLength(v2) ? v1 : v2; // find min vector
    double minVectorLength = vectorLength(minVector);


    std::vector<double> direction = randomDirectionVector(minVector.size()); // create vector random direction

    // create radius vector
    std::vector<double> radiusVector(minVector.size());
    for (int i = 0; i < minVector.size(); ++i) {
        radiusVector[i] = direction[i] * (static_cast<double>(rand()) / RAND_MAX) * minVectorLength / 2;
    }

    return radiusVector;
}


int main() {
    // debug input
    std::vector<double> v1 = { 3.0, 2.0, 1.0};
    std::vector<double> v2 = { 0.0, 1.0, 3.0};

    std::vector<double> radiusVector = createRadiusVector(v1, v2);

    //debug output
    for (double x : radiusVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}