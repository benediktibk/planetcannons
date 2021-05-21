#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include <unistd.h>

int main() {
	Logger logger;
	GraphicSystem graphicSystem(logger);
	GraphicObjectTriangle *triangleOne = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, -1.0f, 0.0f), 
		std::make_tuple(1.0f, -1.0f, 0.0f), 
		std::make_tuple(0.0f, 0.0f, 0.0f));
	GraphicObjectTriangle *triangleTwo = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, 0.0f, 0.0f), 
		std::make_tuple(1.0f, 0.0f, 0.0f), 
		std::make_tuple(0.0f, 1.0f, 0.0f));
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