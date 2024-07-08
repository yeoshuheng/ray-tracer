#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {

    private:
        point3 origin;
        vec3 direction;

    public:

        // constructors
        ray();
        ray(point3& ori, vec3& dir);

        // getters
        // since we want our points & vector to be immutable, the function
        // returns a const pointer.
        const point3& get_origin() const { return origin; }
        const vec3& get_direction() const { return direction; }
        
        // operations
        point3 at(double n) const;
};

#endif