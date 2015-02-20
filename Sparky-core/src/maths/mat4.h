#pragma once

#include "vec3.h"

namespace sparky { namespace maths {

    // TODO (sometime): inlining

    // Column-major ordering
    // [row + column * 4]
    class mat4
    {
    private:
        float elements[4 * 4];
    public:
        mat4();
        mat4(float diagonal);
        mat4(const float *elements);
		
        mat4 translate(const vec3& vector) const;


        inline const float* to_array() const
        {
            return elements;
        }

        mat4& operator*=(const mat4 &right);
        friend mat4 operator*(const mat4 &left, const mat4 &right);

    public:
        static mat4 identity();
        static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
        static mat4 perspective(float fov, float aspect, float near, float far);
    };

}}
