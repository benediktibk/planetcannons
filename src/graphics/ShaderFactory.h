#ifndef PLANETCANNONS_SHADERFACTORY_H
#define PLANETCANNONS_SHADERFACTORY_H

#include "IShaderFactory.h"
#include <vector>

class ILogger;

class ShaderFactory : public IShaderFactory {
    public:
        ShaderFactory(const ILogger &logger);

        virtual TransformationVertexShader* createTransformationVertexShader();
        virtual FixedColorWithLightingFragmentShader* createFixedColorWithLightingFragmentShader(const std::tuple<double, double, double, double> &color);
        virtual FixedColorFragmentShader* createFixedColorFragmentShader(const std::tuple<double, double, double, double> &color);
        virtual ShaderProgram* createShaderProgram(VertexShader &vertexShader, FragmentShader &fragmentShader);
        virtual void registerVertexShader(VertexShader &shader);
        virtual void registerFragmentShader(FragmentShader &shader);
        virtual void unregisterVertexShader(VertexShader &shader);
        virtual void unregisterFragmentShader(FragmentShader &shader);
        virtual const std::vector<TransformationVertexShader*>& getAllTransformationVertexShader() const;
        virtual const std::vector<FixedColorWithLightingFragmentShader*>& getAllFixedColorWithLightingFragmentShader() const;

    private:
        const ILogger &m_logger;
        std::vector<TransformationVertexShader*> m_transformationVertexShader;
        std::vector<FixedColorWithLightingFragmentShader*> m_fixedColorWithLightingFragmentShader;
        std::vector<VertexShader*> m_vertexShader;
        std::vector<FragmentShader*> m_fragmentShader;
};

#endif