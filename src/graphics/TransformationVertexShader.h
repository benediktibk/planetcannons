#ifndef PLANETCANNONS_TRANSFORMATIONVERTEXSHADER_H
#define PLANETCANNONS_TRANSFORMATIONVERTEXSHADER_H

#include "VertexShader.h"
#include <glm/glm.hpp>

class TransformationVertexShader : public VertexShader {
    public:
        TransformationVertexShader(const ILogger &logger);

        void setTransformationLocalToWorld(const glm::mat4 &transformation);
        void setTransformationWorldToView(const glm::mat4 &transformation);
        void setTransformationViewToPerspective(const glm::mat4 &transformation);

    protected:
        virtual void updateUniformsInternal(unsigned int shaderProgramId);

    private:
        glm::mat4 m_transformationLocalToWorld;
        glm::mat4 m_transformationWorldToView;
        glm::mat4 m_transformationViewToPerspective;
};

#endif