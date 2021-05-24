#ifndef PLANETCANNONS_VERTEXSHADER_H
#define PLANETCANNONS_VERTEXSHADER_H

#include "Shader.h"

class VertexShader : public Shader {
    public:
        VertexShader(const ILogger &logger, const std::string &shaderFileName, IShaderRegistry &registry);
        virtual ~VertexShader();
};

#endif