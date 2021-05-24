#ifndef PLANETCANNONS_SHADERFACTORY_H
#define PLANETCANNONS_SHADERFACTORY_H

#include "IShaderFactory.h"
#include <vector>

class ILogger;

class ShaderFactory : public IShaderFactory {
    public:
        ShaderFactory(const ILogger &logger);

        virtual TransformationVertexShader* createTransformationVertexShader();
        virtual FixedColorFragmentShader* createFixedColorFragmentShader(const std::tuple<double, double, double, double> &color);
        virtual ShaderProgram* createShaderProgram(VertexShader &vertexShader, FragmentShader &fragmentShader);
        virtual void registerVertexShader(const VertexShader &shader);
        virtual void registerFragmentShader(const FragmentShader &shader);
        virtual void unregisterVertexShader(const VertexShader &shader);
        virtual void unregisterFragmentShader(const FragmentShader &shader);

    private:
        const ILogger &m_logger;
        std::vector<const TransformationVertexShader*> m_transformationVertexShader;
        std::vector<const VertexShader*> m_vertexShader;
        std::vector<const FragmentShader*> m_fragmentShader;
};

#endif