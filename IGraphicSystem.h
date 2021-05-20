#ifndef PLANETCANNONS_IGRAPHICSYSTEM_H
#define PLANETCANNONS_IGRAPHICSYSTEM_H

class IGraphicSystem {
    public:
        virtual void update() = 0;

        IGraphicSystem() {};
        ~IGraphicSystem() {};

    private:
        IGraphicSystem(const IGraphicSystem&) {}
        void operator=(const IGraphicSystem&) {}
};

#endif