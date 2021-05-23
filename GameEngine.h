#ifndef PLANETCANNONS_GAMEENGINE_H
#define PLANETCANNONS_GAMEENGINE_H

class ILogger;
class IGraphicEngine;
class IPhysicEngine;
class Clock;

class GameEngine {
    public: 
        GameEngine(const ILogger &logger, IGraphicEngine &graphicEngine, IPhysicEngine &physicEngine, unsigned int maximumFramesPerSecond, Clock &clock);
        void execute();

    private:
        const ILogger &m_logger;
        IGraphicEngine &m_graphicEngine;
        IPhysicEngine &m_physicEngine;
        const unsigned int m_maximumFramesPerSecond;
        Clock &m_clock;
};

#endif