#ifndef PLANETCANNONS_GAMEOBJECTBALL_H
#define PLANETCANNONS_GAMEOBJECTBALL_H

#include "IGameObject.h"

class ILogger;
class GraphicObjectIcosahedron;
class PhysicObjectBall;
class LinearAlgebraVector;
class IShaderFactory;

class GameObjectBall : public IGameObject {
    public: 
        GameObjectBall(
            const ILogger &logger, 
            IShaderFactory &shaderFactory,
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
        GraphicObjectIcosahedron *m_graphicObject;
        PhysicObjectBall *m_physicObject;
};

#endif