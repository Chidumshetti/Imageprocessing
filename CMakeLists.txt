cmake_minimum_required(VERSION 3.12)
project(rotateimg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV
find_package(OpenCV REQUIRED)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found! Make sure it's installed and accessible.")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/programs)

# Correct module.cpp path (adjust if needed)
add_library(module_lib programs/module.cpp)  

# Add executable
add_executable(rotateimg main.cpp)

# Link OpenCV and module_lib
target_link_libraries(module_lib ${OpenCV_LIBS})
target_link_libraries(rotateimg module_lib ${OpenCV_LIBS})
