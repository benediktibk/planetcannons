#ifndef PLANETCANNONS_GRAPHICOBJECT_H
#define PLANETCANNONS_GRAPHICOBJECT_H

class IGraphicObject {
    public:        
        IGraphicObject() {}
        virtual void update() const = 0;
        virtual ~IGraphicObject() {}

    private:
        IGraphicObject(const IGraphicObject &) {}
        virtual void operator=(const IGraphicObject &) {}
};

#endif