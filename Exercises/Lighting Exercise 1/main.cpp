#include "config.h"

// on lighting page 118

#pragma region Constant_Variables
float VERTICIES[] = {
//  {       pos     }{       col      }{   tex   }
    // 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    // 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    // -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    // -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left

//    positions      //   normals      //  text coord
-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f

//  EBO box vbo
    // 0.5f,0.5f,0.5f,     // ind 0
    // 0.5f,-0.5f,0.5f,    // ind 1
    // -0.5f,0.5f,0.5f,    // ind 2
    // -0.5f,-0.5f,0.5f,   // ind 3
    // 0.5f,0.5f,-0.5f,    // ind 4
    // 0.5f,-0.5f,-0.5f,   // ind 5
    // -0.5f,0.5f,-0.5f,   // ind 6
    // -0.5f,-0.5f,-0.5f,  // ind 7
};
 
float TEX_COORDS[] = {
    0.0f, 0.0f, //lower-left
    1.0f, 0.0f, //lower-right
    0.5f, 1.0f  //top-center
};

unsigned int indices[] = { // note that we start from 0!
0,1,2, //front face
1,2,3,
4,5,6, // back face
5,6,7,
0,1,4, // right face
1,4,5,
2,3,6, // left face
3,6,7,
0,2,4, // top face
2,4,6,
1,3,5, // bottom face
3,5,7,
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
std::string vLightLocal = "/src/lightShader.vert";
std::string fLightLocal = "/src/lightShader.frag";
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

        OpenGLTest() : vertices(VERTICIES), verticesNum(sizeof(VERTICIES)), texCoords(TEX_COORDS){
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

            this->setupShaders();

            this->camera = Camera(FPS, (static_cast<float>(SCREEN_WIDTH)/static_cast<float>(SCREEN_HEIGHT)), glm::vec3(0.0f, 0.0f, 3.0f));
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetWindowUserPointer(window, this);
            glfwSetCursorPosCallback(window, mouse_callback);
            glfwSetScrollCallback(window, scroll_callback);

            this->setupObjects();
            
            this->loadText(&texture1, "container.jpg", GL_RGB, GL_TEXTURE0);
            stbi_set_flip_vertically_on_load(true);
            this->loadText(&texture2, "awesomeface.png", GL_RGBA, GL_TEXTURE1);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, texture2);
            glBindVertexArray(VAO);

            // activate shader
            (*ourShader).use();
            (*ourShader).setInt("texture1", 0);
            (*ourShader).setInt("texture2", 1);

            glEnable(GL_DEPTH_TEST);
            return;
        }

        int update(){
            // get deltaTime:
            this->updateDeltaTime();

            // input:
            this->processInput(this->window);
    
            // rendering commands:
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            this->model = glm::mat4(1.0);
            this->view = this->camera.GetViewMatrix();
            this->projection = glm::perspective(glm::radians(this->camera.Zoom), static_cast<float>(SCREEN_WIDTH)/static_cast<float>(SCREEN_HEIGHT), 0.1f, 100.0f);

            this->drawObjects();
            
            // check and call events, swap buffers:
            glfwSwapBuffers(this->window);
            glfwPollEvents();
            return 0;
        }

        int stop(){
            this->unbindObjects();
            this->deleteObjects();
            glfwTerminate();
            return 0;
        }

    private:
        #pragma region Private Class Variables
        unsigned int VBO, VAO, EBO;
        unsigned int texture1, texture2;
        Shader* ourShader;
        Shader* ourLightShader;
        const unsigned int SCREEN_WIDTH = 800;
        const unsigned int SCREEN_HEIGHT = 600;
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projection;

        // Camera 
        Camera camera;
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        float lastX, lastY;
        bool firstMouse = true;

        // draws
        float* vertices;
        int verticesNum;
        float* texCoords;

        // light
        unsigned int lightVAO;
        glm::vec3 lightPos = glm::vec3(0.0f, 1.0f, -5.0f);
        #pragma endregion

        static void mouse_callback(GLFWwindow* window, double xpos, double ypos){
            OpenGLTest* instance = static_cast<OpenGLTest*>(glfwGetWindowUserPointer(window));
            instance->handle_mouse_callback(xpos, ypos);
        };
        
        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
            OpenGLTest* instance = static_cast<OpenGLTest*>(glfwGetWindowUserPointer(window));
            instance->handle_scroll_callback(yoffset);
        };

        void handle_mouse_callback(double xpos, double ypos){
            if(firstMouse){
                lastX=xpos;
                lastY=ypos;
                firstMouse=false;
            }
            float xOffset = xpos - lastX;
            float yOffset = lastY - ypos;
            lastX = xpos;
            lastY = ypos;
            camera.ProcessMouseMovement(xOffset, yOffset, true);
        };

        void handle_scroll_callback(double yoffset){
            this->camera.ProcessMouseScroll(yoffset);
        }

        void processInput(GLFWwindow *window){
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
                glfwSetWindowShouldClose(this->window, true);
            }

            // glm::vec3 cameraRight = glm::normalize(glm::cross(this->cameraUp, this->cameraFront));

            if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
                this->camera.ProcessKeyboard(FORWARD, this->deltaTime);
                // this->cameraPos += cameraFront*this->cameraSpeed*this->deltaTime;
            }
            if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
                this->camera.ProcessKeyboard(BACKWARD, this->deltaTime);
                // this->cameraPos -= cameraFront*this->cameraSpeed*this->deltaTime;
            }
            if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
                this->camera.ProcessKeyboard(LEFT, this->deltaTime);
                // this->cameraPos += cameraRight*this->cameraSpeed*this->deltaTime;
            }
            if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
                this->camera.ProcessKeyboard(RIGHT, this->deltaTime);
                // this->cameraPos -= cameraRight*this->cameraSpeed*this->deltaTime;
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
    
        void setupShaders(){
            this->ourShader = new Shader(vShaderPath,fShaderPath);

            std::string vLightFullPath = (projectPath+vLightLocal);
            std::string fLightFullPath = (projectPath+fLightLocal);
            const char* vLightShaderPath = vLightFullPath.c_str();
            const char* fLightShaderPath = fLightFullPath.c_str();
            this->ourLightShader = new Shader(vLightShaderPath,fLightShaderPath);
        }

        void setupObjects(){
            // Generate buffers
            glGenBuffers(1, &this->EBO);
            glGenVertexArrays(1, &this->VAO);
            glGenBuffers(1, &this->VBO);
            glGenVertexArrays(1, &this->lightVAO);

            // bind and fill VBO with data
            glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
            glBufferData(GL_ARRAY_BUFFER, verticesNum, vertices, GL_STATIC_DRAW);

            // bind and apply data to VAO
            glBindVertexArray(this->VAO);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
            glEnableVertexAttribArray(1);

            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
            glEnableVertexAttribArray(2);

            // bind and apply data from EBO to lightVAO
            // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
            
            // bind and apply light VBO data to lightVAO 
            glBindVertexArray(this->lightVAO);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // bind and apply data from EBO to lightVAO
            // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
            // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        }

        void unbindObjects(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        void loadText(unsigned int* texture, std::string textName, unsigned int dataType, unsigned int textNum){
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

        void updateDeltaTime(){
            float currentFrame = glfwGetTime();
            this->deltaTime = currentFrame-this->lastFrame;
            this->lastFrame = currentFrame;
        }

        void deleteObjects(){
            glDeleteVertexArrays(1, &this->VAO);
            glDeleteBuffers(1, &this->VBO);
            glDeleteBuffers(1, &this->EBO);
            glDeleteBuffers(1, &this->lightVAO);
            (*ourShader).close();
        }

        void drawObjects(){
            float scalar = abs(glfwGetTime()) * 2.0f;
            float factor = 10.0f;
            lightPos.x += factor * cos(scalar) * this->deltaTime;
            lightPos.z += factor * sin(scalar) * this->deltaTime;
            // lightPos.z *= cos(scalar);

            (*ourShader).use();
            
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, this->texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, this->texture2);

            // (*ourShader).setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
            (*ourShader).setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));
            (*ourShader).setVec3("lightPos", lightPos);
            (*ourShader).setVec3("viewPos", this->camera.Position);
            (*ourShader).setMat4("projection", this->projection);
            (*ourShader).setMat4("view", this->view);
            this->model = glm::mat4(1.0);
            (*ourShader).setMat4("model", this->model);

            // (*ourShader).setInt("texture1", 0);
            // (*ourShader).setInt("texture2", 1);


            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);

            (*ourLightShader).use();

            (*ourLightShader).setMat4("projection", this->projection);
            (*ourLightShader).setMat4("view", this->view);
            this->model = glm::mat4(1.0f);
            this->model = glm::scale(this->model, glm::vec3(0.2f));
            this->model = glm::translate(this->model, lightPos);
            (*ourLightShader).setMat4("model", this->model);
            
            glBindVertexArray(this->lightVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);




            // for(unsigned int i = 0; i < 10; i++){
            //     this->model = glm::mat4(1.0f);
            //     this->model = glm::translate(this->model, cubePositions[i]);
            //     float angle = 20.0f * i;
            //     this->model = glm::rotate(this->model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            //     if((i+1)%3==0){
            //        this->model = glm::rotate(this->model, glm::radians(scalar*300), glm::vec3(1.0f, 0.3f, 0.5f)); 
            //     }
            //     (*ourShader).setMat4("model", this->model);
            //     // glDrawArrays(GL_TRIANGLES, 0, 36);
            //     glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);
            // }
            glBindVertexArray(0);
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
