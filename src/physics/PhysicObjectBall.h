#ifndef PLANETCANNONS_PHYSICOBJECTBALL_H
#define PLANETCANNONS_PHYSICOBJECTBALL_H

#include "IPhysicObject.h"

class ILogger;

class PhysicObjectBall : public IPhysicObject {
    public:
        PhysicObjectBall(const ILogger &logger, double mass, double radius, const LinearAlgebraVector &position, const LinearAlgebraVector &velocity);
        
        virtual LinearAlgebraVector getCenterOfGravity() const;
        LinearAlgebraVector getPosition() const;
        virtual LinearAlgebraVector getVelocity() const;
        virtual double getMass() const;
        virtual void applyForce(const LinearAlgebraVector &force, double time);

    private:
        const ILogger &m_logger;
        double m_mass;
        double m_radius;
        LinearAlgebraVector m_position;
        LinearAlgebraVector m_velocity;
};

#endif