#ifndef PLANETCANNONS_IPHYSICOBJECT_H
#define PLANETCANNONS_IPHYSICOBJECT_H

#include <tuple>

class IPhysicObject {
    public:
        IPhysicObject() {}
        virtual ~IPhysicObject() {}

        virtual std::tuple<double, double, double> getCenterOfGravity() const = 0;
        virtual double getMass() const = 0;
        virtual void applyForce(double force, double time) = 0;

    private:
        IPhysicObject(const IPhysicObject &) {}
        void operator=(const IPhysicObject &) {}
};

#endif