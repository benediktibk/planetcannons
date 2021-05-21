#include "Shader.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

Shader::Shader(const ILogger &logger, const std::string &code, unsigned int shaderType) :
    m_logger(logger) {
    m_shader = glCreateShader(shaderType);
    const char * const codePointer = code.data();
    glShaderSource(m_shader, 1, &codePointer, NULL);
    glCompileShader(m_shader);
    
    int params;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &params);

    if (GL_TRUE != params) {
        m_logger.error("shader compilation failed");
    }
}

Shader::Shader(const Shader &rhs) :
    m_logger(rhs.m_logger) {
}

Shader::~Shader() {
    glDeleteShader(m_shader);
}

unsigned int Shader::getId() const {
    return m_shader;
}