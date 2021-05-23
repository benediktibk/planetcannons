#ifndef PLANETCANNONS_IPHYSICOBJECT_H
#define PLANETCANNONS_IPHYSICOBJECT_H

class IPhysicObject {
    public:
        IPhysicObject() {}
        virtual ~IPhysicObject() {}

    private:
        IPhysicObject(const IPhysicObject &) {}
        void operator=(const IPhysicObject &) {}
};

#endif