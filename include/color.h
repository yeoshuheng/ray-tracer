#ifndef COLOR_H
#define COLOR_H

#define RGB 255.999

#include "vec3.h"
#include "ray.h"
#include<iostream>

void write_color(std::ostream& out, const vec3& pixel) {

    // convert [0, 1] to [0, 255]
    auto r = pixel.getX(); auto g = pixel.getY(); auto b = pixel.getZ();
    int rbyte = int(RGB * r); int gbyte = int(RGB * g); int bbyte = int(RGB * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

vec3 ray_color(const ray& r) {

    // lerp coloring: linear interpolation

    vec3 unit_direction = unit_vector(r.get_direction());
    auto a = 0.5*(unit_direction.getY() + 1.0);
    return (1.0-a)* vec3(1.0, 1.0, 1.0) + a * vec3(0.5, 0.7, 1.0);

}

#endif