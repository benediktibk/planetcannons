#include "FragmentShader.h"
#include "IShaderRegistry.h"
#include <GL/glew.h>

FragmentShader::FragmentShader(const ILogger &logger, const std::string &shaderFileName, IShaderRegistry &registry) :
    Shader(logger, shaderFileName, GL_FRAGMENT_SHADER, registry) {
    m_registry.registerFragmentShader(*this);
}

FragmentShader::~FragmentShader() {
    m_registry.unregisterFragmentShader(*this);
}