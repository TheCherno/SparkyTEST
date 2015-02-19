#version 330 core

layout (location = 0) out vec4 color;

in DATA
{
    vec4 color;
} fs_in;

void main()
{
    color = vec4(gl_FragCoord.x / 960.0 * fs_in.color.x, gl_FragCoord.y / 540.0 * fs_in.color.y, fs_in.color.z, 1.0f);
}