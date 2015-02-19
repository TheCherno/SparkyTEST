#include "vec3.h"

namespace sparky { namespace maths {

    vec3::vec3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    vec3::vec3(float value)
    {
        x = value;
        y = value;
        z = value;
    }

    vec3::vec3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3& vec3::add(const vec3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    vec3& vec3::subtract(const vec3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    vec3& vec3::operator += (const vec3 &other)
    {
        return add(other);
    }

    vec3& vec3::operator -= (const vec3 &other)
    {
        return subtract(other);
    }

    vec3& operator+(vec3 left, const vec3 &right)
    {
        return left += right;
    }

    vec3& operator-(vec3 left, const vec3 &right)
    {
        return left -= right;
    }

    std::ostream& operator<<(std::ostream &stream, const vec3 &vector)
    {
        stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
        return stream;
    }

} }