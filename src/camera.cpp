#include "../include/models/camera.h"
#include "../include/utils/color.h"
#include "../include/ray_trace.h"

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

    pixel_sample_scales = 1. / sample_per_pixel;
}

void camera::render(const hittable& world) {

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {

            vec3 curr_pixel_color = vec3(0., 0., 0.);
            
            for (int s = 0; s < sample_per_pixel; s++) {
                ray r = get_ray(i, j);
                vec3 pixel_color = ray_color(r, world);
                curr_pixel_color += pixel_color;
            }

            curr_pixel_color *= pixel_sample_scales;

            write_color(std::cout, curr_pixel_color);
        } 
    }
}

vec3 camera::sample_square() const {
    return vec3(random_double(-1, 1) - 0.5, random_double(-1, 1) - 0.5 , 0);
}

ray camera::get_ray(int i, int j) {

    auto offset = sample_square();

    point3 center = get_center();
    point3 pixel00 = get_pixel_00();

    vec3 delta_u = get_delta_u();
    vec3 delta_v = get_delta_v();
    
    point3 pixel_center = pixel00 + ((j + offset.getX()) * delta_u) 
                + ((i + offset.getY()) * delta_v);

    vec3 ray_dir = pixel_center - center;

    ray r = ray(center, ray_dir);

    return r;
}