#include "GameEngine.h"
#include "Logger.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "Clock.h"
#include "GameObjectBall.h"

int main() {
	const double ballWeight = 1e2;
	const double timeFactorForPhysicEngine = 1e3;
	const double maximumTimeStep = timeFactorForPhysicEngine*1e-3;

    Logger logger;
	Clock clock;
	PhysicEngine physicEngine(logger, maximumTimeStep);
	GameEngine gameEngine(logger, GraphicEngine::get(logger), physicEngine, 60, clock, timeFactorForPhysicEngine);
	GameObjectBall ballOne(
		logger,
		std::make_tuple<double, double, double>(-0.25, 0, 0),
		std::make_tuple<double, double, double>(1e-6, -9e-5, 0),
		0.1,
		ballWeight);
	GameObjectBall ballTwo(
		logger,
		std::make_tuple<double, double, double>(0.25, 0, 0),
		std::make_tuple<double, double, double>(0, 1e-4, 0),
		0.1,
		ballWeight);
	GameObjectBall ballThree(
		logger,
		std::make_tuple<double, double, double>(0, -0.7, 0),
		std::make_tuple<double, double, double>(-1e-4, 0, 0),
		0.1,
		ballWeight);

	gameEngine.add(ballOne);
	gameEngine.add(ballTwo);
	gameEngine.add(ballThree);
	gameEngine.execute();
}