#include "GraphicObjectTriangle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GraphicObjectTriangle::GraphicObjectTriangle(const std::tuple<float, float, float> &pointOne, const std::tuple<float, float, float> &pointTwo, const std::tuple<float, float, float> &pointThree) {
    for (size_t i = 0; i < 9; ++i) {
        m_coordinates[i] = 0;
    }

    setPoints(pointOne, pointTwo, pointThree);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &m_vertexBuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
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
    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glVertexAttribPointer(
    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
    3,                  // size
    GL_FLOAT,           // type
    GL_FALSE,           // normalized?
    0,                  // stride
    (void*)0            // array buffer offset
    );
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}