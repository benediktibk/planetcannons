#include "FragmentShader.h"
#include <GL/glew.h>

FragmentShader::FragmentShader(const ILogger &logger, const std::string &shaderFileName) :
    Shader(logger, shaderFileName, GL_FRAGMENT_SHADER) {
}