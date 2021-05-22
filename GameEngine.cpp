#include "GameEngine.h"
#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include "Clock.h"
#include "GraphicObjectCircle.h"
#include "GraphicObjectCircleFilled.h"
#include <unistd.h>
#include <cmath>

GameEngine::GameEngine(const ILogger &logger, GraphicSystem &graphicSystem, unsigned int maximumFramesPerSecond, Clock &clock) :
    m_logger(logger),
    m_graphicSystem(graphicSystem),
    m_maximumFramesPerSecond(maximumFramesPerSecond),
    m_clock(clock) {    
}

void GameEngine::execute() {
    const char* vertexShaderCode =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";
    const char* fragmentShaderCode =
        "#version 400\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
        "}";
	VertexShader vertexShader(m_logger, std::string(vertexShaderCode));
	FragmentShader fragmentShader(m_logger, std::string(fragmentShaderCode));
	ShaderProgram shaderProgram(m_logger, vertexShader, fragmentShader);
	GraphicObjectTriangle *triangleOne = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, -1.0f, 0.0f), 
		std::make_tuple(-0.5f, -1.0f, 0.0f), 
		std::make_tuple(-0.75f, 0.0f, 0.0f),
		shaderProgram);
	GraphicObjectTriangle *triangleTwo = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, 0.0f, 0.0f), 
		std::make_tuple(-0.5f, 0.0f, 0.0f), 
		std::make_tuple(-0.75f, 1.0f, 0.0f),
		shaderProgram);
    GraphicObjectCircle *circle = new GraphicObjectCircle(
		std::make_tuple(0.7f, 0.7f, 0.0f),
        0.1,
        32,
        shaderProgram);
    GraphicObjectCircleFilled *circleFilled = new GraphicObjectCircleFilled(
		std::make_tuple(0.0f, 0.0f, 0.0f),
        0.2,
        100,
        shaderProgram);
	m_graphicSystem.add(triangleOne);
	m_graphicSystem.add(triangleTwo);
	m_graphicSystem.add(circle);
	m_graphicSystem.add(circleFilled);

    m_clock.startMeasurement();
    uint64_t lastTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
    double minimumFrameLength = 1.0/m_maximumFramesPerSecond;

    double movementFrequency = 0.5;
	while (!m_graphicSystem.closeRequested()) {
        double yPosition = sin(2 * 3.141592564 * movementFrequency * lastTimeInMilliseconds/1000.0)/2;

		circleFilled->setCenterPosition(std::make_tuple(0, yPosition, 0));
		m_graphicSystem.update();

        uint64_t currentTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
        uint64_t frameLengthInMilliseconds = currentTimeInMilliseconds - lastTimeInMilliseconds;
        int64_t timeToSleepInMicroseconds = minimumFrameLength * 1e6 - frameLengthInMilliseconds;
        lastTimeInMilliseconds = currentTimeInMilliseconds;
        
        if (timeToSleepInMicroseconds > 0) {
            usleep(timeToSleepInMicroseconds);
        }
	}
}