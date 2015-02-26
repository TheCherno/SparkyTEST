#include "vertexarray.h"

namespace sparky { namespace graphics {

    VertexArray::VertexArray()
    {

    }

    VertexArray::VertexArray(GLfloat *vertices, GLsizei vcount)
    {
        this->vcount = vcount;
        compile(vertices, vcount);
    }

    VertexArray::~VertexArray()
    {

    }

    void VertexArray::compile(GLfloat *vertices, GLsizei vcount)
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vcount * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void VertexArray::bind()
    {
        glBindVertexArray(vao);
    }


} }