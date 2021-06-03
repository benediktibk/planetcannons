#ifndef PLANETCANNONS_IGRAPHICENGINE_H
#define PLANETCANNONS_IGRAPHICENGINE_H

class IGraphicObject;
class IShaderFactory;
class LinearAlgebraVector;

class IGraphicEngine {
    public:
        virtual void update() = 0;
        virtual bool closeRequested() = 0;
        virtual void add(IGraphicObject &graphicObject) = 0;
        virtual void remove(IGraphicObject &graphicObject) = 0;
        virtual bool keyPressed(unsigned int keyType) = 0;
        virtual IShaderFactory& getShaderFactory() = 0;
        virtual void setCamera(const LinearAlgebraVector &position, const LinearAlgebraVector &target, double fieldOfView, double aspectRatio, double nearPlane, double farPlane) = 0;
        virtual void configureLighting(const LinearAlgebraVector &lightPosition, float ambientLightStrength, float specularStrength, float specularExponent) = 0;

        IGraphicEngine() {};
        ~IGraphicEngine() {};

    private:
        IGraphicEngine(const IGraphicEngine&) {}
        void operator=(const IGraphicEngine&) {}
};

#endif