#include "scene.h"

namespace sparky { namespace graphics {

    Scene::Scene()
    {

    }

    Scene::~Scene()
    {

    }

    void Scene::add(Renderable *r)
    {
        renderables.push_back(r);
    }

    void Scene::draw()
    {
        for (Renderable *r : renderables)
        {
            r->draw();
        }
    }

} }