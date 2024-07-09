#ifndef COLOR_H
#define COLOR_H

#define RGB 255.999
#define INF std::numeric_limits<double>::infinity()

#include "../contact/hittable_list.h"

#include<iostream>

// gamma correction
double linear_to_gamma(double linear_component) {
    if (linear_component > 0) {
        return sqrt(linear_component);
    }
    return 0;
}


void write_color(std::ostream& out, const vec3& pixel) {

    static const interval intensity = interval(0.0, 0.999);

    // convert [0, 1] to [0, 255]
    auto r = pixel.getX(); auto g = pixel.getY(); auto b = pixel.getZ();
    r = linear_to_gamma(r); g = linear_to_gamma(g); b = linear_to_gamma(b);

    // clamp intensity
    int rbyte = int(RGB * intensity.clamp(r)); 
    int gbyte = int(RGB * intensity.clamp(g)); 
    int bbyte = int(RGB * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif