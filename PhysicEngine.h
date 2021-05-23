#ifndef PLANETCANNONS_PHYSICENGINE_H
#define PLANETCANNONS_PHYSICENGINE_H

#include "IPhysicEngine.h"
#include <vector>

class ILogger;

class PhysicEngine : public IPhysicEngine {
    public:
        PhysicEngine(const ILogger &logger);
        virtual ~PhysicEngine();
        virtual void execute(double timeSpan);
        virtual void add(IPhysicObject *physicObject);

    private:
        const ILogger &m_logger;
        std::vector<IPhysicObject*> m_objects;
};

#endif