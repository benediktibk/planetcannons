#include "GraphicEngine.h"
#include "ILogger.h"
#include "IGraphicObject.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <sstream>
#include <cstring>

GraphicEngine* GraphicEngine::m_graphicSystem = 0;

bool GraphicEngine::keyPressed(unsigned int keyType) {
    return glfwGetKey(m_window, keyType) == GLFW_PRESS;
}

IGraphicEngine& GraphicEngine::get(const ILogger &logger) {
    if (m_graphicSystem == 0) {
        m_graphicSystem = new GraphicEngine(logger);
    }

    return *m_graphicSystem;
}

void GraphicEngine::glfwErrorCallback(int error, const char* description) {
    if (m_graphicSystem == 0) {
        return;
    }

    std::stringstream logStream;
    logStream << "error " << error << " occurred: " << description;
    m_graphicSystem->m_logger.error(logStream.str());
}

GraphicEngine::GraphicEngine(const ILogger &logger) :
    m_logger(logger),
    m_initialzed(false) {
    glfwSetErrorCallback(GraphicEngine::glfwErrorCallback);
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

    m_window = glfwCreateWindow(800, 800, "planet cannons", NULL, NULL);
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
    
    logOpenGlParameter();

	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.1f, 0.0f);

    m_initialzed = true;
}

bool GraphicEngine::closeRequested() {
    if (!m_initialzed) {
        m_logger.error("initialization failed");
        return true;
    }

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        return true;
    }

    if (glfwWindowShouldClose(m_window) != 0) {
        return true;
    }

    return false;
}

void GraphicEngine::update() {
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

    GLenum openGlError = glGetError();

    if (openGlError != GL_NO_ERROR) {
        std::stringstream logStream;
        logStream << "error in OpenGL occured: " << openGlError;

        switch(openGlError) {
            case GL_INVALID_ENUM: logStream << ", invalid enum"; break;
            case GL_INVALID_VALUE: logStream << ", invalid value"; break;
            case GL_INVALID_OPERATION: logStream << ", invalid operation"; break;
            case GL_STACK_OVERFLOW: logStream << ", stack overflow"; break;
            case GL_STACK_UNDERFLOW: logStream << ", stack underflow"; break;
            case GL_OUT_OF_MEMORY: logStream << ", out of memory"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: logStream << ", invalid framebuffer operation"; break;
            case GL_CONTEXT_LOST: logStream << ", context lost"; break;
            case GL_TABLE_TOO_LARGE: logStream << ", table too large"; break;
            default: break;
        }
        m_logger.error(logStream.str());
    }
}

GraphicEngine::~GraphicEngine() {
    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        delete *object;
    }

    m_objects.clear();

	glfwTerminate();
}

void GraphicEngine::add(IGraphicObject *graphicObject) {
    m_objects.push_back(graphicObject);
}

void GraphicEngine::logOpenGlParameter() {
    std::stringstream logStream;
    logStream << "starting GLFW " << glfwGetVersionString();
    m_logger.info(logStream.str());

    GLenum params[] = {
        GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
        GL_MAX_CUBE_MAP_TEXTURE_SIZE,
        GL_MAX_DRAW_BUFFERS,
        GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
        GL_MAX_TEXTURE_IMAGE_UNITS,
        GL_MAX_TEXTURE_SIZE,
        GL_MAX_VARYING_FLOATS,
        GL_MAX_VERTEX_ATTRIBS,
        GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
        GL_MAX_VERTEX_UNIFORM_COMPONENTS
    };
    const char* names[] = {
        "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
        "GL_MAX_CUBE_MAP_TEXTURE_SIZE",
        "GL_MAX_DRAW_BUFFERS",
        "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
        "GL_MAX_TEXTURE_IMAGE_UNITS",
        "GL_MAX_TEXTURE_SIZE",
        "GL_MAX_VARYING_FLOATS",
        "GL_MAX_VERTEX_ATTRIBS",
        "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
        "GL_MAX_VERTEX_UNIFORM_COMPONENTS"
    };

    logStream.clear();
    logStream << "GL Context Params: " << std::endl;

    for (auto i = 0; i < 10; i++) {
        int value = 0;
        glGetIntegerv(params[i], &value);
        logStream << names[i] << ": " << value << std::endl;
    }

    int valuesArray[2];
    memset(valuesArray, 0, sizeof(valuesArray));
    glGetIntegerv(GL_MAX_VIEWPORT_DIMS, valuesArray);
    logStream << "GL_MAX_VIEWPORT_DIMS,x: " << valuesArray[0] << std::endl;
    logStream << "GL_MAX_VIEWPORT_DIMS,y: " << valuesArray[1] << std::endl;
    unsigned char stereoValue = 0;
    glGetBooleanv(GL_STEREO, &stereoValue);
    logStream << "GL_STEREO: " << (unsigned int)stereoValue;
    m_logger.info(logStream.str());
}