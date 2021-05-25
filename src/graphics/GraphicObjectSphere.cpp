#include "GraphicObjectSphere.h"
#include "ShaderProgram.h"
#include "GraphicObjectTriangle.h"
#include "TransformationVertexShader.h"
#include "FixedColorFragmentShader.h"
#include "math/GeometrySphere.h"
#include "IShaderFactory.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <vector>

GraphicObjectSphere::GraphicObjectSphere(IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius, unsigned int approximationDepth) :
    m_radius(radius),
    m_centerPosition(centerPosition) {
    m_vertexShader = shaderFactory.createTransformationVertexShader();
    m_fragmentShader = shaderFactory.createFixedColorFragmentShader(std::make_tuple<float, float, float, float>(0, 1, 0.5, 1.0));
    m_shaderProgram = shaderFactory.createShaderProgram(*m_vertexShader, *m_fragmentShader);

    GeometrySphere sphere(LinearAlgebraVector(0, 0, 0), m_radius);
    auto triangles = sphere.approximateWithTriangles(approximationDepth);

    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle) {
        m_triangles.push_back(new GraphicObjectTriangle(*triangle, *m_shaderProgram));
    }

    setCenterPosition(centerPosition);
}

GraphicObjectSphere::~GraphicObjectSphere() {
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

void GraphicObjectSphere::setCenterPosition(const LinearAlgebraVector &centerPosition) {
    m_centerPosition = centerPosition;
    glm::mat4 transformation = glm::mat4(1.0f);
    transformation = glm::translate(transformation, glm::vec3(
        centerPosition.getX(), 
        centerPosition.getY(), 
        centerPosition.getZ()));
    m_vertexShader->setTransformationLocalToWorld(transformation);
}

void GraphicObjectSphere::update() const {
    for (auto triangle = m_triangles.begin(); triangle != m_triangles.end(); ++triangle) {
        (*triangle)->update();
    }
}