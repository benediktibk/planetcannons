#ifndef PLANETCANNONS_ISHADERREGISTRY_H
#define PLANETCANNONS_ISHADERREGISTRY_H

#include <tuple>

class VertexShader;
class FragmentShader;

class IShaderRegistry {
    public:
        IShaderRegistry() {}
        virtual ~IShaderRegistry() { }

        virtual void registerVertexShader(const VertexShader &shader) = 0;
        virtual void registerFragmentShader(const FragmentShader &shader) = 0;
        virtual void unregisterVertexShader(const VertexShader &shader) = 0;
        virtual void unregisterFragmentShader(const FragmentShader &shader) = 0;

    private:
        IShaderRegistry(const IShaderRegistry &) {}
        virtual void operator=(const IShaderRegistry &) {}
};

#endif