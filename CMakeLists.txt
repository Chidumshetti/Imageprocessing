cmake_minimum_required(VERSION 3.12)
project(imageprocessing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Find OpenCV package
find_package(OpenCV REQUIRED)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found! Make sure it's installed and accessible.")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/programs)

# Add the source files to the target
add_library(module_lib programs/module.cpp)
add_library(horizontal_lib programs/horizontal_edge.cpp)

# Add executable for main.cpp (if needed)
add_executable(rotateimg main.cpp)

# Link OpenCV, module_lib, and horizontal_lib for rotateimg
target_link_libraries(module_lib ${OpenCV_LIBS})
target_link_libraries(horizontal_lib ${OpenCV_LIBS})
target_link_libraries(rotateimg module_lib horizontal_lib ${OpenCV_LIBS})

# Now, add only the specific test file (test_horizontal.cpp)
add_executable(test_horizontal test/test_horizontal.cpp)

# Link the necessary libraries for test_horizontal
target_link_libraries(test_horizontal horizontal_lib ${OpenCV_LIBS})
