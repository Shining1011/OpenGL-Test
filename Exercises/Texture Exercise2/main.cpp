#include "config.h"


#pragma region Constant_Variables
float vertices[] = {
//  {       pos     }{       col      }{   tex   }
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.51f, 0.51f, // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.51f, 0.49f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.49f, 0.49f, // bottom left
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.49f, 0.51f // top left
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

#pragma endregion

class OpenGLTest{
    public:
        GLFWwindow* window;

        OpenGLTest(){
            glfwInitialize();
            int glfwWindow = this->glfwWindow();
            if(glfwWindow == -1){
                std::cout << "GLFW WINDOW FAILED TO INITIALIZE" << std::endl;
                return;
            }
            int gladLoad = this->gladLoadFunctionPointers();
            if(gladLoad == -1){
                std::cout << "GLAD LOAD FAILED TO INITIALIZE" << std::endl;
                return;
            }
            this->ourShader = new Shader(vShaderPath,fShaderPath);
            this->instantiateObjects();
            this->bindCopyObjects();
            this->linkVertexAttributes();
            this->unbindObjects();
            this->loadText(&texture1, "container.jpg", GL_RGB);
            stbi_set_flip_vertically_on_load(true);
            this->loadText(&texture2, "awesomeface.png", GL_RGBA);
            // activate shader
            (*ourShader).use();
            glUniform1i(glGetUniformLocation((*ourShader).ID, "texture_1"), 0);
            (*ourShader).setInt("texture_2", 1);
            return;
        }

        int update(){
            // input
            this->processInput(this->window);
    
            // rendering commands
            // clear color buffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // use shader program
            (*ourShader).use();

            // draw triangle
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, this->texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, this->texture2);

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
        unsigned int texture1, texture2;
        Shader* ourShader;
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

        void unbindObjects(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void loadText(unsigned int* texture, std::string textName, unsigned int dataType){
            // loading texture 1
            glGenTextures(1, texture);
            glBindTexture(GL_TEXTURE_2D, *texture);

            // set texture parameters (wrapping, filtering, mipmaps)
            // set per coordinate s,t,r = x,y,z
            // set texture option on currently bound textures
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);

            int width, height, nrChannels;
            std::string fullTexPath = (projectPath+"/textures/" + textName);
            unsigned char *data = stbi_load(fullTexPath.c_str(), &width, &height, &nrChannels, 0);

            if(data){
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, 
                    dataType, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else{
                std::cout << "Failed to load texture because " << stbi_failure_reason();
            }

            stbi_image_free(data);
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
    while(!glfwWindowShouldClose(app.window)){
        if(app.update() == -1) return -1;
    }
    if(app.stop() == -1) return -1;
    return 0;
}
