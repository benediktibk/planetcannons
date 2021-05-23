#include "PhysicObjectBall.h"
#include "ILogger.h"

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

double PhysicObjectBall::getMass() const {
    return m_mass;
}

void PhysicObjectBall::applyForce(double, double) {

}

