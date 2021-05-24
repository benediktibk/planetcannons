#ifndef PLANETCANNONS_GRAPHICOBJECCIRCLEFILLED_H
#define PLANETCANNONS_GRAPHICOBJECCIRCLEFILLED_H

#include "IGraphicObject.h"
#include "math/LinearAlgebraVector.h"
#include <vector>

class ShaderProgram;
class TransformationVertexShader;
class FixedColorFragmentShader;
class GraphicObjectTriangle;
class IShaderFactory;
class LinearAlgebraVector;

class GraphicObjectCircleFilled : public IGraphicObject {
    public: 
        GraphicObjectCircleFilled(IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius, unsigned int segmentCount);
        virtual ~GraphicObjectCircleFilled();
        virtual void update() const;
        void setCenterPosition(const LinearAlgebraVector &centerPosition);

    private:
        double m_radius;
        LinearAlgebraVector m_centerPosition;
        unsigned int m_verticeCoordinateCount;
        unsigned int m_verticeCount;
        std::vector<GraphicObjectTriangle*> m_triangles;
        TransformationVertexShader *m_vertexShader;
        FixedColorFragmentShader *m_fragmentShader;
        ShaderProgram *m_shaderProgram;
};

#endif