#include "GameEngine.h"
#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include <unistd.h>

GameEngine::GameEngine(const ILogger &logger, GraphicSystem &graphicSystem, unsigned int maximumFramesPerSecond) :
    m_logger(logger),
    m_graphicSystem(graphicSystem),
    m_maximumFramesPerSecond(maximumFramesPerSecond) {    
}

void GameEngine::execute() {
	VertexShader vertexShader;
	FragmentShader fragmentShader;
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

	bool flip = false;

	while (!m_graphicSystem.closeRequested()) {
		m_graphicSystem.update();
		sleep(1);
		triangleOne->setPoints(
			std::make_tuple(-1.0f, -1.0f, 0.0f), 
			std::make_tuple(1.0f, -1.0f, 0.0f), 
			std::make_tuple(0.0f, flip ? -0.5f : 0.0f, 0.0f));
		flip = !flip;
	}
}