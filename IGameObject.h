#ifndef PLANETCANNONS_IGAMEOBJECT_H
#define PLANETCANNONS_IGAMEOBJECT_H

class IGraphicEngine;
class IPhysicEngine;

class IGameObject {
    public:        
        IGameObject() {}
        virtual void updateGraphics() = 0;
        virtual void addToGraphicEngine(IGraphicEngine &graphicEngine) const = 0;
        virtual void addToPhysicEngine(IPhysicEngine &physicEngine) const = 0;
        virtual void removeFromGraphicEngine(IGraphicEngine &graphicEngine) const = 0;
        virtual void removeFromPhysicEngine(IPhysicEngine &physicEngine) const = 0;
        virtual ~IGameObject() {}

    private:
        IGameObject(const IGameObject &) {}
        virtual void operator=(const IGameObject &) {}
};

#endif