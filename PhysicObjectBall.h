#ifndef PLANETCANNONS_PHYSICOBJECTBALL_H
#define PLANETCANNONS_PHYSICOBJECTBALL_H

#include "IPhysicObject.h"

class ILogger;

class PhysicObjectBall : public IPhysicObject {
    public:
        PhysicObjectBall(const ILogger &logger);

    private:
        const ILogger &m_logger;
};

#endif