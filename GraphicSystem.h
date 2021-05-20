#ifndef PLANETCANNONS_GRAPHICSYSTEM_H
#define PLANETCANNONS_GRAPHICSYSTEM_H

#include "IGraphicSystem.h"

class ILogger;
class GLFWwindow;

class GraphicSystem : public IGraphicSystem {
    public:
        GraphicSystem(const ILogger &logger);
        virtual ~GraphicSystem();
        virtual void update();
        virtual bool closeRequested();

    private:

    private:
        const ILogger &m_logger;
        GLFWwindow *m_window;
        unsigned int m_vertexbuffer;
        bool m_initialzed;
};

#endif