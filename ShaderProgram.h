#ifndef PLANETCANNONS_SHADERPROGRAM_H
#define PLANETCANNONS_SHADERPROGRAM_H

class VertexShader;
class FragmentShader;

class ShaderProgram {
    public:
        ShaderProgram(const VertexShader &vertexShader, const FragmentShader &fragmentShader);
        ~ShaderProgram();
        void use() const;

    private:
        unsigned int m_shaderProgram;
};

#endif