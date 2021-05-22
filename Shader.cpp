#include "Shader.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <sstream>
#include <fstream>

Shader::Shader(const ILogger &logger, const std::string &shaderFileName, unsigned int shaderType) :
    m_logger(logger),
    m_initialized(false),
    m_uniformsUpdateNecessary(true) {
    std::stringstream logStream;
    std::ifstream shaderFile(shaderFileName);
    std::stringstream shaderFileContentStream;
    std::string line;

    if (!shaderFile) {
        logStream << "unable to open shader file " << shaderFileName;
        logger.error(logStream.str());
        return;
    }

    shaderFileContentStream << shaderFile.rdbuf();
    shaderFile.close();
    auto shaderFileContent = shaderFileContentStream.str();

    m_shader = glCreateShader(shaderType);
    const char * const codePointer = shaderFileContent.c_str();
    GLint shaderLength = shaderFileContent.size();
    glShaderSource(m_shader, 1, &codePointer, &shaderLength);
    glCompileShader(m_shader);
    
    int params;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &params);

    if (GL_TRUE != params) {
        m_logger.error("shader compilation failed");
        
        int maximumLength = 2048;
        int actualLength = 0;
        char shaderLog[2048];
        glGetShaderInfoLog(m_shader, maximumLength, &actualLength, shaderLog);
        logStream << "shader info log for GL index " << m_shader << ": " << shaderLog;
        m_logger.info(logStream.str());
        return;
    }

    m_initialized = true;
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

bool Shader::isInitialized() const {
    return m_initialized;
}

void Shader::updateUniforms(unsigned int shaderProgramId) {
    if (m_uniformsUpdateNecessary) {
        updateUniformsInternal(shaderProgramId);
    }

    m_uniformsUpdateNecessary = false;
}

void Shader::updateUniformsInternal(unsigned int) {
}

void Shader::markUniformsUpdateNecessary() {
    m_uniformsUpdateNecessary = true;
}