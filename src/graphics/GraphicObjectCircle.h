#ifndef PLANETCANNONS_GRAPHICOBJECCIRCLE_H
#define PLANETCANNONS_GRAPHICOBJECCIRCLE_H

#include "IGraphicObject.h"
#include <tuple>

class ShaderProgram;

class GraphicObjectCircle : public IGraphicObject {
    public: 
        GraphicObjectCircle(const std::tuple<float, float, float> &centerPosition, double radius, unsigned int segmentCount, const ShaderProgram &shaderProgram);
        virtual ~GraphicObjectCircle();
        virtual void update() const;
        void setCenterPosition(const std::tuple<float, float, float> &centerPosition);

    private:
        double m_radius;
        std::tuple<float, float, float> m_centerPosition;
        unsigned int m_verticeCoordinateCount;
        float *m_verticesCoordinates;
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;
        const ShaderProgram &m_shaderProgram;
        unsigned int m_verticeCount;
};

#endif