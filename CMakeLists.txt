cmake_minimum_required(VERSION 3.10.0)
project(OpenGL_Test VERSION 1.0.0)

add_executable(OpenGL_Test src/config.h src/main.cpp src/glad.c src/stb_image_implementation.cpp)

target_include_directories(OpenGL_Test PRIVATE ${PROJECT_SOURCE_DIR}\\dependencies\\include)

# Linux and MacOS

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

target_include_directories(OpenGL_Test PRIVATE ${GLFW_INCLUDE_DIRS})
target_link_libraries(OpenGL_Test PRIVATE ${GLFW_LIBRARIES})


# Windows os
# target_link_libraries(OpenGL_Test PRIVATE ${PROJECT_SOURCE_DIR}\\dependencies\\lib\\glfw3.lib)
