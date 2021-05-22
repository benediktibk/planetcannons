#ifndef PLANETCANNONS_GRAPHICOBJECCIRCLEFILLED_H
#define PLANETCANNONS_GRAPHICOBJECCIRCLEFILLED_H

#include "IGraphicObject.h"
#include <tuple>
#include <vector>

class ShaderProgram;
class TransformationVertexShader;
class FixedColorFragmentShader;
class GraphicObjectTriangle;
class ILogger;

class GraphicObjectCircleFilled : public IGraphicObject {
    public: 
        GraphicObjectCircleFilled(const ILogger &logger, const std::tuple<float, float, float> &centerPosition, double radius, unsigned int segmentCount);
        virtual ~GraphicObjectCircleFilled();
        virtual void update() const;
        void setCenterPosition(const std::tuple<float, float, float> &centerPosition);

    private:
        double m_radius;
        std::tuple<float, float, float> m_centerPosition;
        unsigned int m_verticeCoordinateCount;
        unsigned int m_verticeCount;
        std::vector<GraphicObjectTriangle*> m_triangles;
        TransformationVertexShader *m_vertexShader;
        FixedColorFragmentShader *m_fragmentShader;
        ShaderProgram *m_shaderProgram;
};

#endif