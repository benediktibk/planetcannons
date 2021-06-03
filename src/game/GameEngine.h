#ifndef PLANETCANNONS_GAMEENGINE_H
#define PLANETCANNONS_GAMEENGINE_H

#include <vector>

class ILogger;
class IGraphicEngine;
class IPhysicEngine;
class Clock;
class IGameObject;
class GameObjectLight;

class GameEngine {
    public: 
        GameEngine(const ILogger &logger, IGraphicEngine &graphicEngine, IPhysicEngine &physicEngine, unsigned int maximumFramesPerSecond, Clock &clock, double timeFactorForPhysicEngine);
        ~GameEngine();
        void execute();
        void add(IGameObject &object);

    private:
        const ILogger &m_logger;
        IGraphicEngine &m_graphicEngine;
        IPhysicEngine &m_physicEngine;
        const unsigned int m_maximumFramesPerSecond;
        Clock &m_clock;
        std::vector<IGameObject*> m_objects;
        double m_timeFactorForPhysicEngine;
        GameObjectLight *m_light;
};

#endif