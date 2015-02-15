#include <iostream>
#include "input/input.h"
#include "graphics/screen.h"
#include "graphics/shader.h"

int main(int argc, char **args)
{
    Window window("Sparky", 960, 540);
    Screen screen(window);
    Input input;

    Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.enable();
    float time = 0.0f;
    while (!window.closed())
    {
        shader.setUniform1f("time", time);
        screen.clear();
        screen.fill_rect(-0.5f, -0.5f, 1.0f, 1.0f);
        window.update();
        time += 0.01f;
    }
    return 0;
}