#ifndef PLANETCANNONS_FRAGMENTSHADER_H
#define PLANETCANNONS_FRAGMENTSHADER_H

class FragmentShader {
    public:
        FragmentShader();
        unsigned int getId() const;

    private:
        unsigned int m_shader;
};

#endif