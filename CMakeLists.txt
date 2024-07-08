cmake_minimum_required(VERSION 3.24)

project(ray_trace)

set(SOURCE_FILES
    src/main.cpp
    src/vec3.cpp
    src/ray.cpp
    src/camera.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

