#ifndef PLANETCANNONS_PHYSICOBJECTBALLSTATIC_H
#define PLANETCANNONS_PHYSICOBJECTBALLSTATIC_H

#include "PhysicObjectBall.h"
#include <tuple>

class ILogger;

class PhysicObjectBallStatic : public PhysicObjectBall {
    public:
        PhysicObjectBallStatic(const ILogger &logger, double mass, double radius, const std::tuple<double, double, double> &position);
        
        virtual void applyForce(const std::tuple<double, double, double> &force, double time);
};

#endif