#include "GameEngine.h"
#include "Logger.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "Clock.h"
#include "GameObjectBall.h"

int main() {
    Logger logger;
	Clock clock;
	PhysicEngine physicEngine(logger, 1e-3);
	GameEngine gameEngine(logger, GraphicEngine::get(logger), physicEngine, 60, clock);
	GameObjectBall ballOne(
		logger,
		std::make_tuple<double, double, double>(-0.25, 0, 0),
		std::make_tuple<double, double, double>(0, 0, 0),
		0.1,
		10);
	GameObjectBall ballTwo(
		logger,
		std::make_tuple<double, double, double>(0.25, 0, 0),
		std::make_tuple<double, double, double>(0, 0, 0),
		0.1,
		10);
	gameEngine.add(ballOne);
	gameEngine.add(ballTwo);
	gameEngine.execute();
}