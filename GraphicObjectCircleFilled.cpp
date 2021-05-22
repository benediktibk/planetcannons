#include "GraphicObjectCircleFilled.h"
#include "ShaderProgram.h"
#include "GraphicObjectTriangle.h"
#include "TransformationVertexShader.h"
#include "FixedColorFragmentShader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cmath>
#include <vector>

GraphicObjectCircleFilled::GraphicObjectCircleFilled(const ILogger &logger, const std::tuple<float, float, float> &centerPosition, double radius, unsigned int segmentCount) :
    m_radius(radius),
    m_centerPosition(centerPosition),
    m_verticeCount(segmentCount) {
    m_triangles.reserve(segmentCount);

    m_vertexShader = new TransformationVertexShader(logger);
    m_fragmentShader = new FixedColorFragmentShader(logger);
    m_shaderProgram = new ShaderProgram(logger, *m_vertexShader, *m_fragmentShader);

    for (size_t i = 0; i < segmentCount; ++i) {
        m_triangles.push_back(new GraphicObjectTriangle(*m_shaderProgram));
    }

    for (unsigned int i = 0; i < m_verticeCount; ++i) {
        double angle = 2 * M_PI * i / (double)m_verticeCount;
        float x = m_radius * cos(angle);
        float y = m_radius * sin(angle);
        float z = 0;
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

    setCenterPosition(centerPosition);
}

GraphicObjectCircleFilled::~GraphicObjectCircleFilled() {
    delete m_shaderProgram;
    m_shaderProgram = 0;
    delete m_vertexShader;
    m_vertexShader = 0;
    delete m_fragmentShader;
    m_fragmentShader = 0;

    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        delete *triangle;
    }

    m_triangles.clear();
}

void GraphicObjectCircleFilled::setCenterPosition(const std::tuple<float, float, float> &centerPosition) {
    m_centerPosition = centerPosition;
}

void GraphicObjectCircleFilled::update() const {
    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        (*triangle)->update();
    }
}