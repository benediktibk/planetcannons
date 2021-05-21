#ifndef PLANETCANNONS_GAMEENGINE_H
#define PLANETCANNONS_GAMEENGINE_H

class ILogger;
class GraphicSystem;

class GameEngine {
    public: 
        GameEngine(const ILogger &logger, GraphicSystem &graphicSystem, unsigned int maximumFramesPerSecond);
        void execute();

    private:
        const ILogger &m_logger;
        GraphicSystem &m_graphicSystem;
        const unsigned int m_maximumFramesPerSecond;
};

#endif