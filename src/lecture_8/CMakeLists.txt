cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LossFunctionDemo)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    loss.cpp
    Loss_CategoricalCrossentropy.cpp
    loss_demo.cpp
)

# Add the header files (optional, but useful for IDEs)
set(HEADERS
    loss.h
    Loss_CategoricalCrossentropy.h
)

# Create an executable from the source files
add_executable(LossFunctionDemo ${SOURCES} ${HEADERS})

# Link Eigen library if necessary (assuming Eigen is installed system-wide)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(LossFunctionDemo Eigen3::Eigen)
