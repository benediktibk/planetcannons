#include "GraphicObjectCircle.h"
#include "ShaderProgram.h"
#include "math/LinearAlgebraVector.h"
#include "math/GeometryCircle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cmath>
#include <vector>

GraphicObjectCircle::GraphicObjectCircle(const LinearAlgebraVector &centerPosition, double radius, unsigned int segmentCount, const ShaderProgram &shaderProgram) :
    m_radius(radius),
    m_centerPosition(centerPosition),
    m_verticeCoordinateCount(segmentCount*3),
    m_verticesCoordinates(0),
    m_vertexBuffer(0),
    m_vertexArray(0),
    m_shaderProgram(shaderProgram),
    m_verticeCount(segmentCount) {

    m_verticesCoordinates = new float[m_verticeCoordinateCount];
    setCenterPosition(centerPosition);

    glGenVertexArrays(1, &m_vertexArray);
    glBindVertexArray(m_vertexArray);
    glEnableVertexAttribArray(0);
    glGenBuffers(1, &m_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_verticeCoordinateCount, m_verticesCoordinates, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

GraphicObjectCircle::~GraphicObjectCircle() {
    glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteVertexArrays(1, &m_vertexArray);
    delete[] m_verticesCoordinates;
    m_verticesCoordinates = 0;
    m_verticeCoordinateCount = 0;
}

void GraphicObjectCircle::setCenterPosition(const LinearAlgebraVector &centerPosition) {
    std::vector< LinearAlgebraVector > vertices;
    vertices.reserve(m_verticeCount);

    m_centerPosition = centerPosition;
    GeometryCircle circle(m_centerPosition, m_radius);

    for (unsigned int i = 0; i < m_verticeCount; ++i) {
        double angle = 2 * M_PI * i / (double)m_verticeCount;
        vertices.push_back(circle.calculatePoint(angle));
    }

    unsigned int m_verticesCoordinatesPosition = 0;

    for (auto vertice = vertices.begin(); vertice != vertices.end(); ++vertice) {
        m_verticesCoordinates[m_verticesCoordinatesPosition + 0] = vertice->getX();
        m_verticesCoordinates[m_verticesCoordinatesPosition + 1] = vertice->getY();
        m_verticesCoordinates[m_verticesCoordinatesPosition + 2] = vertice->getZ();
        m_verticesCoordinatesPosition += 3;
    }
}

void GraphicObjectCircle::update() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * m_verticeCoordinateCount, m_verticesCoordinates);
    glBindVertexArray(m_vertexArray);
    m_shaderProgram.use();
    glDrawArrays(GL_LINE_LOOP, 0, m_verticeCount);
    glBindVertexArray(0);
}