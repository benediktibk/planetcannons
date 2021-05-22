#ifndef PLANETCANNONS_GRAPHICSYSTEM_H
#define PLANETCANNONS_GRAPHICSYSTEM_H

#include "IGraphicSystem.h"
#include <vector>

class ILogger;
class GLFWwindow;

class GraphicSystem : public IGraphicSystem {
    public:
        static GraphicSystem& get(const ILogger &logger);

    public:
        virtual ~GraphicSystem();
        virtual void update();
        virtual bool closeRequested();
        virtual void add(IGraphicObject *graphicObject);

    private:
        static void glfwErrorCallback(int error, const char* description);

    private:
        GraphicSystem(const ILogger &logger);
        void logOpenGlParameter();

    private:
        static GraphicSystem *m_graphicSystem;

    private:
        const ILogger &m_logger;
        GLFWwindow *m_window;
        bool m_initialzed;
        std::vector<IGraphicObject*> m_objects;
};

#endif