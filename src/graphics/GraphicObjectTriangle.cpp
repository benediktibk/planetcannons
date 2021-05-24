#include "GraphicObjectTriangle.h"
#include "ShaderProgram.h"
#include "math/LinearAlgebraVector.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GraphicObjectTriangle::GraphicObjectTriangle(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree, const ShaderProgram &shaderProgram) :
    m_shaderProgram(shaderProgram) {
    setPoints(pointOne, pointTwo, pointThree);
    initialize();
}

GraphicObjectTriangle::GraphicObjectTriangle(const ShaderProgram &shaderProgram) :
    m_shaderProgram(shaderProgram) {
    for (size_t i = 0; i < 9; ++i) {
        m_coordinates[i] = 0;
    }

    initialize();
}

GraphicObjectTriangle::~GraphicObjectTriangle() {
    glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteVertexArrays(1, &m_vertexArray);
}

void GraphicObjectTriangle::initialize() {
    glGenVertexArrays(1, &m_vertexArray);
    glBindVertexArray(m_vertexArray);
    glEnableVertexAttribArray(0);
    glGenBuffers(1, &m_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_coordinates), m_coordinates, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void GraphicObjectTriangle::setPoints(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree) {
    m_coordinates[0] = pointOne.getX();
    m_coordinates[1] = pointOne.getY();
    m_coordinates[2] = pointOne.getZ();
    m_coordinates[3] = pointTwo.getX();
    m_coordinates[4] = pointTwo.getY();
    m_coordinates[5] = pointTwo.getZ();
    m_coordinates[6] = pointThree.getX();
    m_coordinates[7] = pointThree.getY();
    m_coordinates[8] = pointThree.getZ();
}

void GraphicObjectTriangle::setPointOne(const LinearAlgebraVector &point) {
    m_coordinates[0] = point.getX();
    m_coordinates[1] = point.getY();
    m_coordinates[2] = point.getZ();
}

void GraphicObjectTriangle::setPointTwo(const LinearAlgebraVector &point) {
    m_coordinates[3] = point.getX();
    m_coordinates[4] = point.getY();
    m_coordinates[5] = point.getZ();
}

void GraphicObjectTriangle::setPointThree(const LinearAlgebraVector &point) {
    m_coordinates[6] = point.getX();
    m_coordinates[7] = point.getY();
    m_coordinates[8] = point.getZ();
}

void GraphicObjectTriangle::update() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_coordinates), m_coordinates);
    glBindVertexArray(m_vertexArray);
    m_shaderProgram.use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}