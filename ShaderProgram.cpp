#include "ShaderProgram.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <sstream>

ShaderProgram::ShaderProgram(const ILogger &logger, VertexShader &vertexShader, FragmentShader &fragmentShader) :
    m_logger(logger) {
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, fragmentShader.getId());
    glAttachShader(m_shaderProgram, vertexShader.getId());
    glLinkProgram(m_shaderProgram);

    int params;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &params);

    if (GL_TRUE != params) {
        m_logger.error("could not link shader program");

        int maximumLength = 2048;
        int actualLength = 0;
        char programLog[2048];
        glGetProgramInfoLog(m_shaderProgram, maximumLength, &actualLength, programLog);
        std::stringstream logStream;
        logStream << "program info log for GL index " << m_shaderProgram << ": " << programLog;
        m_logger.info(logStream.str());
    }

    glUseProgram(m_shaderProgram);
    vertexShader.initializeUniforms();
    fragmentShader.initializeUniforms();
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(m_shaderProgram);
}

void ShaderProgram::use() const {
    glUseProgram(m_shaderProgram);
}