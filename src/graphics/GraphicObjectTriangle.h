#ifndef PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H
#define PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H

#include "IGraphicObject.h"

class ShaderProgram;
class LinearAlgebraVector;

class GraphicObjectTriangle : public IGraphicObject {
    public: 
        GraphicObjectTriangle(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree, const ShaderProgram &shaderProgram);
        GraphicObjectTriangle(const ShaderProgram &shaderProgram);
        virtual ~GraphicObjectTriangle();
        virtual void update() const;
        void setPoints(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree);
        void setPointOne(const LinearAlgebraVector &point);
        void setPointTwo(const LinearAlgebraVector &point);
        void setPointThree(const LinearAlgebraVector &point);

    private:
        void initialize();

    private:
        float m_coordinates[9];
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;
        const ShaderProgram &m_shaderProgram;
};

#endif