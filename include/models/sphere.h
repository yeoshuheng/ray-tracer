#ifndef SPHERE_H
#define SPHERE_H

#include "../contact/hittable.h"
#include "../utils/vec3.h"

class sphere : public hittable {
    private:
        point3 center;
        double radius;
    public:
        // constructor
        sphere(point3 c, double r);

        // override hit, calculates if a hit occurs on the sphere.
        bool hit(const ray& r, interval ray_interval, hit_record& hr) const override;

        // getters
        point3 get_center() const { return center; }
        double get_radius() const { return radius; }
};

#endif