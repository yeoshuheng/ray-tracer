mkdir -p build

cd build

cmake ..

cmake --build . -v

./ray_trace > image.ppm