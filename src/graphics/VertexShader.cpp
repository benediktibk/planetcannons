#include "VertexShader.h"
#include "IShaderRegistry.h"
#include <GL/glew.h>

VertexShader::VertexShader(const ILogger &logger, const std::string &shaderFileName, IShaderRegistry &registry) :
    Shader(logger, shaderFileName, GL_VERTEX_SHADER, registry) {
    m_registry.registerVertexShader(*this);
}

VertexShader::~VertexShader() {
    m_registry.unregisterVertexShader(*this);
}