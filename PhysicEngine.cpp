#include "PhysicEngine.h"
#include "IPhysicObject.h"
#include "LinearAlgebra.h"

PhysicEngine::PhysicEngine(const ILogger &logger, double maximumTimestep) :
    m_logger(logger),
    m_maximumTimestep(maximumTimestep),
    m_gravitationalConstant(6.67408e-11) {
}

PhysicEngine::~PhysicEngine() {
    m_objects.clear();
}

void PhysicEngine::execute(double timeSpan) {
    double time = 0;

    while (timeSpan - time > 1e-6) {
        double currentTimestep = std::min(m_maximumTimestep, timeSpan - time);
        std::vector<std::tuple<double, double, double> > totalForces;

        for (auto object = m_objects.begin(); object != m_objects.end(); ++object) {
            auto totalForce = std::make_tuple<double, double, double>(0, 0, 0);
            auto objectPointer = *object;

            for (auto otherObject = m_objects.begin(); otherObject != m_objects.end(); ++otherObject) {
                if (object == otherObject) {
                    continue;
                }

                auto otherObjectPointer = *otherObject;

                auto distanceVector = LinearAlgebra::subtract(objectPointer->getCenterOfGravity(), otherObjectPointer->getCenterOfGravity());
                auto distance = LinearAlgebra::norm(distanceVector);
                auto factor = (-1)*m_gravitationalConstant*objectPointer->getMass()*otherObjectPointer->getMass()/(distance*distance*distance);
                auto force = LinearAlgebra::multiply(factor, distanceVector);
                totalForce = LinearAlgebra::add(totalForce, force);
            }

            totalForces.push_back(totalForce);
        }

        for (size_t i = 0; i < m_objects.size(); ++i) {
            m_objects[i]->applyForce(totalForces[i], currentTimestep);
        }

        time += currentTimestep;
    }
}

void PhysicEngine::add(IPhysicObject &physicObject) {
    m_objects.push_back(&physicObject);
}