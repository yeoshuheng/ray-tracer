#ifndef HITTABLE_H
#define HITTABLE_H

#include "../utils/vec3.h"
#include "../utils/ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;

        // track the face in which the ray hits the object
        bool front_face;

        void set_face_direction(const ray& r, const vec3& outward_normal) {
            // NOTE outward_normal is already made to unit length due to division by radius.

            // if ray direction and normal are in opposite directions,
            // the ray is hitting the outside of the object.
            front_face = dot(r.get_direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        };
};

class hittable {
    public:
        virtual ~hittable() = default;

        // tracks if an object has been 'hit' by a ray, defaults to false.
        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& hr) const = 0;
};

#endif