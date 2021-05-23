#ifndef PLANETCANNONS_IGRAPHICENGINE_H
#define PLANETCANNONS_IGRAPHICENGINE_H

class IGraphicObject;

class IGraphicEngine {
    public:
        virtual void update() = 0;
        virtual bool closeRequested() = 0;
        virtual void add(IGraphicObject &graphicObject) = 0;
        virtual void remove(IGraphicObject &graphicObject) = 0;
        virtual bool keyPressed(unsigned int keyType) = 0;

        IGraphicEngine() {};
        ~IGraphicEngine() {};

    private:
        IGraphicEngine(const IGraphicEngine&) {}
        void operator=(const IGraphicEngine&) {}
};

#endif