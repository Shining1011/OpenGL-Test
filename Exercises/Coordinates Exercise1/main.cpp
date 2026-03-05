#include "config.h"

// left on page 91 of the tutorial

#pragma region Constant_Variables
float vertices[] = {
//  {       pos     }{       col      }{   tex   }
    // 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    // 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    // -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    // -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left

//  {       pos         }{   tex   }
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
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

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f, 0.0f, 0.0f),
    glm::vec3( 2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f, 2.0f, -2.5f),
    glm::vec3( 1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)
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
            glEnable(GL_DEPTH_TEST);
            return;
        }

        int update(){
            // input
            this->processInput(this->window);
    
            // rendering commands
            // clear color buffer & depth buffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // use shader program
            (*ourShader).use();

            // apply 3d transformations local, model, view, projection
            glm::mat4 model = glm::mat4(1.0);
            model = glm::rotate(model, glm::radians(-60.0f), glm::vec3(1.0f, 1.0f, 0.0f));

            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(-1.0f, 0.0f, 0.0f));

            glm::mat4 projection = glm::perspective(glm::radians(90.0f), static_cast<float>(SCREEN_WIDTH)/static_cast<float>(SCREEN_HEIGHT-400), 0.1f, 100.0f);

            unsigned int modelLoc = glGetUniformLocation((*ourShader).ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            unsigned int viewLoc = glGetUniformLocation((*ourShader).ID, "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

            unsigned int projLoc = glGetUniformLocation((*ourShader).ID, "projection");
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            // draw triangle
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, this->texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, this->texture2);

            glBindVertexArray(this->VAO);

            // float scalar = abs(glfwGetTime());

            for(unsigned int i = 0; i < 10; i++){
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, cubePositions[i]);
                float angle = 20.0f * i;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                (*ourShader).setMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            
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
            // glGenBuffers(1, &this->EBO);
            glGenVertexArrays(1, &this->VAO);
            glGenBuffers(1, &this->VBO);
        }

        void bindCopyObjects(){
            glBindVertexArray(this->VAO);
            glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            
            // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }
    
        void linkVertexAttributes(){
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            // glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
        }

        void unbindObjects(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void loadText(unsigned int* texture, std::string textName, unsigned int dataType){
            // loading texture
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
                std::cout << "Failed to load texture because " << stbi_failure_reason() << std::endl;
            }

            stbi_image_free(data);
        }

        void deleteObjects(){
            glDeleteVertexArrays(1, &this->VAO);
            glDeleteBuffers(1, &this->VBO);
            glDeleteBuffers(1, &this->EBO);
            (*ourShader).close();
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
