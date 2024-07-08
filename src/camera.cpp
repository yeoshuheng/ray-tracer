#include "../include/models/camera.h"
#include "../include/utils/color.h"

camera::camera(int iw, double ar) {

    aspect_ratio = ar;
    image_width = iw;

    int ih = int(iw / ar);

    image_height = (ih < 1) ? 1 : ih;

    viewport_width = viewport_height * (double(image_width) / image_height);
    
    viewport_u = vec3(viewport_width, 0, 0);
    viewport_v = vec3(0, -viewport_height, 0);

    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;
    
    viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void camera::render(const hittable& world) {

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    point3 center = get_center();
    point3 pixel00 = get_pixel_00();

    vec3 delta_u = get_delta_u();
    vec3 delta_v = get_delta_v();

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {

            point3 pixel_center = pixel00 + (j * delta_u) 
                + (i * delta_v);

            vec3 ray_dir = pixel_center - center;

            ray r = ray(center, ray_dir);
            
            vec3 pixel_color = ray_color(r, world);
            
            write_color(std::cout, pixel_color);
        } 
    }
}