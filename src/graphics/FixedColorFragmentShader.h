#ifndef PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H
#define PLANETCANNONS_FIXEDCOLORFRAGMENTSHADER_H

#include "FragmentShader.h"
#include <tuple>

class FixedColorFragmentShader : public FragmentShader {
    public:
        FixedColorFragmentShader(const ILogger &logger, const std::tuple<float, float, float, float> &color, IShaderRegistry &registry);

        void setAmbientLightStrength(float value);
        void setLightPosition(const std::tuple<float, float, float> &value);
        void setCameraPosition(const std::tuple<float, float, float> &value);
        void setSpecular(float strength, float exponent);

    protected:
        virtual void updateUniformsInternal(unsigned int shaderProgramId);

    private:
        std::tuple<float, float, float, float> m_color;
        float m_ambientLight;
        std::tuple<float, float, float> m_lightPosition;
        std::tuple<float, float, float> m_cameraPosition;
        float m_specularStrength;
        float m_specularExponent;
};

#endif