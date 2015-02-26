#pragma once

#include <GL/glew.h>

class Renderable
{
public:
    virtual void draw() = 0;
};