#pragma once

#include <vector>

#include "renderable.h"

namespace sparky { namespace graphics {

    class Scene : public Renderable
    {
    private:
        std::vector<Renderable*> renderables;
    public:
        Scene();
        ~Scene();
        void add(Renderable *r);
        void draw();
    };
} }