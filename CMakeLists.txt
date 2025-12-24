cmake_minimum_required(VERSION 3.10)
project(c_liste C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable debug symbols by default
set(CMAKE_BUILD_TYPE Debug)

# Add compile flags for debugging
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -Wall")

# Add the executable
add_executable(app main.c)

# Optional: Print build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
