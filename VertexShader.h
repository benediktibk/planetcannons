#ifndef PLANETCANNONS_VERTEXSHADER_H
#define PLANETCANNONS_VERTEXSHADER_H

class ILogger;

class VertexShader {
    public:
        VertexShader(const ILogger &logger);
        unsigned int getId() const;

    private:
        const ILogger &m_logger;
        unsigned int m_shader;
};

#endif