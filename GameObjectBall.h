#ifndef PLANETCANNONS_GAMEOBJECTBALL_H
#define PLANETCANNONS_GAMEOBJECTBALL_H

#include "IGameObject.h"
#include <tuple>

class ILogger;
class GraphicObjectCircleFilled;
class PhysicObjectBall;

class GameObjectBall : public IGameObject {
    public: 
        GameObjectBall(
            const ILogger &logger, 
            const std::tuple<float, float, float> &centerPosition, 
            const std::tuple<float, float, float> &velocity, 
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