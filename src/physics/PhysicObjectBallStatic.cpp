#include "PhysicObjectBallStatic.h"
#include "utils/ILogger.h"
#include "math/LinearAlgebraVector.h"

PhysicObjectBallStatic::PhysicObjectBallStatic(
    const ILogger &logger, 
    double mass, 
    double radius, 
    const LinearAlgebraVector &position) :
    PhysicObjectBall(logger, mass, radius, position, LinearAlgebraVector(0, 0, 0)) {
}

void PhysicObjectBallStatic::applyForce(const LinearAlgebraVector &, double) {
}

