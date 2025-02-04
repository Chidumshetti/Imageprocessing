cmake_minimum_required(VERSION 3.12)
project(rotateimg)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Check if OpenCV was found
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found! Make sure it's installed and accessible.")
endif()

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Include project headers (lib is outside programs)
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/programs)

# Add library (lib/module.cpp is now outside programs)
add_library(module_lib lib/module.cpp)

# Add executable
add_executable(rotateimg main.cpp)

# Link OpenCV and other required libraries
target_link_libraries(module_lib ${OpenCV_LIBS})
target_link_libraries(rotateimg module_lib ${OpenCV_LIBS})
