#ifndef PLANETCANNONS_FRAGMENTSHADER_H
#define PLANETCANNONS_FRAGMENTSHADER_H

#include "Shader.h"

class FragmentShader : public Shader {
    public:
        FragmentShader(const ILogger &logger, const std::string &shaderFileName, IShaderRegistry &registry);
        virtual ~FragmentShader();
};

#endif