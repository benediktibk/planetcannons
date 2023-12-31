#include "GameEngine.h"
#include "graphics/IGraphicEngine.h"
#include "physics/IPhysicEngine.h"
#include "utils/ILogger.h"
#include "utils/Clock.h"
#include "IGameObject.h"
#include "GameObjectLight.h"
#include "math/LinearAlgebraVector.h"
#include "math/GeometrySphere.h"
#include <GLFW/glfw3.h>
#include <unistd.h>
#include <cmath>
#include <sstream>

GameEngine::GameEngine(const ILogger &logger, IGraphicEngine &graphicEngine, IPhysicEngine &physicEngine, unsigned int maximumFramesPerSecond, Clock &clock, double timeFactorForPhysicEngine) :
    m_logger(logger),
    m_graphicEngine(graphicEngine),
    m_physicEngine(physicEngine),
    m_maximumFramesPerSecond(maximumFramesPerSecond),
    m_clock(clock),
    m_timeFactorForPhysicEngine(timeFactorForPhysicEngine) {   

    m_light = new GameObjectLight(
		logger,
		graphicEngine.getShaderFactory(),
		LinearAlgebraVector(0, 0, 0.5),
		0.01);
        
	add(*m_light);
}

GameEngine::~GameEngine() {
    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        (*object)->removeFromGraphicEngine(m_graphicEngine);
        (*object)->removeFromPhysicEngine(m_physicEngine);
    }

    m_objects.clear();

    delete m_light;
    m_light = 0;
}

void GameEngine::add(IGameObject &object) {
    m_objects.push_back(&object);
    object.addToGraphicEngine(m_graphicEngine);
    object.addToPhysicEngine(m_physicEngine);
}

void GameEngine::remove(IGameObject &object) {
    object.removeFromGraphicEngine(m_graphicEngine);
    object.removeFromPhysicEngine(m_physicEngine);
    std::remove(m_objects.begin(), m_objects.end(), &object);
}

void GameEngine::execute() {
    m_graphicEngine.configureLighting(m_light->getPosition(), 0.2, 0.5, 32);

    m_clock.startMeasurement();
    uint64_t lastTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
    double minimumFrameLength = 1.0/m_maximumFramesPerSecond;

    double phi = 0.0;
    double theta = 0.0;
    unsigned int frames = 0;
    uint64_t lastTimeFpsOutputCreatedInMilliseconds = lastTimeInMilliseconds;
    uint64_t lastTimePhysicUpdateInMilliseconds = lastTimeInMilliseconds;
    double correctionFactorSleepTime = 0.95;
    GeometrySphere sphere(LinearAlgebraVector(0, 0, 0), 1);

	while (!m_graphicEngine.closeRequested()) {
        if (m_graphicEngine.keyPressed(GLFW_KEY_DOWN)) {
            theta -= 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_UP)) {
            theta += 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_LEFT)) {
            phi -= 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_RIGHT)) {
            phi += 0.01;
        }

        if (phi < 0) {
            phi += 2*M_PI;
        }

        if (phi > 2*M_PI) {
            phi -= 2*M_PI;
        }

        if (theta < 0) {
            theta += 2*M_PI;
        }

        if (theta > 2*M_PI) {
            theta -= 2*M_PI;
        }

        auto cameraPosition = sphere.calculatePoint(phi, theta);
        m_graphicEngine.setCamera(cameraPosition, LinearAlgebraVector(0, 0, 0), M_PI/2, 1, 0.1, 100);

        uint64_t currentTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
        double timeSpanForPhysicSimulation = (currentTimeInMilliseconds - lastTimePhysicUpdateInMilliseconds) / 1000.0;
        m_physicEngine.execute(timeSpanForPhysicSimulation*m_timeFactorForPhysicEngine);
        lastTimePhysicUpdateInMilliseconds = currentTimeInMilliseconds;

        for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
            (*object)->updateGraphics();
        }

		m_graphicEngine.update();

        currentTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
        frames++;

        if (currentTimeInMilliseconds - lastTimeFpsOutputCreatedInMilliseconds > 1000) {
            double framesPerSecond = (double)frames / (currentTimeInMilliseconds - lastTimeFpsOutputCreatedInMilliseconds) * 1000;
            std::stringstream logStream;
            logStream << "frames per second: " << framesPerSecond;
            m_logger.debug(logStream.str());
            frames = 0;
            lastTimeFpsOutputCreatedInMilliseconds = currentTimeInMilliseconds;
        }

        currentTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
        uint64_t frameLengthInMilliseconds = currentTimeInMilliseconds - lastTimeInMilliseconds;
        int64_t timeToSleepInMicroseconds = (minimumFrameLength * 1e6 - frameLengthInMilliseconds) * correctionFactorSleepTime;
        lastTimeInMilliseconds = currentTimeInMilliseconds;
        
        if (timeToSleepInMicroseconds > 0) {
            usleep(timeToSleepInMicroseconds);
        }
	}
}