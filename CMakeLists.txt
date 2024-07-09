cmake_minimum_required(VERSION 3.24)

project(ray_trace)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    src/main.cpp
    src/vec3.cpp
    src/ray.cpp
    src/hittable_list.cpp
    src/materials.cpp
    src/camera.cpp
    src/sphere.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

