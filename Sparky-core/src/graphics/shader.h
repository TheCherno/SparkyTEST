#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <GL/glew.h>

#include "../maths/maths.h"
#include "../utils/fileutils.h"

namespace sparky { namespace graphics {

    class Shader
    {
    public:
        static Shader *CURRENT;
    private:
        GLuint shader;
        std::map<const GLchar*, GLint> locationCache;
    public:
        Shader(const char *vert_path, const char *frag_path);
        ~Shader();
        GLint get_uniform(const GLchar *name);

        void setUniform1f(const GLchar *name, GLfloat value);
        void setUniform2f(const GLchar *name, GLfloat x, GLfloat y);
        void setUniform3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z);
        void setUniform3f(const GLchar *name, const sparky::maths::vec3 &vector);
        void setUniform4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
        void setUniform4f(const GLchar *name, const sparky::maths::vec4 &vector);

        void setUniformMat4f(const GLchar *name, const sparky::maths::mat4 &matrix);

        void enable() const;
        void disable() const;
    private:
        GLuint load(const char *vert_path, const char *frag_path);
    };

} }