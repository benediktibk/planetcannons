#ifndef PLANETCANNONS_IPHYSICENGINE_H
#define PLANETCANNONS_IPHYSICENGINE_H

class IPhysicObject;

class IPhysicEngine {
    public:
        IPhysicEngine() {}
        virtual ~IPhysicEngine() {}
        virtual void execute(double timeSpan) = 0;
        virtual void add(IPhysicObject &physicObject) = 0;
        virtual void remove(IPhysicObject &physicObject) = 0;

    private:
        IPhysicEngine(const IPhysicEngine &) {}
        void operator=(const IPhysicEngine &) {}
};

#endif