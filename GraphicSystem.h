#ifndef PLANETCANNONS_GRAPHICSYSTEM_H
#define PLANETCANNONS_GRAPHICSYSTEM_H

#include "IGraphicSystem.h"

class ILogger;

class GraphicSystem : public IGraphicSystem {
    public:
        GraphicSystem(const ILogger &logger);
        virtual void update();

    private:
        const ILogger &m_logger;
};

#endif