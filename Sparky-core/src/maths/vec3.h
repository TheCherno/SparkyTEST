#pragma once

#include <iostream>

namespace sparky { namespace maths {
   
    // TODO (sometime): inlining
    class vec3
    {
    public:
        float x, y, z;
    public:
        vec3();
        vec3(float value);
        vec3(float x, float y, float z);

        vec3& add(const vec3 &other);
        vec3& subtract(const vec3 &other);

        vec3& operator+=(const vec3 &other);
        vec3& operator-=(const vec3 &other);

        friend vec3& operator+(vec3 left, const vec3 &right);
        friend vec3& operator-(vec3 left, const vec3 &right);

        inline bool operator==(const vec3 &other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }
        inline bool operator!=(const vec3 &other) const
        {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream &stream, const vec3 &vector);
    };

} }
