#include "game/GameEngine.h"
#include "utils/Logger.h"
#include "graphics/IGraphicEngine.h"
#include "graphics/GraphicEngine.h"
#include "physics/PhysicEngine.h"
#include "utils/Clock.h"
#include "game/GameObjectBall.h"
#include "math/LinearAlgebraVector.h"

int main() {
	const double ballWeight = 1e2;
	const double timeFactorForPhysicEngine = 1e3;
	const double maximumTimeStep = timeFactorForPhysicEngine*1e-3;

    Logger logger;
	Clock clock;
	PhysicEngine physicEngine(logger, maximumTimeStep);
	IGraphicEngine &graphicEngine = GraphicEngine::get(logger);
	GameEngine gameEngine(logger, graphicEngine, physicEngine, 60, clock, timeFactorForPhysicEngine);
	GameObjectBall ballOne(
		logger,
		graphicEngine.getShaderFactory(),
		LinearAlgebraVector(-0.25, 0, 0),
		LinearAlgebraVector(1e-6, -9e-5, 0),
		0.1,
		ballWeight);
	GameObjectBall ballTwo(
		logger,
		graphicEngine.getShaderFactory(),
		LinearAlgebraVector(0.25, 0, 0),
		LinearAlgebraVector(0, 1e-4, 0),
		0.1,
		ballWeight);
	GameObjectBall ballThree(
		logger,
		graphicEngine.getShaderFactory(),
		LinearAlgebraVector(0, -0.7, 0),
		LinearAlgebraVector(-1e-4, 1e-5, 0),
		0.1,
		ballWeight);

	gameEngine.add(ballOne);
	gameEngine.add(ballTwo);
	gameEngine.add(ballThree);
	
	gameEngine.execute();

	gameEngine.remove(ballOne);
	gameEngine.remove(ballTwo);
	gameEngine.remove(ballThree);
}