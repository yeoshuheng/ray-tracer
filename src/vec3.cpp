#include "../include/vec3.h"

vec3::vec3(double x, double y, double z) {
    e[0] = x; e[1] = y; e[2] = z;
}

vec3::vec3() {
    e[0] = 0; e[1] = 0; e[2] = 0;
}

vec3& vec3::operator+=(const vec3& other) {
            e[0] += other.e[0]; e[1] += other.e[1]; e[2] += other.e[2];
            return *this;
        }

vec3& vec3::operator*=(double n) {
    e[0] *= n; e[1] *= n; e[2] *= n;
    return *this;
}

vec3& vec3::operator/=(double n) {
    return *this *= 1/n;
}

double vec3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

double vec3::length() const {
    return sqrt(length_squared()); }