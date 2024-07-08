#include<iostream>

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
    camera cam = camera(400);

    // render
    cam.render(world);
}