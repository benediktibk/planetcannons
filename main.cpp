#include "GameEngine.h"
#include "Logger.h"
#include "GraphicSystem.h"
#include "Clock.h"

int main() {
    Logger logger;
	GraphicSystem graphicSystem(logger);
	Clock clock;
	GameEngine gameEngine(logger, graphicSystem, 60, clock);
	gameEngine.execute();
}