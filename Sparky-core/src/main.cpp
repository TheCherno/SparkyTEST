#include <iostream>
#include "input/input.h"
#include "graphics/shader.h"
#include "graphics/window.h"
#include "graphics/scene.h"
#include "graphics/primitives/rectangle.h"

#include "maths/vec3.h"

#define PAUSE system("PAUSE")

using namespace sparky;
 
int main(int argc, char **args)
{
    graphics::Window window("Sparky", 960, 540);
    Input input;
    
    graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.enable();

    maths::mat4 projection = maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniformMat4f("pr_matrix", projection);
    
    graphics::Scene scene;
    graphics::Rectangle rect(2, 2, 4, 4, 0xff);
    scene.add(&rect);

    for (int i = 0; i < 10; i++)
    {
        graphics::Rectangle *r = new graphics::Rectangle(i, i, 0.5f, 0.5f, maths::vec4(i * 20 / 255.0f, 0.0f, 0.0f, 1.0f));
        scene.add(r);
    }

    float x = 0.0f, y = 0.0f;

    while (!window.closed())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rect.set_position(x, y);
        scene.draw();
        window.update();

        x += 0.01f;
        y += 0.01f;
    }
    return 0;
}