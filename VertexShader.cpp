#include "VertexShader.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

VertexShader::VertexShader(const ILogger &logger) :
    m_logger(logger) {
    const char* code =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";

    m_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_shader, 1, &code, NULL);
    glCompileShader(m_shader);
    
    int params;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &params);

    if (GL_TRUE != params) {
        m_logger.error("shader compilation failed");
    }
}

unsigned int VertexShader::getId() const {
    return m_shader;
}