#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
};

class hittable {
    public:
        virtual ~hittable() = default;

        // tracks if an object has been 'hit' by a ray, defaults to false.
        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& hr) const = 0;
};

#endif