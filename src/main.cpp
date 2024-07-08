#include<iostream>

#include "../include/color.h"
#include "../include/vec3.h"
#include "../include/camera.h"
#include "../include/ray.h"


using namespace std;

int main() {

    int width = 400;

    double aspect_ratio = 16. / 9.;

    int height = int(width / aspect_ratio);

    camera cam = camera(width, height);

    cout << "P3\n" << width << " " << height << "\n255\n";


    point3 center = cam.get_center();
    point3 pixel00 = cam.get_pixel_00();

    vec3 delta_u = cam.get_delta_u();
    vec3 delta_v = cam.get_delta_v();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            point3 pixel_center = pixel00 + (j * delta_u) 
                + (i * delta_v);

            vec3 ray_dir = pixel_center - center;

            ray r = ray(center, ray_dir);
            
            vec3 pixel_color = ray_color(r);
            
            write_color(std::cout, pixel_color);
        } 
    }
}