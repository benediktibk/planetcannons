#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include <unistd.h>

int main() {
	Logger logger;
	GraphicSystem graphicSystem(logger);
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
	graphicSystem.add(triangleOne);
	graphicSystem.add(triangleTwo);

	bool flip = false;

	while (!graphicSystem.closeRequested()) {
		graphicSystem.update();
		sleep(1);
		triangleOne->setPoints(
			std::make_tuple(-1.0f, -1.0f, 0.0f), 
			std::make_tuple(1.0f, -1.0f, 0.0f), 
			std::make_tuple(0.0f, flip ? -0.5f : 0.0f, 0.0f));
		flip = !flip;
	}
}