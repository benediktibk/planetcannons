#include "GameObjectBall.h"
#include "graphics/GraphicObjectSphere.h"
#include "physics/PhysicObjectBall.h"
#include "utils/ILogger.h"
#include "physics/IPhysicEngine.h"
#include "graphics/IGraphicEngine.h"
#include "math/LinearAlgebraVector.h"

GameObjectBall::GameObjectBall(const ILogger &logger, IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, const LinearAlgebraVector &velocity, double radius, double mass) :
    m_logger(logger) {
    m_graphicObject = new GraphicObjectSphere(shaderFactory, centerPosition, radius, 3, std::make_tuple<float, float, float, float>(0, 1, 0.5, 1.0), true);
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