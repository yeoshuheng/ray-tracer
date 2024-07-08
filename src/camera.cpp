#include "../include/models/camera.h"

camera::camera(int iw, int ih) {
    image_width = iw;
    image_height = (ih < 1) ? 1 : ih;

    viewport_width = viewport_height * (double(image_width) / image_height);
    
    viewport_u = vec3(viewport_width, 0, 0);
    viewport_v = vec3(0, -viewport_height, 0);

    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;
    
    viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}