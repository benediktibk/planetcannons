#ifndef PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H
#define PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H

#include "FragmentShader.h"

class FixedColorFragmentShader : public FragmentShader {
    public:
        FixedColorFragmentShader(const ILogger &logger) :
            FragmentShader(logger, "fixedColor.frag") { }
};

#endif