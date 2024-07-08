#ifndef CAMERA_H
#define CAMERA_H

#include "../contact/hittable.h"

class camera {
    private:
    
        int aspect_ratio;
        int image_width;
        int image_height;

        // for anti-aliasing
        int sample_per_pixel = 10;
        double pixel_sample_scales;
        
        double focal_length = 1.0;
        double viewport_height = 2.0;
        double viewport_width;

        // upper left pixel location
        point3 viewport_upper_left;

        // starting pixel position
        point3 pixel00_loc;

        // vectors across the viewport edges
        vec3 viewport_u;
        vec3 viewport_v;

        // pixel deltas for height/width
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        point3 camera_center = point3(0.,0.,0.);

    public:
        // constructor
        camera(int iw, double ar = 16.0/9.0);

        // getters
        point3 get_center() const { return camera_center; }
        point3 get_pixel_00() const { return pixel00_loc; }
        vec3 get_delta_u() const { return pixel_delta_u; }
        vec3 get_delta_v() const { return pixel_delta_v; }


        // for rendering
        void render(const hittable& world);
        ray get_ray(int i, int j);

        // anti-aliasing
        vec3 sample_square() const;
};

#endif