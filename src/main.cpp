#include<iostream>

#include "../include/contact/hittable_list.h"

#include "../include/models/camera.h"
#include "../include/models/sphere.h"
#include "../include/models/materials.h"


using namespace std;

int main() {

    // create world
    hittable_list world;

    // create materials
    auto material_ground = make_shared<lambertian>(vec3(0.8, 0.8, 0.0));
    auto material_sphere = make_shared<lambertian>(vec3(0.1, 0.2, 0.5));
    auto material_metal = make_shared<metal>(vec3(0.8, 0.8, 0.8));

    // add ground
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100, material_ground));

    // add sphere
    world.add(make_shared<sphere>(point3(-1., 0., -1), 0.5, material_sphere));
    world.add(make_shared<sphere>(point3(1., 0., -1), 0.5, material_metal));

    // create camera
    camera cam = camera(400);

    // render
    cam.render(world);
}