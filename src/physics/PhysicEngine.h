#ifndef PLANETCANNONS_PHYSICENGINE_H
#define PLANETCANNONS_PHYSICENGINE_H

#include "IPhysicEngine.h"
#include <vector>

class ILogger;

class PhysicEngine : public IPhysicEngine {
    public:
        PhysicEngine(const ILogger &logger, double maximumTimestep);
        virtual ~PhysicEngine();
        virtual void execute(double timeSpan);
        virtual void add(IPhysicObject &physicObject);
        virtual void remove(IPhysicObject &physicObject);

    private:
        const ILogger &m_logger;
        std::vector<IPhysicObject*> m_objects;
        const double m_maximumTimestep;
        const double m_gravitationalConstant;
};

#endif