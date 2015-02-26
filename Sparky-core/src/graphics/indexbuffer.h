#pragma once

#include "renderable.h"
#include <GL/glew.h>

namespace sparky { namespace graphics {

    class IndexBuffer : public Renderable
    {
    private:
        GLuint ibo;
        GLushort *indices;
        GLsizei count;
    public:
        IndexBuffer(GLushort *indices, GLsizei count);
        void compile(GLushort *indices, GLsizei count);
        void bind();
        void draw();
        void unbind();
    };

} }