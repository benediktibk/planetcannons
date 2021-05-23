#include "GameEngine.h"
#include "IGraphicEngine.h"
#include "IPhysicEngine.h"
#include "Logger.h"
#include "GraphicObjectTriangle.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include "Clock.h"
#include "GraphicObjectCircle.h"
#include "GraphicObjectCircleFilled.h"
#include "IGameObject.h"
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
}

GameEngine::~GameEngine() {
    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        (*object)->removeFromGraphicEngine(m_graphicEngine);
        (*object)->removeFromPhysicEngine(m_physicEngine);
    }

    m_objects.clear();
}

void GameEngine::add(IGameObject &object) {
    m_objects.push_back(&object);
    object.addToGraphicEngine(m_graphicEngine);
    object.addToPhysicEngine(m_physicEngine);
}

void GameEngine::execute() {
    m_clock.startMeasurement();
    uint64_t lastTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
    double minimumFrameLength = 1.0/m_maximumFramesPerSecond;

    double xPosition = 0.0;
    double yPosition = 0.0;
    unsigned int frames = 0;
    uint64_t lastTimeFpsOutputCreatedInMilliseconds = lastTimeInMilliseconds;
    uint64_t lastTimePhysicUpdateInMilliseconds = lastTimeInMilliseconds;
    double correctionFactorSleepTime = 0.95;

	while (!m_graphicEngine.closeRequested()) {
        if (m_graphicEngine.keyPressed(GLFW_KEY_LEFT)) {
            xPosition -= 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_RIGHT)) {
            xPosition += 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_DOWN)) {
            yPosition -= 0.01;
        }

        if (m_graphicEngine.keyPressed(GLFW_KEY_UP)) {
            yPosition += 0.01;
        }

        uint64_t currentTimeInMilliseconds = m_clock.getMillisecondsSinceStart();
        double timeSpanForPhysicSimulation = (currentTimeInMilliseconds - lastTimePhysicUpdateInMilliseconds) / 1000.0;
        m_physicEngine.execute(timeSpanForPhysicSimulation*m_timeFactorForPhysicEngine);
        lastTimePhysicUpdateInMilliseconds = currentTimeInMilliseconds;

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