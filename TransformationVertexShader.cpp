#include "TransformationVertexShader.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

TransformationVertexShader::TransformationVertexShader(const ILogger &logger) :
    VertexShader(logger, "transformation.vert"),
    m_transformation(1.0f) { 
}

void TransformationVertexShader::updateUniformsInternal(unsigned int shaderProgramId) {     
    unsigned int transformationMatrixLocation = glGetUniformLocation(shaderProgramId, "transformationMatrix");   
    glUniformMatrix4fv(transformationMatrixLocation, 1, GL_FALSE, glm::value_ptr(m_transformation));
}

void TransformationVertexShader::setTransformation(const glm::mat4 &transformation) {
    m_transformation = transformation;
    markUniformsUpdateNecessary();
}