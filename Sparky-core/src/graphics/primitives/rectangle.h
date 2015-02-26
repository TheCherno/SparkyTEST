#pragma once

#include "../renderable.h"
#include "../vertexarray.h"
#include "../indexbuffer.h"
#include "../shader.h"
#include "../../maths/mat4.h"

namespace sparky { namespace graphics {

    class Rectangle : public Renderable
    {
    private:
        maths::mat4 ml_matrix;
        maths::vec4 color;
        VertexArray *vao;
        IndexBuffer *ibo;
        float x, y;
        float width, height;
    public:
        Rectangle(float x, float y, float width, float height);
        Rectangle(float x, float y, float width, float height, int hex);
        Rectangle(float x, float y, float width, float height, maths::vec4 color);
        ~Rectangle();
        void set_position(float x, float y);
        void set_color(int hex);
        void set_color(maths::vec4 color);
        void draw() override;
    private:
        void compile();
    };


} }
