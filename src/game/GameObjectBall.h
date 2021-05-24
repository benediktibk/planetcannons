#ifndef PLANETCANNONS_GAMEOBJECTBALL_H
#define PLANETCANNONS_GAMEOBJECTBALL_H

#include "IGameObject.h"

class ILogger;
class GraphicObjectCircleFilled;
class PhysicObjectBall;
class LinearAlgebraVector;

class GameObjectBall : public IGameObject {
    public: 
        GameObjectBall(
            const ILogger &logger, 
            const LinearAlgebraVector &centerPosition, 
            const LinearAlgebraVector &velocity, 
            double radius, 
            double mass);
        virtual ~GameObjectBall();
        virtual void updateGraphics();
        virtual void addToGraphicEngine(IGraphicEngine &graphicEngine) const;
        virtual void addToPhysicEngine(IPhysicEngine &physicEngine) const;
        virtual void removeFromGraphicEngine(IGraphicEngine &graphicEngine) const;
        virtual void removeFromPhysicEngine(IPhysicEngine &physicEngine) const;

    private:
        const ILogger &m_logger;
        GraphicObjectCircleFilled *m_graphicObject;
        PhysicObjectBall *m_physicObject;
};

#endif