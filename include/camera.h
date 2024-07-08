#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

class camera {
    private:
        int aspect_ratio;
        int image_width;
        int image_height;
        
        double focal_length = 1.;
        double viewport_height = 2.;
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
        camera(int iw, int ih);

        // getters
        point3 get_center() const { return camera_center; }
        point3 get_pixel_00() const { return pixel00_loc; }
        vec3 get_delta_u() const { return pixel_delta_u; }
        vec3 get_delta_v() const { return pixel_delta_v; }

};

#endif