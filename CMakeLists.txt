cmake_minimum_required(VERSION 3.10.0)
project(OpenGL_Test VERSION 1.0.0)

add_executable(OpenGL_Test src/config.h src/main.cpp src/glad.c)

target_include_directories(OpenGL_Test PRIVATE ${PROJECT_SOURCE_DIR}\\dependencies\\include)
