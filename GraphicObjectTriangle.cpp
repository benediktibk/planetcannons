#include "GraphicObjectTriangle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GraphicObjectTriangle::GraphicObjectTriangle(const std::tuple<float, float, float> &pointOne, const std::tuple<float, float, float> &pointTwo, const std::tuple<float, float, float> &pointThree) {
    for (auto i = 0; i < 9; ++i) {
        m_coordinates[i] = 0;
    }

    setPoints(pointOne, pointTwo, pointThree);

    glGenVertexArrays(1, &m_vertexArray);
    glBindVertexArray(m_vertexArray);
    glEnableVertexAttribArray(0);
    glGenBuffers(1, &m_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_coordinates), m_coordinates, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    const char* vertexShaderCode =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";

    const char* fragmentShaderCode =
        "#version 400\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
        "}";

    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);

    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, fragmentShader);
    glAttachShader(m_shaderProgram, vertexShader);
    glLinkProgram(m_shaderProgram);
}

GraphicObjectTriangle::~GraphicObjectTriangle() {
    glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteVertexArrays(1, &m_vertexArray);
}

void GraphicObjectTriangle::setPoints(const std::tuple<float, float, float> &pointOne, const std::tuple<float, float, float> &pointTwo, const std::tuple<float, float, float> &pointThree) {
    m_coordinates[0] = std::get<0>(pointOne);
    m_coordinates[1] = std::get<1>(pointOne);
    m_coordinates[2] = std::get<2>(pointOne);
    m_coordinates[3] = std::get<0>(pointTwo);
    m_coordinates[4] = std::get<1>(pointTwo);
    m_coordinates[5] = std::get<2>(pointTwo);
    m_coordinates[6] = std::get<0>(pointThree);
    m_coordinates[7] = std::get<1>(pointThree);
    m_coordinates[8] = std::get<2>(pointThree);
}

void GraphicObjectTriangle::update() const {
    glBindVertexArray(m_vertexArray);
    glUseProgram(m_shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}