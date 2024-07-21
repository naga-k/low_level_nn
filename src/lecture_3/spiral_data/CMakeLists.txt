cmake_minimum_required(VERSION 3.10)
project(MatplotlibCppExample)

set(CMAKE_CXX_STANDARD 11)

# # Create the executable
add_executable(plot_spiral /Users/nagakarumuri/Documents/GitHub/low_level_nn/src/lecture_3/plot_spiral.cpp)

# Link against the required libraries (typically, no additional linking is needed for matplotlib-cpp itself)
# For more complex setups, you might need to link against other libraries (e.g., Boost or others)
