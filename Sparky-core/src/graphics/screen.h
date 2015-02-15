#pragma once

#include <iostream>
#include "window.h"

class Screen
{
private:
    Window &window;
public:
    Screen(Window &window);
    ~Screen();
    void fill_rect(float x, float y, float width, float height);
    void clear();
};