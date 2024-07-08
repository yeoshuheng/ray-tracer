#ifndef RAY_TRACE_H
#define RAY_TRACE_H

#include "utils/vec3.h"
#include "utils/ray.h"
#include "utils/color.h"

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

#define PI 3.1415926535897932385

// util functions for anti-aliasing

inline double random_double() {
    return std::rand() / (RAND_MAX + 1.);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

inline double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

#endif