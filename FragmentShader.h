#ifndef PLANETCANNONS_FRAGMENTSHADER_H
#define PLANETCANNONS_FRAGMENTSHADER_H

class ILogger;

class FragmentShader {
    public:
        FragmentShader(const ILogger &logger);
        unsigned int getId() const;

    private:
        const ILogger &m_logger;
        unsigned int m_shader;
};

#endif