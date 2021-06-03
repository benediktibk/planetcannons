#ifndef PLANETCANNONS_ISHADERREGISTRY_H
#define PLANETCANNONS_ISHADERREGISTRY_H

#include <tuple>
#include <glm/glm.hpp>
#include <vector>

class VertexShader;
class FragmentShader;
class TransformationVertexShader;
class FixedColorWithLightingFragmentShader;

class IShaderRegistry {
    public:
        IShaderRegistry() {}
        virtual ~IShaderRegistry() { }

        virtual void registerVertexShader(VertexShader &shader) = 0;
        virtual void registerFragmentShader(FragmentShader &shader) = 0;
        virtual void unregisterVertexShader(VertexShader &shader) = 0;
        virtual void unregisterFragmentShader(FragmentShader &shader) = 0;
        virtual const std::vector<TransformationVertexShader*>& getAllTransformationVertexShader() const = 0;
        virtual const std::vector<FixedColorWithLightingFragmentShader*>& getAllFixedColorWithLightingFragmentShader() const = 0;

    private:
        IShaderRegistry(const IShaderRegistry &) {}
        virtual void operator=(const IShaderRegistry &) {}
};

#endif