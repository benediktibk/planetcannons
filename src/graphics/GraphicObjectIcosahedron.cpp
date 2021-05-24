#include "GraphicObjectIcosahedron.h"
#include "ShaderProgram.h"
#include "GraphicObjectTriangle.h"
#include "TransformationVertexShader.h"
#include "FixedColorFragmentShader.h"
#include "IShaderFactory.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <vector>

GraphicObjectIcosahedron::GraphicObjectIcosahedron(IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius) :
    m_radius(radius),
    m_centerPosition(centerPosition) {
    m_triangles.reserve(20);

    m_vertexShader = shaderFactory.createTransformationVertexShader();
    m_fragmentShader = shaderFactory.createFixedColorFragmentShader(std::make_tuple<float, float, float, float>(0, 1, 0.5, 1.0));
    m_shaderProgram = shaderFactory.createShaderProgram(*m_vertexShader, *m_fragmentShader);

    for (size_t i = 0; i < 20; ++i) {
        m_triangles.push_back(new GraphicObjectTriangle(*m_shaderProgram));
    }

    std::vector<LinearAlgebraVector> points;
    const double goldenRatio = (1 + sqrt(5))/2;
    const double edgeSize = m_radius * 2 / goldenRatio;
    const double scalingFactor = edgeSize/2;
    points.reserve(12);
    points.push_back(scalingFactor*LinearAlgebraVector(0, 1, goldenRatio));
    points.push_back(scalingFactor*LinearAlgebraVector(0, -1, goldenRatio));
    points.push_back(scalingFactor*LinearAlgebraVector(0, 1, (-1)*goldenRatio));
    points.push_back(scalingFactor*LinearAlgebraVector(0, -1, (-1)*goldenRatio));
    points.push_back(scalingFactor*LinearAlgebraVector(1, goldenRatio, 0));
    points.push_back(scalingFactor*LinearAlgebraVector(-1, goldenRatio, 0));
    points.push_back(scalingFactor*LinearAlgebraVector(1, (-1)*goldenRatio, 0));
    points.push_back(scalingFactor*LinearAlgebraVector(-1, (-1)*goldenRatio, 0));
    points.push_back(scalingFactor*LinearAlgebraVector(goldenRatio, 0, 1));
    points.push_back(scalingFactor*LinearAlgebraVector(goldenRatio, 0, -1));
    points.push_back(scalingFactor*LinearAlgebraVector((-1)*goldenRatio, 0, 1));
    points.push_back(scalingFactor*LinearAlgebraVector((-1)*goldenRatio, 0, -1));

    m_triangles[0]->setPointOne(points[0]);
    m_triangles[0]->setPointTwo(points[1]);
    m_triangles[0]->setPointThree(points[2]);

    m_triangles[1]->setPointOne(points[1]);
    m_triangles[1]->setPointTwo(points[2]);
    m_triangles[1]->setPointThree(points[3]);

    // m_triangles[2]->setPointOne(points[2]);
    // m_triangles[2]->setPointTwo(points[0]);
    // m_triangles[2]->setPointThree(points[3]);
}

GraphicObjectIcosahedron::~GraphicObjectIcosahedron() {
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

void GraphicObjectIcosahedron::setCenterPosition(const LinearAlgebraVector &centerPosition) {
    m_centerPosition = centerPosition;
    glm::mat4 transformation = glm::mat4(1.0f);
    transformation = glm::translate(transformation, glm::vec3(
        centerPosition.getX(), 
        centerPosition.getY(), 
        centerPosition.getZ()));
    m_vertexShader->setTransformationLocalToWorld(transformation);
}

void GraphicObjectIcosahedron::update() const {
    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        (*triangle)->update();
    }
}