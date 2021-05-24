#ifndef PLANETCANNONS_IPHYSICOBJECT_H
#define PLANETCANNONS_IPHYSICOBJECT_H

#include "math/LinearAlgebraVector.h"

class IPhysicObject {
    public:
        IPhysicObject() {}
        virtual ~IPhysicObject() {}

        virtual LinearAlgebraVector getCenterOfGravity() const = 0;
        virtual LinearAlgebraVector getVelocity() const = 0;
        virtual double getMass() const = 0;
        virtual void applyForce(const LinearAlgebraVector &force, double time) = 0;

    private:
        IPhysicObject(const IPhysicObject &) {}
        void operator=(const IPhysicObject &) {}
};

#endif