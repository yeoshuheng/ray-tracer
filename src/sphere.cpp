#include "../include/models/sphere.h"
#include "../include/contact/hittable.h"

sphere::sphere(point3 c, double r, shared_ptr<material> mat) {
    center = c; radius = fmax(0, r); mat = mat;
}

// given ray P(t), and sphere Q, we want to find if there is a t
// such that P(t) lies on Q.
// we form a quadratic equation wrt to t and solve for roots of t.
// we let h = -b/2 = d (Q-C) to shorten the quadratic, given the below.

bool sphere::hit(
    const ray& r, 
    interval ray_interval, 
    hit_record& hr) const {
    
    double radius = this->get_radius();  point3 center = this->get_center();

    // calculate variables to solve crossing btw ray & sphere
    vec3 origin_to_center = center - r.get_origin();
    auto a = r.get_direction().length_squared();
    auto h = dot(r.get_direction(), origin_to_center);
    auto c = origin_to_center.length_squared() - radius * radius;
    

    // calculate discriminants
    auto discriminant = h * h - a * c;
    if (discriminant < 0) {return false;}
    
    auto discriminant_sqrt = sqrt(discriminant);
    
    // solve for the t that results in a hit that is constrainted btw tmin, tmax.
    auto root = (h - discriminant_sqrt) / a;

    // we only want to render a color if the current value of t is greater than t_min
    // or if it is lesser than t_max. If it is neither we ignore.
    if (!ray_interval.surrounds(root)) {
        root = (h + discriminant_sqrt) / a; // check if other answer is valid.
         if (!ray_interval.surrounds(root)) {
            return false;
         }
    }

    // update hit record
    hr.t = root;
    point3 hit_at = r.at(root);
    hr.p = hit_at;
    hr.mat = mat;   
    
    // division by radius converts the surface normal to unit length.
    vec3 outward_normal = (hit_at - center) / radius;
    hr.set_face_direction(r, outward_normal);
    
    return true;
}