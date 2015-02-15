#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA
{
    vec4 color;
} vs_out;

uniform float time;

void main()
{
    vec4 pos = position;
    pos.x += time;
    gl_Position = /*pr_matrix **/ vw_matrix * ml_matrix * pos;
    vs_out.color = color;
}