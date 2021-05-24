#ifndef PLANETCANNONS_GRAPHICENGINE_H
#define PLANETCANNONS_GRAPHICENGINE_H

#include "IGraphicEngine.h"
#include <vector>

class ILogger;
class GLFWwindow;

class GraphicEngine : public IGraphicEngine {
    public:
        static IGraphicEngine& get(const ILogger &logger);

    public:
        virtual ~GraphicEngine();
        virtual void update();
        virtual bool closeRequested();
        virtual void add(IGraphicObject &graphicObject);
        virtual void remove(IGraphicObject &graphicObject);
        virtual bool keyPressed(unsigned int keyType);
        virtual IShaderFactory& getShaderFactory();
        virtual void setCamera(const LinearAlgebraVector &position, const LinearAlgebraVector &target, double fieldOfView, double aspectRatio, double nearPlane, double farPlane);

    private:
        static void glfwErrorCallback(int error, const char* description);

    private:
        GraphicEngine(const ILogger &logger);
        void logOpenGlParameter();

    private:
        static GraphicEngine *m_graphicSystem;

    private:
        const ILogger &m_logger;
        IShaderFactory *m_shaderFactory;
        GLFWwindow *m_window;
        bool m_initialzed;
        std::vector<IGraphicObject*> m_objects;
};

#endif