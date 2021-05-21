#ifndef PLANETCANNONS_VERTEXSHADER_H
#define PLANETCANNONS_VERTEXSHADER_H

class VertexShader {
    public:
        VertexShader();
        unsigned int getId() const;

    private:
        unsigned int m_shader;
};

#endif