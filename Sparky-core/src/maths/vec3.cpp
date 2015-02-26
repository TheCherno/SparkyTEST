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
        *this = *this + other;
        return *this;
    }

    vec3& vec3::subtract(const vec3 &other)
    {
        *this = *this - other;
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
    
    vec3 operator+(const vec3 &left, const vec3 &right)
    {
        return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
    }

    vec3 operator-(const vec3 &left, const vec3 &right)
    {
        return vec3(left.x - right.x, left.y - right.y, left.z - right.z);
    }

    std::ostream& operator<<(std::ostream &stream, const vec3 &vector)
    {
        stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;
        return stream;
    }

} }