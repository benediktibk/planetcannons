#ifndef PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H
#define PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H

#include "IGraphicObject.h"

class ShaderProgram;
class LinearAlgebraVector;
class GeometryTriangle;

class GraphicObjectTriangle : public IGraphicObject {
    public: 
        GraphicObjectTriangle(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree, const ShaderProgram &shaderProgram);
        GraphicObjectTriangle(const GeometryTriangle &triangle, const ShaderProgram &shaderProgram);
        GraphicObjectTriangle(const ShaderProgram &shaderProgram);
        
        virtual ~GraphicObjectTriangle();
        virtual void update() const;

    private:
        void setPoints(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree);
        void initialize();
        void updateNormal();

    private:
        float m_coordinatesAndNormals[18];
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;
        const ShaderProgram &m_shaderProgram;
};

#endif