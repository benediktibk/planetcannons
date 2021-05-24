#ifndef PLANETCANNONS_GRAPHICOBJECTCIRCLE_H
#define PLANETCANNONS_GRAPHICOBJECTCIRCLE_H

#include "IGraphicObject.h"
#include "math/LinearAlgebraVector.h"

class ShaderProgram;

class GraphicObjectCircle : public IGraphicObject {
    public: 
        GraphicObjectCircle(const LinearAlgebraVector &centerPosition, double radius, unsigned int segmentCount, const ShaderProgram &shaderProgram);
        virtual ~GraphicObjectCircle();
        virtual void update() const;
        void setCenterPosition(const LinearAlgebraVector &centerPosition);

    private:
        double m_radius;
        LinearAlgebraVector m_centerPosition;
        unsigned int m_verticeCoordinateCount;
        float *m_verticesCoordinates;
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;
        const ShaderProgram &m_shaderProgram;
        unsigned int m_verticeCount;
};

#endif