#pragma once

#include <iostream>

namespace sparky { namespace maths {
   
    // TODO (sometime): inlining
    class vec4
    {
    public:
        float x, y, z, w;
    public:
        vec4();
        vec4(float value);
        vec4(float x, float y, float z, float w);

        vec4& add(const vec4 &other);
        vec4& subtract(const vec4 &other);

        vec4& operator+=(const vec4 &other);
        vec4& operator-=(const vec4 &other);

        friend vec4& operator+(vec4 left, const vec4 &right);
        friend vec4& operator-(vec4 left, const vec4 &right);

        inline bool operator==(const vec4 &other) const
        {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }
        inline bool operator!=(const vec4 &other) const
        {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream &stream, const vec4 &vector);
    };

} }
