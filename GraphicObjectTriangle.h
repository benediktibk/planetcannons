#ifndef PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H
#define PLANETCANNONS_GRAPHICOBJECTTRIANGLE_H

#include "IGraphicObject.h"
#include <tuple>

class GraphicObjectTriangle : public IGraphicObject {
    public: 
        GraphicObjectTriangle(const std::tuple<float, float, float> &pointOne, const std::tuple<float, float, float> &pointTwo, const std::tuple<float, float, float> &pointThree);
        virtual ~GraphicObjectTriangle();
        virtual void update() const;
        void setPoints(const std::tuple<float, float, float> &pointOne, const std::tuple<float, float, float> &pointTwo, const std::tuple<float, float, float> &pointThree);

    private:
        float m_coordinates[9];
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;
};

#endif