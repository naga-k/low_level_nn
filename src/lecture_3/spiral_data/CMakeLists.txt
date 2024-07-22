cmake_minimum_required(VERSION 3.10)
project(SpiralData)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    plot_spiral.cpp
)

# Add the executable
add_executable(plot_spiral ${SOURCES})

# Link Eigen library if necessary (assuming Eigen is installed system-wide)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(plot_spiral Eigen3::Eigen)