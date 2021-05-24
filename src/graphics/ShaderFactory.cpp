#include "ShaderFactory.h"
#include "TransformationVertexShader.h"
#include "FixedColorFragmentShader.h"
#include "ShaderProgram.h"

ShaderFactory::ShaderFactory(const ILogger &logger) :
    m_logger(logger) {
}

TransformationVertexShader* ShaderFactory::createTransformationVertexShader() {
    auto shader = new TransformationVertexShader(m_logger, *this);
    m_transformationVertexShader.push_back(shader);
    return shader;
}

FixedColorFragmentShader* ShaderFactory::createFixedColorFragmentShader(const std::tuple<double, double, double, double> &color) {
    return new FixedColorFragmentShader(m_logger, color, *this);
}

ShaderProgram* ShaderFactory::createShaderProgram(VertexShader &vertexShader, FragmentShader &fragmentShader) {
    return new ShaderProgram(m_logger, vertexShader, fragmentShader);
}

void ShaderFactory::registerVertexShader(VertexShader &shader) {
    m_vertexShader.push_back(&shader);
}

void ShaderFactory::registerFragmentShader(FragmentShader &shader) {
    m_fragmentShader.push_back(&shader);
}

void ShaderFactory::unregisterVertexShader(VertexShader &shader) {
    std::remove(m_vertexShader.begin(), m_vertexShader.end(), &shader);
    std::remove(m_transformationVertexShader.begin(), m_transformationVertexShader.end(), &shader);
}

void ShaderFactory::unregisterFragmentShader(FragmentShader &shader) {
    std::remove(m_fragmentShader.begin(), m_fragmentShader.end(), &shader);
}

void ShaderFactory::updateGlobalTransformations(const glm::mat4 &transformationWorldToView, const glm::mat4 &transformationViewToPerspective) {
    for (auto shader = m_transformationVertexShader.begin(); shader != m_transformationVertexShader.end(); ++shader) {
        (*shader)->setTransformationWorldToView(transformationWorldToView);
        (*shader)->setTransformationViewToPerspective(transformationViewToPerspective);
    }
}