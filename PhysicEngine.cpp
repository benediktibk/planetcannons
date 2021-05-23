#include "PhysicEngine.h"
#include "IPhysicObject.h"

PhysicEngine::PhysicEngine(const ILogger &logger) :
    m_logger(logger) {
}

PhysicEngine::~PhysicEngine() {
    for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
        delete *object;
    }

    m_objects.clear();
}

void PhysicEngine::execute(double) {

}

void PhysicEngine::add(IPhysicObject &physicObject) {
    m_objects.push_back(&physicObject);
}