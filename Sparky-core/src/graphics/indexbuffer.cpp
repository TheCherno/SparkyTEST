#include "indexbuffer.h"

namespace sparky { namespace graphics {

    IndexBuffer::IndexBuffer(GLushort *indices, GLsizei count)
    {
        this->indices = indices;
        this->count = count;
        compile(indices, count);
    }


    void IndexBuffer::compile(GLushort *indices, GLsizei count)
    {
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBuffer::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    }

    void IndexBuffer::draw()
    {
        bind();
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, nullptr);
    }

    void IndexBuffer::unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
}