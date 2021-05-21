#ifndef PLANETCANNONS_SHADER_H
#define PLANETCANNONS_SHADER_H

#include <string>

class ILogger;

class Shader {
    public:
        Shader(const ILogger &logger, const std::string &code, unsigned int shaderType);
        unsigned int getId() const;
        virtual ~Shader();

    private:
        Shader(const Shader &rhs);
        void operator=(const Shader &) {}

    private:
        const ILogger &m_logger;
        unsigned int m_shader;
};

#endif