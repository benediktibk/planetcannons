#include "FragmentShader.h"
#include <GL/glew.h>

FragmentShader::FragmentShader(const ILogger &logger, const std::string &code) :
    Shader(logger, code, GL_FRAGMENT_SHADER) {
}