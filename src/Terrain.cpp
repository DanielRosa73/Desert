#include <cmath>
#include "Terrain.h"
#include "PerlinNoise.h"

Terrain::Terrain(int width, int depth, float maxHeight, PerlinNoise& pn) {
    createVertices(width, depth, maxHeight, pn);
}

void Terrain::render() {
    // We will implement this function later.
}

void Terrain::createVertices(int width, int depth, float maxHeight, PerlinNoise& pn) {
    for(int z = 0; z < depth; z++) {
        for(int x = 0; x < width; x++) {
            // Calculate the height using Perlin noise
            double height = pn.noise(x / 10.0, z / 10.0, 0.8) * maxHeight;

            // Position
            vertices.push_back((float)x);
            vertices.push_back((float)height);
            vertices.push_back((float)z);

            // Normal
            vertices.push_back(0.0f);
            vertices.push_back(1.0f);
            vertices.push_back(0.0f);

            // Texture coordinates
            vertices.push_back(x / (float)width);
            vertices.push_back(z / (float)depth);
        }
    }

    for(int z = 0; z < depth - 1; z++) {
        for(int x = 0; x < width - 1; x++) {
            int topLeft = (z * width) + x;
            int topRight = topLeft + 1;
            int bottomLeft = ((z + 1) * width) + x;
            int bottomRight = bottomLeft + 1;

            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
}

