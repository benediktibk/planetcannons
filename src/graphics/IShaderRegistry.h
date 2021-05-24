#ifndef PLANETCANNONS_ISHADERREGISTRY_H
#define PLANETCANNONS_ISHADERREGISTRY_H

#include <tuple>
#include <glm/glm.hpp>

class VertexShader;
class FragmentShader;

class IShaderRegistry {
    public:
        IShaderRegistry() {}
        virtual ~IShaderRegistry() { }

        virtual void registerVertexShader(VertexShader &shader) = 0;
        virtual void registerFragmentShader(FragmentShader &shader) = 0;
        virtual void unregisterVertexShader(VertexShader &shader) = 0;
        virtual void unregisterFragmentShader(FragmentShader &shader) = 0;
        virtual void updateGlobalTransformations(const glm::mat4 &transformationWorldToView, const glm::mat4 &transformationViewToPerspective) = 0;

    private:
        IShaderRegistry(const IShaderRegistry &) {}
        virtual void operator=(const IShaderRegistry &) {}
};

#endif