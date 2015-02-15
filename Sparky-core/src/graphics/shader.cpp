#include "shader.h"

Shader::Shader(const char *vert_path, const char *frag_path)
{
    shader = load(FileUtils::read_file(vert_path).c_str(), FileUtils::read_file(frag_path).c_str());
}

Shader::~Shader()
{
    glDeleteProgram(shader);
}

GLuint Shader::load(const char *vert_path, const char *frag_path)
{
    GLuint program = glCreateProgram();
    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vert, 1, &vert_path, NULL);
    glCompileShader(vert);
    GLint result;
    glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(vert, length, &length, &error[0]);
        std::cerr << &error[0] << std::endl;
        glDeleteShader(vert);
        throw new std::runtime_error("Could not compile vertex shader!");
    }

    glShaderSource(frag, 1, &frag_path, NULL);
    glCompileShader(frag);
    glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> error(length);
        glGetShaderInfoLog(frag, length, &length, &error[0]);
        std::cerr << &error[0] << std::endl;
        glDeleteShader(frag);
        throw new std::runtime_error("Could not compile fragment shader!");
    }

    glAttachShader(program, vert);
    glAttachShader(program, frag);

    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vert);
    glDeleteShader(frag);

    return program;
}

void Shader::enable() const
{
    glUseProgram(shader);
}

void Shader::disable() const
{
    glUseProgram(0);
}
