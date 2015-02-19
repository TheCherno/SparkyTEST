#include <iostream>
#include "input/input.h"
#include "graphics/screen.h"
#include "graphics/shader.h"

#include "maths/vec3.h"

#define PAUSE system("PAUSE")

// TODO: NAMESPACING!!!
 
int main(int argc, char **args)
{
    Window window("Sparky", 960, 540);
    Screen screen(window);
    Input input;
    
    Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.enable();

    using namespace sparky::maths;
    mat4 projection = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniformMat4f("pr_matrix", projection);
    
    float time = 0.0f;
    while (!window.closed())
    {
        shader.setUniform1f("time", time);
        screen.clear();
        screen.fill_rect(0.0f, 0.0f, 2.0f, 2.0f);
        window.update();
        time += 0.01f;
    }
    PAUSE;
    return 0;
}