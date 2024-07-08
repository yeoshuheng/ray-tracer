#include<iostream>

#include "../include/ray_trace.h"
#include "../include/contact/hittable_list.h"

#include "../include/models/camera.h"
#include "../include/models/sphere.h"


using namespace std;

int main() {

    // create world
    hittable_list world;


    // add ground
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // add sphere
    world.add(make_shared<sphere>(point3(0., 0., -1), 0.5));

    // create camera

    int width = 400;

    double aspect_ratio = 16.0 / 9.0;

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
            
            vec3 pixel_color = ray_color(r, world);
            
            write_color(std::cout, pixel_color);
        } 
    }
}