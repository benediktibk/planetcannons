#include "VertexShader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

VertexShader::VertexShader() {
    const char* code =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";

    m_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_shader, 1, &code, NULL);
    glCompileShader(m_shader);
}

unsigned int VertexShader::getId() const {
    return m_shader;
}