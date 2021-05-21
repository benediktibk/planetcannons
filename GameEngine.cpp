#include "GameEngine.h"
#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include "Clock.h"
#include <unistd.h>
#include <cmath>

GameEngine::GameEngine(const ILogger &logger, GraphicSystem &graphicSystem, unsigned int maximumFramesPerSecond, Clock &clock) :
    m_logger(logger),
    m_graphicSystem(graphicSystem),
    m_maximumFramesPerSecond(maximumFramesPerSecond),
    m_clock(clock) {    
}

void GameEngine::execute() {
	VertexShader vertexShader(m_logger);
	FragmentShader fragmentShader(m_logger);
	ShaderProgram shaderProgram(vertexShader, fragmentShader);
	GraphicObjectTriangle *triangleOne = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, -1.0f, 0.0f), 
		std::make_tuple(1.0f, -1.0f, 0.0f), 
		std::make_tuple(0.0f, 0.0f, 0.0f),
		shaderProgram);
	GraphicObjectTriangle *triangleTwo = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, 0.0f, 0.0f), 
		std::make_tuple(1.0f, 0.0f, 0.0f), 
		std::make_tuple(0.0f, 1.0f, 0.0f),
		shaderProgram);
	m_graphicSystem.add(triangleOne);
	m_graphicSystem.add(triangleTwo);

    m_clock.startMeasurement();
    uint64_t lastTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
    double minimumFrameLength = 1.0/m_maximumFramesPerSecond;
	while (!m_graphicSystem.closeRequested()) {
        double yPosition = sin(2 * 3.141592564 * 1 * lastTimeInMilliseconds/1000.0)/2 - 0.5;

		triangleOne->setPoints(
			std::make_tuple(-1.0f, -1.0f, 0.0f), 
			std::make_tuple(1.0f, -1.0f, 0.0f), 
			std::make_tuple(0.0f, yPosition, 0.0f));
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