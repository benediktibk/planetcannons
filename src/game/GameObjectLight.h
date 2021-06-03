#ifndef PLANETCANNONS_GAMEOBJECTLIGHT_H
#define PLANETCANNONS_GAMEOBJECTLIGHT_H

#include "IGameObject.h"

class ILogger;
class GraphicObjectSphere;
class LinearAlgebraVector;
class IShaderFactory;

class GameObjectLight : public IGameObject {
    public: 
        GameObjectLight(
            const ILogger &logger, 
            IShaderFactory &shaderFactory,
            const LinearAlgebraVector &centerPosition,
            double radius);
        virtual ~GameObjectLight();
        virtual void updateGraphics();
        virtual void addToGraphicEngine(IGraphicEngine &graphicEngine) const;
        virtual void addToPhysicEngine(IPhysicEngine &physicEngine) const;
        virtual void removeFromGraphicEngine(IGraphicEngine &graphicEngine) const;
        virtual void removeFromPhysicEngine(IPhysicEngine &physicEngine) const;
        const LinearAlgebraVector& getPosition() const;

    private:
        const ILogger &m_logger;
        GraphicObjectSphere *m_graphicObject;
};

#endif