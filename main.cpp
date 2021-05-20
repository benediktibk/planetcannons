#include "GraphicSystem.h"
#include "Logger.h"

int main() {
	Logger logger;
	GraphicSystem graphicSystem(logger);

	while (!graphicSystem.closeRequested()) {
		graphicSystem.update();
	}
}