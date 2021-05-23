#include "GameEngine.h"
#include "Logger.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "Clock.h"

int main() {
    Logger logger;
	Clock clock;
	PhysicEngine physicEngine(logger);
	GameEngine gameEngine(logger, GraphicEngine::get(logger), physicEngine, 60, clock);
	gameEngine.execute();
}