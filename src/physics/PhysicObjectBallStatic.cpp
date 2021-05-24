#include "PhysicObjectBallStatic.h"
#include "utils/ILogger.h"
#include "math/LinearAlgebra.h"

PhysicObjectBallStatic::PhysicObjectBallStatic(
    const ILogger &logger, 
    double mass, 
    double radius, 
    const std::tuple<double, double, double> &position) :
    PhysicObjectBall(logger, mass, radius, position, std::make_tuple<double, double, double>(0, 0, 0)) {
}

void PhysicObjectBallStatic::applyForce(const std::tuple<double, double, double> &, double) {
}

