#ifndef PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H
#define PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H

#include "FragmentShader.h"
#include <tuple>

class FixedColorFragmentShader : public FragmentShader {
    public:
        FixedColorFragmentShader(const ILogger &logger, const std::tuple<float, float, float, float> &color);
        virtual void initializeUniforms(unsigned int shaderProgramId);

    private:
        std::tuple<float, float, float, float> m_color;
};

#endif