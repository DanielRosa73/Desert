#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <GLFW/glfw3.h>

class ShaderProgram {
public:
    ShaderProgram(const char* vertexPath, const char* fragmentPath);
    void use();
    unsigned int ID;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
