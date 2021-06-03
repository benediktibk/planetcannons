#include "FixedColorFragmentShader.h"
#include <GL/glew.h>

FixedColorFragmentShader::FixedColorFragmentShader(const ILogger &logger, const std::tuple<float, float, float, float> &color, IShaderRegistry &registry) :
    FragmentShader(logger, "fixedColor.frag", registry),
    m_color(color),
    m_ambientLight(1),
    m_lightPosition(std::make_tuple<float, float, float>(0, 0, 0)),
    m_cameraPosition(std::make_tuple<float, float, float>(0, 0, 0)),
    m_specularStrength(0),
    m_specularExponent(1) { 
}

void FixedColorFragmentShader::updateUniformsInternal(unsigned int shaderProgramId) {    
    float inputColorValues[] = {
        std::get<0>(m_color),
        std::get<1>(m_color),
        std::get<2>(m_color),
        std::get<3>(m_color)
    };
    float lightPositionValues[] = {
        std::get<0>(m_lightPosition),
        std::get<1>(m_lightPosition),
        std::get<2>(m_lightPosition)
    };
    float cameraPositionValues[] = {
        std::get<0>(m_cameraPosition),
        std::get<1>(m_cameraPosition),
        std::get<2>(m_cameraPosition)
    };
    
    unsigned int inputColorLocation = glGetUniformLocation(shaderProgramId, "inputColor");    
    glUniform4fv(inputColorLocation, 1, inputColorValues);
    unsigned int ambientLightLocation = glGetUniformLocation(shaderProgramId, "ambientLight");    
    glUniform1f(ambientLightLocation, m_ambientLight);
    unsigned int lightPositionLocation = glGetUniformLocation(shaderProgramId, "lightPosition");    
    glUniform4fv(lightPositionLocation, 1, lightPositionValues);
    unsigned int cameraPositionLocation = glGetUniformLocation(shaderProgramId, "cameraPosition");    
    glUniform4fv(cameraPositionLocation, 1, cameraPositionValues);
    unsigned int specularStrengthLocation = glGetUniformLocation(shaderProgramId, "specularStrength");    
    glUniform1f(specularStrengthLocation, m_specularStrength);
    unsigned int specularExponentLocation = glGetUniformLocation(shaderProgramId, "specularExponent");    
    glUniform1f(specularExponentLocation, m_specularExponent);
}

void FixedColorFragmentShader::setAmbientLightStrength(float value) {
    m_ambientLight = value;
    markUniformsUpdateNecessary();
}

void FixedColorFragmentShader::setLightPosition(const std::tuple<float, float, float> &value) {
    m_lightPosition = value;
    markUniformsUpdateNecessary();
}

void FixedColorFragmentShader::setCameraPosition(const std::tuple<float, float, float> &value) {
    m_cameraPosition = value;
    markUniformsUpdateNecessary();
}

void FixedColorFragmentShader::setSpecular(float strength, float exponent) {
    m_specularStrength = strength;
    m_specularExponent = exponent;
    markUniformsUpdateNecessary();
}