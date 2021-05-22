#ifndef PLANETCANNONS_SHADER_H
#define PLANETCANNONS_SHADER_H

#include <string>

class ILogger;

class Shader {
    public:
        Shader(const ILogger &logger, const std::string &shaderFileName, unsigned int shaderType);
        unsigned int getId() const;
        virtual ~Shader();
        bool isInitialized() const;
        void updateUniforms(unsigned int shaderProgramId);

    protected:
        virtual void updateUniformsInternal(unsigned int shaderProgramId);
        void markUniformsUpdateNecessary();

    private:
        Shader(const Shader &rhs);
        void operator=(const Shader &) {}

    protected:
        const ILogger &m_logger;

    private:
        unsigned int m_shader;
        bool m_initialized;
        bool m_uniformsUpdateNecessary;
};

#endif