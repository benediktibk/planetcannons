#ifndef PLANETCANNONS_TRANSFORMATIONVERTEXSHADER_H
#define PLANETCANNONS_TRANSFORMATIONVERTEXSHADER_H

#include "VertexShader.h"

class TransformationVertexShader : public VertexShader {
    public:
        TransformationVertexShader(const ILogger &logger) :
            VertexShader(logger, "transformation.vert") { }
};

#endif