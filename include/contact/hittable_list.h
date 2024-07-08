#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include<memory>
#include<vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public:

        std::vector< shared_ptr<hittable> > objects;

        hittable_list() {};
        hittable_list(shared_ptr<hittable> obj) { add(obj); };

        // util functions
        void clear() { objects.clear(); };
        void add(shared_ptr<hittable> obj);
        
        // hit function
        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& hr) const override;
};

#endif


// shared pointers:

// pointer to a allocated type that is managed by reference counting.
// consists of:
//      one pointer to the shared object
//      one pointer to a struct containing reference counts (weak & strong)

// when we copy a shared pointer, the reference count increases.
// when we destroy a shared pointer, we decrement the reference count.
// once reference count is zero we destroy the shared object.

// weak ptrs: only has the raw pointer, does not know if object is alive.
// strong pts: owns the raw pointer, keeps the raw pointer alive.