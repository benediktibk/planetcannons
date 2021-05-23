#include "PhysicObjectBall.h"
#include "ILogger.h"
#include "LinearAlgebra.h"

PhysicObjectBall::PhysicObjectBall(
    const ILogger &logger, 
    double mass, 
    double radius, 
    const std::tuple<double, double, double> &position, 
    const std::tuple<double, double, double> &velocity) :
    m_logger(logger),
    m_mass(mass),
    m_radius(radius),
    m_position(position),
    m_velocity(velocity) {
}

std::tuple<double, double, double> PhysicObjectBall::getCenterOfGravity() const {
    return m_position;
}

std::tuple<double, double, double> PhysicObjectBall::getPosition() const {
    return m_position;
}

std::tuple<double, double, double> PhysicObjectBall::getVelocity() const {
    return m_velocity;
}

double PhysicObjectBall::getMass() const {
    return m_mass;
}

void PhysicObjectBall::applyForce(const std::tuple<double, double, double> &force, double time) {
    auto newPositionDueToVelocity = LinearAlgebra::add(m_position, LinearAlgebra::multiply(time, m_velocity));
    auto positionChangeDueToForce = LinearAlgebra::multiply(time * time / m_mass / 2, force);
    m_position = LinearAlgebra::add(newPositionDueToVelocity, positionChangeDueToForce);
}

