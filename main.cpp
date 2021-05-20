#include "GraphicSystem.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"

int main() {
	Logger logger;
	GraphicSystem graphicSystem(logger);
	GraphicObjectTriangle *triangleOne = new GraphicObjectTriangle(
		std::make_tuple(-1.0f, -1.0f, 0.0f), 
		std::make_tuple(1.0f, -1.0f, 0.0f), 
		std::make_tuple(0.0f, 1.0f, 0.0f));
	graphicSystem.add(triangleOne);

	while (!graphicSystem.closeRequested()) {
		graphicSystem.update();
	}
}