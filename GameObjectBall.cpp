#include "GameObjectBall.h"
#include "GraphicObjectCircleFilled.h"
#include "PhysicObjectBall.h"
#include "ILogger.h"
#include "IPhysicEngine.h"
#include "IGraphicEngine.h"

GameObjectBall::GameObjectBall(const ILogger &logger, const std::tuple<float, float, float> &centerPosition, const std::tuple<float, float, float> &velocity, double radius, double mass) :
    m_logger(logger) {
    m_graphicObject = new GraphicObjectCircleFilled(logger, centerPosition, radius, 32);
    m_physicObject = new PhysicObjectBall(logger, mass, radius, centerPosition, velocity);
}

GameObjectBall::~GameObjectBall() {
    delete m_physicObject;
    m_physicObject = 0;
    delete m_graphicObject;
    m_graphicObject = 0;
}

void GameObjectBall::updateGraphics() {
    m_graphicObject->setCenterPosition(m_physicObject->getPosition());
}

void GameObjectBall::addToGraphicEngine(IGraphicEngine &graphicEngine) const {
    graphicEngine.add(*m_graphicObject);
}

void GameObjectBall::addToPhysicEngine(IPhysicEngine &physicEngine) const {
    physicEngine.add(*m_physicObject);
}

void GameObjectBall::removeFromGraphicEngine(IGraphicEngine &graphicEngine) const {
    graphicEngine.remove(*m_graphicObject);
}

void GameObjectBall::removeFromPhysicEngine(IPhysicEngine &physicEngine) const {
    physicEngine.remove(*m_physicObject);
}