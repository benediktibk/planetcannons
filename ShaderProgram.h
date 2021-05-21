#ifndef PLANETCANNONS_SHADERPROGRAM_H
#define PLANETCANNONS_SHADERPROGRAM_H

class VertexShader;
class FragmentShader;
class ILogger;

class ShaderProgram {
    public:
        ShaderProgram(const ILogger &logger, const VertexShader &vertexShader, const FragmentShader &fragmentShader);
        ~ShaderProgram();
        void use() const;

    private:
        const ILogger &m_logger;
        unsigned int m_shaderProgram;
};

#endif