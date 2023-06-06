#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <GLFW/glfw3.h>
#include "PerlinNoise.h"

class Terrain {
public:
    Terrain(int width, int depth, float maxHeight, PerlinNoise& pn);
    void render();

private:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void createVertices(int width, int depth, float maxHeight, PerlinNoise& pn);
};

#endif
