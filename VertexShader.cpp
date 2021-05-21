#include "VertexShader.h"
#include <GL/glew.h>

VertexShader::VertexShader(const ILogger &logger, const std::string &code) :
    Shader(logger, code, GL_VERTEX_SHADER) {
}