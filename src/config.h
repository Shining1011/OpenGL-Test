#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "iostream"
#include "fstream"

#ifndef SHADER_H
#define SHADER_H

class Shader {
    public:
        // The program ID
        unsigned int ID;

        // constructor reads and builds the shader
        Shader(const char* vertexPath, const char*){
                // retrieve vertex/fragment source code from file path
                std::string vertexCode;
                std::string fragmentCode;
                std::ifstream vShaderFile;
                std::ifstream fShaderFile;
                // ensure ifstream objects can throw exceptions:
                vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                try

        };
        // use/activate the shader
        void use();
        // ultility uniform functions
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
};
#endif