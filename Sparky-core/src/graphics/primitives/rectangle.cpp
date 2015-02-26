#include "rectangle.h"

namespace sparky { namespace graphics {

    Rectangle::Rectangle(float x, float y, float width, float height)
    {
        set_position(x, y);
        this->width = width;
        this->height = height;
        set_color(maths::vec4(0.5f, 0.0f, 0.5f, 1.0f));
        compile();
    }

    Rectangle::Rectangle(float x, float y, float width, float height, int hex)
    {
        set_position(x, y);
        this->width = width;
        this->height = height;
        set_color(hex);
        compile();
    }

    Rectangle::Rectangle(float x, float y, float width, float height, maths::vec4 color)
    {
        set_position(x, y);
        this->width = width;
        this->height = height;
        set_color(color);
        compile();
    }

    Rectangle::~Rectangle()
    {
        delete vao;
        delete ibo;
    }

    void Rectangle::compile()
    {
        GLfloat vertices[] =
        {
            0.0f, 0.0f, 0.0f,
            0.0f, height, 0.0f,
            width, height, 0.0f,
            width, 0.0f, 0.0f
        };

        GLushort indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

        vao = new VertexArray(vertices, 4 * 3);
        ibo = new IndexBuffer(indices, 6);
    }

    void Rectangle::set_position(float x, float y)
    {
        this->x = x;
        this->y = y;
        ml_matrix = maths::mat4::identity().translate(maths::vec3(x, y, 0.0f));
    }

    void Rectangle::set_color(int hex)
    {
        float a = ((hex & 0xff000000) >> 24) / 255.0f;
        float r = ((hex & 0xff0000) >> 16) / 255.0f;
        float g = ((hex & 0xff00) >> 8) / 255.0f;
        float b = ((hex & 0xff) >> 0) / 255.0f;
        color = maths::vec4(r, g, b, a);
    }

    void Rectangle::set_color(maths::vec4 color)
    {
        this->color = color;
    }

    void Rectangle::draw()
    {
        Shader::CURRENT->setUniformMat4f("ml_matrix", ml_matrix);
        Shader::CURRENT->setUniform4f("ml_color", color);
        vao->bind();
        ibo->draw();
    }

} }
