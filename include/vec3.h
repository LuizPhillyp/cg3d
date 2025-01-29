#pragma once
#include<GL/gl.h>

struct vec3 {
    GLfloat x, y, z;

    vec3(GLfloat val = 0) : x(val), y(val), z(val) {}

    vec3(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}

    vec3 operator+(vec3 vector) {
        return vec3(x + vector.x, y + vector.y, z + vector.z);
    }

    vec3 operator-(vec3 vector) {
        return vec3(x - vector.x, y - vector.y, z - vector.z);
    }

    GLfloat operator*(vec3 vector) {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    vec3 operator*(GLfloat scalar) {
        return vec3(x * scalar, y * scalar, z * scalar);
    }

    vec3 operator/(GLfloat scalar) {
        return vec3(x / scalar, y / scalar, z / scalar);
    }

    vec3 operator+=(vec3 vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        return *this;
    }

    vec3 operator-=(vec3 vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        return *this;
    }

    vec3 operator*=(GLfloat scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    vec3 operator/=(GLfloat scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    GLfloat length() {
        return inv_sqrt(x * x + y * y + z * z);
    }

    void normalize() {
        GLfloat inv_length = inv_sqrt(x * x + y * y + z * z);
        *this *= inv_length;
    }

    static vec3 normalize(vec3 vector) {
        GLfloat inv_length = inv_sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
        return vector * inv_length;
    }

    static GLfloat dot(vec3 vector1, vec3 vector2) {
        return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
    }

    static vec3 cross(vec3 vector1, vec3 vector2) {
        return vec3(
            vector1.y * vector2.z - vector1.z * vector2.y,
            vector1.z * vector2.x - vector1.x * vector2.z,
            vector1.x * vector2.y - vector1.y * vector2.x
        );
    }

private:
    static GLfloat inv_sqrt(float number) {
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y = number;
        i = *(long *)&y;  // Evil floating point bit level hacking
        i = 0x5f3759df - (i >> 1); // what the fuck?
        y = *(GLfloat *)&i;
        y = y * (threehalfs - (x2 * y * y));  // 1st iteration
        return y;
    }
};