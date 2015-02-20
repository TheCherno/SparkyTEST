#include "mat4.h"

namespace sparky { namespace maths {

    mat4::mat4()
    {
        for (int i = 0; i < 4 * 4; i++)
            elements[i] = 0.0f;
    }

    mat4::mat4(float diagonal)
    {
        elements[0 + 0 * 4] = diagonal;
        elements[1 + 0 * 4] = 0.0f;
        elements[2 + 0 * 4] = 0.0f;
        elements[3 + 0 * 4] = 0.0f;

        elements[0 + 1 * 4] = 0.0f;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 1 * 4] = 0.0f;
        elements[3 + 1 * 4] = 0.0f;

        elements[0 + 2 * 4] = 0.0f;
        elements[1 + 2 * 4] = 0.0f;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 2 * 4] = 0.0f;

        elements[0 + 3 * 4] = 0.0f;
        elements[1 + 3 * 4] = 0.0f;
        elements[2 + 3 * 4] = 0.0f;
        elements[3 + 3 * 4] = diagonal;
    }

    mat4::mat4(const float *elements)
    {
        for (int i = 0; i < 4 * 4; i++)
            this->elements[i] = elements[i];
    }
    
    mat4 mat4::translate(const vec3& vector) const
    {
        mat4 translation(1.0f);
        translation.elements[0 + 3 * 4] = vector.x;
        translation.elements[1 + 3 * 4] = vector.y;
        translation.elements[2 + 3 * 4] = vector.z;
        return *this * translation;
    }


    mat4 mat4::identity()
    {
        return mat4(1.0f);
    }

    mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        mat4 result(1.0f); 

        result.elements[0 + 0 * 4] = 2.0f / (right - left);

        result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

        result.elements[2 + 2 * 4] = 2.0f / (near - far);

        result.elements[0 + 3 * 4] = (left + right) / (left - right);
        result.elements[1 + 3 * 4] = (bottom + right) / (bottom - top);
        result.elements[2 + 3 * 4] = (far + near) / (far - near);

        return result;
    }
    mat4 mat4::perspective(float fov, float aspect, float near, float far)
    {
        // TODO: IMPLEMENT!
        return mat4(1.0f);
    }

    mat4& mat4::operator*=(const mat4 &right)
    {
        *this = *this * right;
        return *this;
    }

    mat4 operator*(const mat4 &left, const mat4 &right)
    {
        mat4 result;

        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                float sum = 0.0f;
                for (int i = 0; i < 4; i++)
                {
                    sum += left.elements[x + i * 4] * right.elements[i + y * 4];
                }
                result.elements[y + x * 4] = sum;
            }
        }

        return result;
    }

} }