cmake_minimum_required(VERSION 3.10)
project(c_liste C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable debug symbols by default
set(CMAKE_BUILD_TYPE Debug)

# Add compile flags for debugging
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -Wall")

# Add the original executable (no GLib)
add_executable(app main.c)

# Add the GLib-based executable
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)

add_executable(app_glib main_glib.c)
target_include_directories(app_glib PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_libraries(app_glib ${GLIB_LIBRARIES})
target_compile_options(app_glib PRIVATE ${GLIB_CFLAGS_OTHER})

# Add the custom list executable (no GLib)
add_executable(app_custom main_custom.c)

# Optional: Print build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "GLib found: ${GLIB_FOUND}")
message(STATUS "GLib include dirs: ${GLIB_INCLUDE_DIRS}")
message(STATUS "GLib libraries: ${GLIB_LIBRARIES}")
