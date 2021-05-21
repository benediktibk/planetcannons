#include "FragmentShader.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

FragmentShader::FragmentShader(const ILogger &logger) :
    m_logger(logger) {
    const char* code =
        "#version 400\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
        "}";

    m_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_shader, 1, &code, NULL);
    glCompileShader(m_shader);

    int params;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &params);

    if (GL_TRUE != params) {
        m_logger.error("shader compilation failed");
    }
}

unsigned int FragmentShader::getId() const {
    return m_shader;
}