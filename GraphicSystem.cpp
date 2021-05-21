#include "GraphicSystem.h"
#include "ILogger.h"
#include "IGraphicObject.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <sstream>

static const ILogger *graphicSystemLogger;

void glfwErrorCallback(int error, const char* description) {
    if (graphicSystemLogger == 0) {
        return;
    }

    std::stringstream logStream;
    logStream << "error " << error << " occurred: " << description;
    graphicSystemLogger->error(logStream.str());
}

GraphicSystem::GraphicSystem(const ILogger &logger) :
    m_logger(logger),
    m_initialzed(false) {
    graphicSystemLogger = &logger;
    std::stringstream logStream;
    logStream << "starting GLFW " << glfwGetVersionString();
    m_logger.info(logStream.str());
    glfwSetErrorCallback(glfwErrorCallback);
    bool success = glfwInit();

    if(!success) {
        m_logger.error("failed to initialize GLFW");
        return;
	}

    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(1024, 768, "planet cannons", NULL, NULL);
	if(m_window == NULL) {
        m_logger.error("failed to open GLFW window");
        return;
	}

	glfwMakeContextCurrent(m_window);
    
    GLenum glewResult = glewInit();
    if (glewResult != GLEW_OK) {
		m_logger.error("failed to initialize GLEW");
        return;
	}

	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.1f, 0.0f);

    m_initialzed = true;
}

bool GraphicSystem::closeRequested() {
    if (!m_initialzed) {
        m_logger.error("initialization failed");
        return true;
    }

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
        return true;
    }

    if (glfwWindowShouldClose(m_window) != 0) {
        return true;
    }

    return false;
}

void GraphicSystem::update() {
    if (!m_initialzed) {
        m_logger.error("initialization failed");
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        (*object)->update();
    }

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

GraphicSystem::~GraphicSystem() {
    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        delete *object;
    }

    m_objects.clear();

	glfwTerminate();
}

void GraphicSystem::add(IGraphicObject *graphicObject) {
    m_objects.push_back(graphicObject);
}