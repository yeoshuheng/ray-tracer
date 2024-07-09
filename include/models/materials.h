#ifndef MATERIAL_H
#define MATERIAL_H

#include "../contact/hittable.h"

class material {
    public:
        virtual ~material() = default;

        // scatters a ray, attentuation represents how much the ray should be scattered.
        virtual bool scatter(const ray& ray_in, const hit_record& hr, vec3& attentuation, ray& scattered) const {
            return false;
        }
};

class lambertian : public material {
    private:
        vec3 albedo;

    public:
        // constructor
        //albedo represents the fractional reflectance of the object.
        lambertian(const vec3& a) {
            albedo = a;
        };

        bool scatter(const ray& ray_in, const hit_record& hr, vec3& attentuation, ray& scattered) const override;
};

class metal : public material {
    private:
        vec3 albedo;

    public:
        // constructor
        //albedo represents the fractional reflectance of the object.
        metal(const vec3& a) {
            albedo = a;
        };

        bool scatter(const ray& ray_in, const hit_record& hr, vec3& attentuation, ray& scattered) const override;
};


#endif