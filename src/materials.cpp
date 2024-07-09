#include "../include/models/materials.h"

struct hit_record;

bool lambertian::scatter(const ray& ray_in, const hit_record& hr, vec3& attentuation, ray& scattered) const {
            vec3 scattered_direction = hr.normal + random_unit_vector();
            point3 p = hr.p;

            // if the random unit vector is opposite to normal, we get a zero vector.
            // we prevent this w by ignoring such unit vectors.
            if (scattered_direction.near_zero()) {
                scattered_direction = hr.normal;
            }

            scattered = ray(p, scattered_direction);
            attentuation = albedo;
            return true;
        }

bool metal::scatter(const ray& ray_in, const hit_record& hr, vec3& attentuation, ray& scattered) const {

            vec3 reflected_direction = reflection(hr.normal, ray_in.get_direction());
            point3 p = hr.p;

            scattered = ray(p, reflected_direction);
            attentuation = albedo;
            return true;
        }