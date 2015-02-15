#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../utils/fileutils.h"

class Shader
{
private:
    GLuint shader;
public:
    Shader(const char *vert_path, const char *frag_path);
    ~Shader();
    void enable() const;
    void disable() const;
private:
    GLuint load(const char *vert_path, const char *frag_path);
};