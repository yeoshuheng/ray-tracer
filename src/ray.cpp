#include "../include/ray.h"

ray::ray() {}

ray::ray(point3& ori, vec3& dir) {
    origin = ori; direction = dir;
}

point3 ray::at(double n) const {
    return origin + n * direction;
}