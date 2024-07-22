cmake_minimum_required(VERSION 3.10)
project(PlotExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    plot.cpp
)

# Add the executable
add_executable(plot ${SOURCES})

# Link against the required libraries (typically, no additional linking is needed for matplotlib-cpp itself)
# For more complex setups, you might need to link against other libraries (e.g., Boost or others)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(plot Eigen3::Eigen)