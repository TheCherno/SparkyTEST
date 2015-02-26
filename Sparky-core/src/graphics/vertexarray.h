#pragma once

#include <GL/glew.h>

namespace sparky { namespace graphics {

    class VertexArray
    {
    private:
        GLsizei vcount;
        GLuint vao, vbo;
        const GLfloat *vertices;
    public:
        VertexArray();
        VertexArray(GLfloat *vertices, GLsizei vcount);
        ~VertexArray();
        void bind();
    private:
        void compile(GLfloat *vertices, GLsizei vcount);
        GLuint compile(GLfloat *vertices, GLsizei vcount, GLfloat *normals, GLfloat *tcs);
    };

} }