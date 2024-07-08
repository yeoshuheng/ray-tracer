mkdir -p build

cd build

cmake ..

cmake --build .

./ray_trace > image.ppm