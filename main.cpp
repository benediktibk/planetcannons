#include "GameEngine.h"
#include "Logger.h"
#include "GraphicSystem.h"
#include "Clock.h"

int main() {
    Logger logger;
	Clock clock;
	GameEngine gameEngine(logger, GraphicSystem::get(logger), 60, clock);
	gameEngine.execute();
}