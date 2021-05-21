#ifndef PLANETCANNONS_GAMEENGINE_H
#define PLANETCANNONS_GAMEENGINE_H

class ILogger;
class GraphicSystem;
class Clock;

class GameEngine {
    public: 
        GameEngine(const ILogger &logger, GraphicSystem &graphicSystem, unsigned int maximumFramesPerSecond, Clock &clock);
        void execute();

    private:
        const ILogger &m_logger;
        GraphicSystem &m_graphicSystem;
        const unsigned int m_maximumFramesPerSecond;
        Clock &m_clock;
};

#endif