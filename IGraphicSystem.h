#ifndef PLANETCANNONS_IGRAPHICSYSTEM_H
#define PLANETCANNONS_IGRAPHICSYSTEM_H

class IGraphicObject;

class IGraphicSystem {
    public:
        virtual void update() = 0;
        virtual bool closeRequested() = 0;
        virtual void add(IGraphicObject *graphicObject) = 0;

        IGraphicSystem() {};
        ~IGraphicSystem() {};

    private:
        IGraphicSystem(const IGraphicSystem&) {}
        void operator=(const IGraphicSystem&) {}
};

#endif