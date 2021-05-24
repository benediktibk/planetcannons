#include "FixedColorFragmentShader.h"
#include <GL/glew.h>

FixedColorFragmentShader::FixedColorFragmentShader(const ILogger &logger, const std::tuple<float, float, float, float> &color) :
    FragmentShader(logger, "fixedColor.frag"),
    m_color(color) { 
}

void FixedColorFragmentShader::updateUniformsInternal(unsigned int shaderProgramId) {    
    float values[] = {
        std::get<0>(m_color),
        std::get<1>(m_color),
        std::get<2>(m_color),
        std::get<3>(m_color)
    };
    
    unsigned int inputColorLocation = glGetUniformLocation(shaderProgramId, "inputColor");    
    glUniform4fv(inputColorLocation, 1, values);
}