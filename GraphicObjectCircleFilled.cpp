#include "GraphicObjectCircleFilled.h"
#include "ShaderProgram.h"
#include "GraphicObjectTriangle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cmath>
#include <vector>

GraphicObjectCircleFilled::GraphicObjectCircleFilled(const std::tuple<float, float, float> &centerPosition, double radius, unsigned int segmentCount, const ShaderProgram &shaderProgram) :
    m_radius(radius),
    m_centerPosition(centerPosition),
    m_verticeCount(segmentCount) {
    m_triangles.reserve(segmentCount);

    for (size_t i = 0; i < segmentCount; ++i) {
        m_triangles.push_back(new GraphicObjectTriangle(shaderProgram));
    }

    setCenterPosition(centerPosition);
}

GraphicObjectCircleFilled::~GraphicObjectCircleFilled() {
    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        delete *triangle;
    }

    m_triangles.clear();
}

void GraphicObjectCircleFilled::setCenterPosition(const std::tuple<float, float, float> &centerPosition) {
    m_centerPosition = centerPosition;

    for (unsigned int i = 0; i < m_verticeCount; ++i) {
        double angle = 2 * M_PI * i / (double)m_verticeCount;
        float x = std::get<0>(m_centerPosition) + m_radius * cos(angle);
        float y = std::get<1>(m_centerPosition) + m_radius * sin(angle);
        float z = std::get<2>(m_centerPosition);
        auto vertex = std::make_tuple(x, y, z);
        m_triangles[i]->setPointOne(vertex);

        unsigned int previousIndex;

        if (i == 0) {
            previousIndex = m_verticeCount - 1;
        } 
        else {
            previousIndex = i - 1;
        }

        m_triangles[previousIndex]->setPointTwo(vertex);
        m_triangles[i]->setPointThree(m_centerPosition);
    }
}

void GraphicObjectCircleFilled::update() const {
    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        (*triangle)->update();
    }
}