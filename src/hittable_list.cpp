#include "../include/contact/hittable_list.h"

void hittable_list::add(shared_ptr<hittable> obj) { objects.push_back(obj); }

bool hittable_list::hit(
    const ray& r, 
    interval ray_interval,
    hit_record& hr) const {

    hit_record temp_hr;
    bool has_hit_something = false;
    auto closest_so_far = ray_interval.max;

    // ensure we don't modify the objects.
    for (const auto& obj : objects) {
        if (obj->hit(r, interval(ray_interval.min, closest_so_far), temp_hr)) {
            has_hit_something = true;
            closest_so_far = temp_hr.t;
            hr = temp_hr; // swap our hit record
        }
    }

    return has_hit_something;
};
