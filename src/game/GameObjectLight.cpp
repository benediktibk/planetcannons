#include "GameObjectLight.h"
#include "graphics/GraphicObjectSphere.h"
#include "utils/ILogger.h"
#include "graphics/IGraphicEngine.h"
#include "math/LinearAlgebraVector.h"

GameObjectLight::GameObjectLight(const ILogger &logger, IShaderFactory &shaderFactory, const LinearAlgebraVector &centerPosition, double radius) :
    m_logger(logger) {
    m_graphicObject = new GraphicObjectSphere(shaderFactory, centerPosition, radius, 3, std::make_tuple<float, float, float, float>(1, 1, 1, 1));
}

GameObjectLight::~GameObjectLight() {
    delete m_graphicObject;
    m_graphicObject = 0;
}

void GameObjectLight::updateGraphics() {
}

void GameObjectLight::addToGraphicEngine(IGraphicEngine &graphicEngine) const {
    graphicEngine.add(*m_graphicObject);
}

void GameObjectLight::addToPhysicEngine(IPhysicEngine &) const {
}

void GameObjectLight::removeFromGraphicEngine(IGraphicEngine &graphicEngine) const {
    graphicEngine.remove(*m_graphicObject);
}

void GameObjectLight::removeFromPhysicEngine(IPhysicEngine &) const {
}

const LinearAlgebraVector& GameObjectLight::getPosition() const {
    return m_graphicObject->getCenterPosition();
}