#include "GraphicObjectTriangle.h"
#include "ShaderProgram.h"
#include "math/LinearAlgebraVector.h"
#include "math/GeometryTriangle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GraphicObjectTriangle::GraphicObjectTriangle(const GeometryTriangle &triangle, const ShaderProgram &shaderProgram, const LinearAlgebraVector &directionOfNormal) :
    m_shaderProgram(shaderProgram) {
    setPoints(triangle.getPointOne(), triangle.getPointTwo(), triangle.getPointThree(), directionOfNormal);
    initializeVertices();
}

GraphicObjectTriangle::~GraphicObjectTriangle() {
    glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteVertexArrays(1, &m_vertexArray);
}

void GraphicObjectTriangle::initializeVertices() {
    glGenVertexArrays(1, &m_vertexArray);
    glBindVertexArray(m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_coordinatesAndNormals), m_coordinatesAndNormals, GL_STREAM_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void GraphicObjectTriangle::setPoints(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree, const LinearAlgebraVector &directionOfNormal) {
    m_coordinatesAndNormals[0] = pointOne.getX();
    m_coordinatesAndNormals[1] = pointOne.getY();
    m_coordinatesAndNormals[2] = pointOne.getZ();
    m_coordinatesAndNormals[6] = pointTwo.getX();
    m_coordinatesAndNormals[7] = pointTwo.getY();
    m_coordinatesAndNormals[8] = pointTwo.getZ();
    m_coordinatesAndNormals[12] = pointThree.getX();
    m_coordinatesAndNormals[13] = pointThree.getY();
    m_coordinatesAndNormals[14] = pointThree.getZ();    
    
    auto sideOne = pointTwo - pointOne;
    auto sideTwo = pointThree - pointOne;
    sideOne = sideOne / sideOne.norm();
    sideTwo = sideTwo / sideTwo.norm();
    auto normal = LinearAlgebraVector::crossProduct(sideOne, sideTwo);
    auto direction = LinearAlgebraVector::dotProduct(normal, directionOfNormal);

    if (direction < 0) {
        normal = normal * (-1);
    }

    m_coordinatesAndNormals[3] = normal.getX();
    m_coordinatesAndNormals[4] = normal.getY();
    m_coordinatesAndNormals[5] = normal.getZ();
    m_coordinatesAndNormals[9] = normal.getX();
    m_coordinatesAndNormals[10] = normal.getY();
    m_coordinatesAndNormals[11] = normal.getZ();
    m_coordinatesAndNormals[15] = normal.getX();
    m_coordinatesAndNormals[16] = normal.getY();
    m_coordinatesAndNormals[17] = normal.getZ();
}

void GraphicObjectTriangle::update() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_coordinatesAndNormals), m_coordinatesAndNormals);

    glBindVertexArray(m_vertexArray);
    m_shaderProgram.use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}