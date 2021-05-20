#include "GraphicSystem.h"
#include "ILogger.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GraphicSystem::GraphicSystem(const ILogger &logger) :
    m_logger(logger),
    m_initialzed(false) {
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

    m_window = glfwCreateWindow( 1024, 768, "planet cannons", NULL, NULL);
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

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.1f, 0.0f);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &m_vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

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

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
    glVertexAttribPointer(
    0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
    3,                  // size
    GL_FLOAT,           // type
    GL_FALSE,           // normalized?
    0,                  // stride
    (void*)0            // array buffer offset
    );
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

GraphicSystem::~GraphicSystem() {
	glfwTerminate();
}