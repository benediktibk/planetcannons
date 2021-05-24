#include "TransformationVertexShader.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

TransformationVertexShader::TransformationVertexShader(const ILogger &logger) :
    VertexShader(logger, "transformation.vert"),
    m_transformationLocalToWorld(1.0f),
    m_transformationWorldToView(1.0f),
    m_transformationViewToPerspective(1.0f) { 
}

void TransformationVertexShader::updateUniformsInternal(unsigned int shaderProgramId) {     
    unsigned int transformationLocalToWorldLocation = glGetUniformLocation(shaderProgramId, "transformationLocalToWorld");   
    unsigned int transformationWorldToViewLocation = glGetUniformLocation(shaderProgramId, "transformationWorldToView");   
    unsigned int transformationViewToPerspectiveLocation = glGetUniformLocation(shaderProgramId, "transformationViewToPerspective");   
    glUniformMatrix4fv(transformationLocalToWorldLocation, 1, GL_FALSE, glm::value_ptr(m_transformationLocalToWorld));
    glUniformMatrix4fv(transformationWorldToViewLocation, 1, GL_FALSE, glm::value_ptr(m_transformationWorldToView));
    glUniformMatrix4fv(transformationViewToPerspectiveLocation, 1, GL_FALSE, glm::value_ptr(m_transformationViewToPerspective));
}

void TransformationVertexShader::setTransformationLocalToWorld(const glm::mat4 &transformation) {
    m_transformationLocalToWorld = transformation;
    markUniformsUpdateNecessary();
}

void TransformationVertexShader::setTransformationWorldToView(const glm::mat4 &transformation) {
    m_transformationWorldToView = transformation;
    markUniformsUpdateNecessary();
}

void TransformationVertexShader::setTransformationViewToPerspective(const glm::mat4 &transformation) {
    m_transformationViewToPerspective = transformation;
    markUniformsUpdateNecessary();
}