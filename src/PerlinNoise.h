#pragma once
#include <vector>

class PerlinNoise {
public:
    PerlinNoise();
    PerlinNoise(unsigned int seed);
    double noise(double x, double y, double z);
private:
    std::vector<int> p;
};
