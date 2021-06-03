#ifndef PLANETCANNONS_GRAPHICOBJECTCIRCLEFILLED_H
#define PLANETCANNONS_GRAPHICOBJECTCIRCLEFILLED_H

#include "IGraphicObject.h"
#include "math/LinearAlgebraVector.h"
#include <vector>

class ShaderProgram;
class TransformationVertexShader;
class FixedColorFragmentShader;
class GraphicObjectTriangle;
class IShaderFactory;
class LinearAlgebraVector;

class GraphicObjectSphere : public IGraphicObject {
    public: 
        GraphicObjectSphere(IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius, unsigned int approximationDepth);
        virtual ~GraphicObjectSphere();
        virtual void update() const;
        void setCenterPosition(const LinearAlgebraVector &centerPosition);

    private:
        double m_radius;
        LinearAlgebraVector m_centerPosition;
        std::vector<GraphicObjectTriangle*> m_triangles;
        TransformationVertexShader *m_vertexShader;
        FixedColorFragmentShader *m_fragmentShader;
        ShaderProgram *m_shaderProgram;
};

#endif