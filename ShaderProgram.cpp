#include "ShaderProgram.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

ShaderProgram::ShaderProgram(const VertexShader &vertexShader, const FragmentShader &fragmentShader) {
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, fragmentShader.getId());
    glAttachShader(m_shaderProgram, vertexShader.getId());
    glLinkProgram(m_shaderProgram);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(m_shaderProgram);
}

void ShaderProgram::use() const {
    glUseProgram(m_shaderProgram);
}