#include "config.h"

float vertices[] = {
//  {       pos     }{       col      }{   tex   }
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
};
 
float texCoords[] = {
    0.0f, 0.0f, //lower-left
    1.0f, 0.0f, //lower-right
    0.5f, 1.0f  //top-center
};

unsigned int indices[] = { // note that we start from 0!
0, 1, 3, // first triangle
1, 2, 3 // second triangle
};

const char *vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
" ourColor = aColor;\n"
"}\0";

const char *fragmentShaderSource = 
"#version 330 core\n"
"in vec3 ourColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
" FragColor = vec4(ourColor, 1.0);\n"
"}\0";

std::string projectPath = std::filesystem::current_path().parent_path().string();
std::string vLocal = "/src/shader.vert";
std::string fLocal = "/src/shader.frag";
// ensure the const char paths have a non instance varible to reference not a local one
std::string vFullPath = (projectPath+vLocal);
std::string fFullPath = (projectPath+fLocal);
const char* vShaderPath = vFullPath.c_str();
const char* fShaderPath = fFullPath.c_str();

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width,height);
}

class OpenGLTest{
    public:
        GLFWwindow* window;

        int start(){
            glfwInitialize();
            int glfwWindow = this->glfwWindow();
            if(glfwWindow == -1) return -1;
            int gladLoad = this->gladLoadFunctionPointers();
            if(gladLoad == -1) return -1;
            this->instantiateObjects();
            this->bindCopyObjects();
            this->linkVertexAttributes();
            this->UnbindObjects();
            // set texture parameters (wrapping, filtering, mipmaps)
            // set per coordinate s,t,r = x,y,z
            
            // texture loading
            glGenTextures(1, &(this->texture));
            glBindTexture(GL_TEXTURE_2D, this->texture);
            
            // set texture option on currently bound textures
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
            
            int width, height, nrChannels;
            std::string fullTexPath = (projectPath+"/textures/wall.jpg");
            unsigned char *data = stbi_load(fullTexPath.c_str(), &width, &height, &nrChannels, 0);

            if(data){
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else{
                std::cout << "Failed to load texture because " << stbi_failure_reason();
            }

            stbi_image_free(data);

            Shader ourShader(vShaderPath,fShaderPath);
            // activate shader
            ourShader.use();

            return 0;
        }

        int update(){
            // input
            this->processInput(this->window);
    
            // rendering commands
            // clear color buffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // use shader program
            //this->ourShader.use();

            // draw triangle
            glBindTexture(GL_TEXTURE_2D, this->texture);
            glBindVertexArray(this->VAO);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe mode
            // glDrawArrays(GL_TRIANGLES, 0, 3);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
            glBindVertexArray(0);
    
            // check and call events, swap buffers
            glfwSwapBuffers(this->window);
            glfwPollEvents();
            return 0;
        }

        int stop(){
            deleteObjects();
            glfwTerminate();
            return 0;
        }

    private:
        unsigned int VBO, VAO, EBO;
        unsigned int texture;
        const unsigned int SCREEN_WIDTH = 800;
        const unsigned int SCREEN_HEIGHT = 600;

        void processInput(GLFWwindow *window){
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
                glfwSetWindowShouldClose(this->window, true);
            }
        }

        void glfwInitialize(){
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        int glfwWindow(){
            this->window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_WIDTH, "LearnOpenGL", NULL, NULL);
            if(window == NULL){
                std::cout << "Failed to make GLFW window" << std::endl;
                glfwTerminate();
                return -1;
            }
            glfwMakeContextCurrent(this->window);
            glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
            return 0;
        }

        int gladLoadFunctionPointers(){
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                std::cout << "Failed to initialize GLAD" << std::endl;
                return -1;
            }
    
            framebuffer_size_callback(this->window, SCREEN_WIDTH, SCREEN_HEIGHT);
            return 0;
        }
        
        void instantiateObjects(){
            glGenBuffers(1, &this->EBO);
            glGenVertexArrays(1, &this->VAO);
            glGenBuffers(1, &this->VBO);
        }

        void bindCopyObjects(){
            glBindVertexArray(this->VAO);
            glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }
    
        void linkVertexAttributes(){
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);
        }

        void UnbindObjects(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void deleteObjects(){
            glDeleteVertexArrays(1, &this->VAO);
            glDeleteBuffers(1, &this->VBO);
            glDeleteBuffers(1, &this->EBO);
            //ourShader.close();
        }
};

int main(){
    OpenGLTest app;
    if(app.start() == -1) return -1;
    while(!glfwWindowShouldClose(app.window)){
        if(app.update() == -1) return -1;
    }
    if(app.stop() == -1) return -1;
    return 0;
}
