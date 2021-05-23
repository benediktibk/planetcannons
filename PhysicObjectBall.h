#ifndef PLANETCANNONS_PHYSICOBJECTBALL_H
#define PLANETCANNONS_PHYSICOBJECTBALL_H

#include "IPhysicObject.h"
#include <tuple>

class ILogger;

class PhysicObjectBall : public IPhysicObject {
    public:
        PhysicObjectBall(const ILogger &logger, double mass, double radius, const std::tuple<double, double, double> &position, const std::tuple<double, double, double> &velocity);
        
        virtual std::tuple<double, double, double> getCenterOfGravity() const;
        virtual std::tuple<double, double, double> getPosition() const;
        virtual std::tuple<double, double, double> getVelocity() const;
        virtual double getMass() const;
        virtual void applyForce(const std::tuple<double, double, double> &force, double time);

    private:
        const ILogger &m_logger;
        double m_mass;
        double m_radius;
        std::tuple<double, double, double> m_position;
        std::tuple<double, double, double> m_velocity;
};

#endif