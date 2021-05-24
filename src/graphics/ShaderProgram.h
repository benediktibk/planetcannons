#ifndef PLANETCANNONS_SHADERPROGRAM_H
#define PLANETCANNONS_SHADERPROGRAM_H

class VertexShader;
class FragmentShader;
class ILogger;

class ShaderProgram {
    public:
        ShaderProgram(const ILogger &logger, VertexShader &vertexShader, FragmentShader &fragmentShader);
        ~ShaderProgram();
        void use() const;

    private:
        const ILogger &m_logger;
        unsigned int m_shaderProgram;
        VertexShader &m_vertexShader;
        FragmentShader &m_fragmentShader;
};

#endif