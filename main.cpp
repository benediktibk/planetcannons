#include "GameEngine.h"
#include "Logger.h"
#include "GraphicEngine.h"
#include "Clock.h"

int main() {
    Logger logger;
	Clock clock;
	GameEngine gameEngine(logger, GraphicEngine::get(logger), 60, clock);
	gameEngine.execute();
}