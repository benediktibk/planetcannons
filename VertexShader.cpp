#include "VertexShader.h"
#include <GL/glew.h>

VertexShader::VertexShader(const ILogger &logger, const std::string &shaderFileName) :
    Shader(logger, shaderFileName, GL_VERTEX_SHADER) {
}