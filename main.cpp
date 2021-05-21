#include "GameEngine.h"
#include "Logger.h"
#include "GraphicSystem.h"

int main() {
    Logger logger;
	GraphicSystem graphicSystem(logger);
	GameEngine gameEngine(logger, graphicSystem, 60);
	gameEngine.execute();
}