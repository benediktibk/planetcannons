#include "FixedColorFragmentShader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

FixedColorFragmentShader::FixedColorFragmentShader(const ILogger &logger, const std::tuple<float, float, float, float> &color) :
    FragmentShader(logger, "fixedColor.frag"),
    m_color(color) { 
}

void FixedColorFragmentShader::initializeUniforms() {
    unsigned int inputColorLocation = glGetUniformLocation(getId(), "inputColor");
    float values[] = {
        std::get<0>(m_color),
        std::get<1>(m_color),
        std::get<2>(m_color),
        std::get<3>(m_color)
    };
    glUniform4fv(
        inputColorLocation,
        1,
        values);
}