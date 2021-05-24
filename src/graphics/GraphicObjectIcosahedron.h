#ifndef PLANETCANNONS_GRAPHICOBJECTICOSAHEDRON_H
#define PLANETCANNONS_GRAPHICOBJECTICOSAHEDRON_H

#include "IGraphicObject.h"
#include "math/LinearAlgebraVector.h"
#include <vector>

class ShaderProgram;
class TransformationVertexShader;
class FixedColorFragmentShader;
class GraphicObjectTriangle;
class IShaderFactory;
class LinearAlgebraVector;

class GraphicObjectIcosahedron : public IGraphicObject {
    public: 
        GraphicObjectIcosahedron(IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius);
        virtual ~GraphicObjectIcosahedron();
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