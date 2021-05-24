#include "PhysicObjectBall.h"
#include "utils/ILogger.h"
#include <sstream>

PhysicObjectBall::PhysicObjectBall(
    const ILogger &logger, 
    double mass, 
    double radius, 
    const LinearAlgebraVector &position, 
    const LinearAlgebraVector &velocity) :
    m_logger(logger),
    m_mass(mass),
    m_radius(radius),
    m_position(position),
    m_velocity(velocity) {
}

LinearAlgebraVector PhysicObjectBall::getCenterOfGravity() const {
    return m_position;
}

LinearAlgebraVector PhysicObjectBall::getPosition() const {
    return m_position;
}

LinearAlgebraVector PhysicObjectBall::getVelocity() const {
    return m_velocity;
}

double PhysicObjectBall::getMass() const {
    return m_mass;
}

void PhysicObjectBall::applyForce(const LinearAlgebraVector &force, double time) {
    auto newPositionDueToVelocity = m_position + time*m_velocity;
    auto positionChangeDueToForce = (time * time / m_mass / 2) * force;
    auto newVelocity = m_velocity + (time / m_mass) * force;

    m_position = newPositionDueToVelocity + positionChangeDueToForce;
    m_velocity = newVelocity;
}

