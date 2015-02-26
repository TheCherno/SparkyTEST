#include "vec4.h"

namespace sparky { namespace maths {

    vec4::vec4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    vec4::vec4(float value)
    {
        x = value;
        y = value;
        z = value;
        w = value;
    }

    vec4::vec4(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    vec4& vec4::add(const vec4 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    vec4& vec4::subtract(const vec4 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }
    vec4& vec4::operator += (const vec4 &other)
    {
        return add(other);
    }

    vec4& vec4::operator -= (const vec4 &other)
    {
        return subtract(other);
    }

    vec4& operator+(vec4 left, const vec4 &right)
    {
        return left += right;
    }

    vec4& operator-(vec4 left, const vec4 &right)
    {
        return left -= right;
    }

    std::ostream& operator<<(std::ostream &stream, const vec4 &vector)
    {
        stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")" << std::endl;
        return stream;
    }

} }