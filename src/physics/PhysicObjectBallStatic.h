#ifndef PLANETCANNONS_PHYSICOBJECTBALLSTATIC_H
#define PLANETCANNONS_PHYSICOBJECTBALLSTATIC_H

#include "PhysicObjectBall.h"

class ILogger;

class PhysicObjectBallStatic : public PhysicObjectBall {
    public:
        PhysicObjectBallStatic(const ILogger &logger, double mass, double radius, const LinearAlgebraVector &position);
        
        virtual void applyForce(const LinearAlgebraVector &force, double time);
};

#endif