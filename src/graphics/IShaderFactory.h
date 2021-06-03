#ifndef PLANETCANNONS_ISHADERFACTORY_H
#define PLANETCANNONS_ISHADERFACTORY_H

#include "IShaderRegistry.h"

class ShaderProgram;
class TransformationVertexShader;
class FixedColorWithLightingFragmentShader;
class FixedColorFragmentShader;

class IShaderFactory : public IShaderRegistry {
    public:
        IShaderFactory() : IShaderRegistry() {}
        virtual ~IShaderFactory() { }

        virtual TransformationVertexShader* createTransformationVertexShader() = 0;
        virtual FixedColorWithLightingFragmentShader* createFixedColorWithLightingFragmentShader(const std::tuple<double, double, double, double> &color) = 0;
        virtual FixedColorFragmentShader* createFixedColorFragmentShader(const std::tuple<double, double, double, double> &color) = 0;
        virtual ShaderProgram* createShaderProgram(VertexShader &vertexShader, FragmentShader &fragmentShader) = 0;

    private:
        IShaderFactory(const IShaderFactory &) : IShaderRegistry() {}
        virtual void operator=(const IShaderFactory &) {}
};

#endif