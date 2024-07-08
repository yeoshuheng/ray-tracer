#ifndef COLOR_H
#define COLOR_H

#define RGB 255.999
#define INF std::numeric_limits<double>::infinity()

#include "../contact/hittable.h"
#include<iostream>

void write_color(std::ostream& out, const vec3& pixel) {

    static const interval intensity = interval(0.0, 0.999);

    // convert [0, 1] to [0, 255]
    auto r = pixel.getX(); auto g = pixel.getY(); auto b = pixel.getZ();

    // clamp intensity
    int rbyte = int(RGB * intensity.clamp(r)); 
    int gbyte = int(RGB * intensity.clamp(g)); 
    int bbyte = int(RGB * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

vec3 ray_color(const ray& r, const hittable& world) {

    hit_record hr;

    // if we hit, we use normal to color instead.
    // normal shows us the direction of reflection (where light bounces back to camera)
    
    if (world.hit(r, interval(0, INF), hr)) {
        return 0.5 * (hr.normal + vec3(1., 1., 1.)); 
    }

    // lerp coloring: linear interpolation to get background

    vec3 unit_direction = unit_vector(r.get_direction());
    auto a = 0.5 * (unit_direction.getY() + 1.0);
    return (1.0 - a)* vec3(1.0, 1.0, 1.0) + a * vec3(0.5, 0.7, 1.0);

}

#endif