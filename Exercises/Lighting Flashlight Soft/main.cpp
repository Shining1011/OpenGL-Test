#include "config.h"
using namespace glm;
using namespace std;

// page 139 chpt light casters

#pragma region Constant_Variables
float VERTICIES[] = {
//  {       pos     }{       col      }{   tex   }
    // 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    // 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    // -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    // -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left

//    positions      //   normals      //  texthttp://192.168.2.107/modules/icewhale_files/#/files/Emily-Storage/AppData/qbittorrent/config/downloads coord
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

vec3 cubePositions[] = {
    vec3( 0.0f, 0.0f, 0.0f),
    vec3( 2.0f, 5.0f, -15.0f),
    vec3(-1.5f, -2.2f, -2.5f),
    vec3(-3.8f, -2.0f, -12.3f),
    vec3( 2.4f, -0.4f, -3.5f),
    vec3(-1.7f, 3.0f, -7.5f),
    vec3( 1.3f, -2.0f, -2.5f),
    vec3( 1.5f, 2.0f, -2.5f),
    vec3( 1.5f, 0.2f, -1.5f),
    vec3(-1.3f, 1.0f, -1.5f)
};

string projectPath = filesystem::current_path().parent_path().string();
string vLocal = "/src/shader.vert";
string fLocal = "/src/shader.frag";
string vLightLocal = "/src/lightShader.vert";
string fLightLocal = "/src/lightShader.frag";
// ensure the const char paths have a non instance varible to reference not a local one
string vFullPath = (projectPath+vLocal);
string fFullPath = (projectPath+fLocal);
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
                cout << "GLFW WINDOW FAILED TO INITIALIZE" << endl;
                return;
            }
            int gladLoad = this->gladLoadFunctionPointers();
            if(gladLoad == -1){
                cout << "GLAD LOAD FAILED TO INITIALIZE" << endl;
                return;
            }

            this->setupShaders();

            this->camera = Camera(FREE, (static_cast<float>(SCREEN_WIDTH)/static_cast<float>(SCREEN_HEIGHT)), vec3(0.0f, 0.0f, 3.0f));
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetWindowUserPointer(window, this);
            glfwSetCursorPosCallback(window, mouse_callback);
            glfwSetScrollCallback(window, scroll_callback);

            this->setupObjects();
            
            this->loadText(&texture1, "container2.png", GL_RGBA, GL_TEXTURE0);
            this->loadText(&specular1, "container2_specular.png", GL_RGBA, GL_TEXTURE1);
            this->loadText(&emission1, "matrix.jpg", GL_RGB, GL_TEXTURE2);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, specular1);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, emission1);
            glBindVertexArray(VAO);

            // activate shader
            (*ourShader).use();
            (*ourShader).setInt("material.diffuse", 0);
            (*ourShader).setInt("material.specular", 1);
            (*ourShader).setInt("emission", 2);

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
            this->model = mat4(1.0);
            this->view = this->camera.GetViewMatrix();
            this->projection = perspective(radians(this->camera.Zoom), static_cast<float>(SCREEN_WIDTH)/static_cast<float>(SCREEN_HEIGHT), 0.1f, 100.0f);

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
        unsigned int texture1;
        unsigned int specular1;
        unsigned int emission1;
        Shader* ourShader;
        Shader* ourLightShader;
        const unsigned int SCREEN_WIDTH = 800;
        const unsigned int SCREEN_HEIGHT = 600;
        mat4 model;
        mat4 view;
        mat4 projection;

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
        vec4 lightPos = vec4(0.0f, 3.0f, -3.0f, 1.0);
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

            vec3 restriction = vec3(1.0f, 0.0f, 1.0f);
            if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
                this->camera.ProcessKeyboard(FORWARD, this->deltaTime);
            }
            if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
                this->camera.ProcessKeyboard(BACKWARD, this->deltaTime);
            }
            if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
                this->camera.ProcessKeyboard(LEFT, this->deltaTime);
            }
            if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
                this->camera.ProcessKeyboard(RIGHT, this->deltaTime); 
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
                cout << "Failed to make GLFW window" << endl;
                glfwTerminate();
                return -1;
            }
            glfwMakeContextCurrent(this->window);
            glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
            return 0;
        }

        int gladLoadFunctionPointers(){
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                cout << "Failed to initialize GLAD" << endl;
                return -1;
            }
    
            framebuffer_size_callback(this->window, SCREEN_WIDTH, SCREEN_HEIGHT);
            return 0;
        }
    
        void setupShaders(){
            this->ourShader = new Shader(vShaderPath,fShaderPath);

            string vLightFullPath = (projectPath+vLightLocal);
            string fLightFullPath = (projectPath+fLightLocal);
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

        void loadText(unsigned int* texture, string textName, unsigned int dataType, unsigned int textNum){
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
            string fullTexPath = (projectPath+"/textures/" + textName);
            unsigned char *data = stbi_load(fullTexPath.c_str(), &width, &height, &nrChannels, 0);

            if(data){
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, 
                    dataType, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else{
                cout << "Failed to load texture because " << stbi_failure_reason() << endl;
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

        void bindTextures(){
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, this->texture1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, this->specular1);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, this->emission1);
        }

        void moveLight(float scalar){
            
            float factor = 2.0f;
            // lightPos.z += factor * sin(scalar) * this->deltaTime;
            // lightPos.x += factor * cos(scalar) * this->deltaTime;
        }

        void drawObjects(){

            float scalar = abs(glfwGetTime());
            vec3 lightColor = vec3(1.0f);
            vec3 diffuseColor = lightColor;
            vec4 lightDir = vec4(-0.2f, -1.0f, -0.3f, 0.0);
            moveLight(scalar);
            (*ourShader).use();

            bindTextures();

            // Emission
            (*ourShader).setInt("material.emission", 2);

            // Material Properties
            (*ourShader).setInt("material.diffuse", 0);
            (*ourShader).setInt("material.specular", 1);
            (*ourShader).setFloat("material.shininess", 32.0f);

            // Light Properties
            (*ourShader).setVec3("light.ambient", lightColor * vec3(0.1f));
            (*ourShader).setVec3("light.diffuse", diffuseColor * vec3(2.0f));
            (*ourShader).setVec3("light.specular", vec3(1.0f));

            // Light Attenuation
            (*ourShader).setFloat("light.constant", 1.0f);
            (*ourShader).setFloat("light.linear", 0.09f);
            (*ourShader).setFloat("light.quadratic", 0.032f);
            
            // Light Object
            
            vec3 lightPosView = vec3(this->view * this->lightPos);
            vec3 camPosView = view * vec4(camera.Position, 1.0);
            vec3 camFrontView = view * vec4(camera.Front, 0.0);
            (*ourShader).setVec3("light.position", camPosView);
            (*ourShader).setVec3("light.direction", camFrontView);
            (*ourShader).setFloat("light.innerCutOff", cos(radians(12.5f)));
            (*ourShader).setFloat("light.outerCutOff", cos(radians(17.5f)));
            // cout << cos(radians(1.5f)) << endl;
            
            // Model View Projection
            (*ourShader).setMat4("projection", this->projection);
            (*ourShader).setMat4("view", this->view);
            this->model = mat4(1.0);
            (*ourShader).setMat4("model", this->model);

            // ******************************//

            // Objects

            glBindVertexArray(this->VAO);


            for(unsigned int i = 0; i < 10; i++){
                this->model = mat4(1.0f);
                this->model = translate(this->model, cubePositions[i]);
                float angle = 20.0f * i;
                this->model = rotate(this->model, radians(angle), vec3(1.0f, 0.3f, 0.5f));
                if((i+1)%3==0){
                   this->model = rotate(this->model, radians(scalar*300), vec3(1.0f, 0.3f, 0.5f)); 
                }
                (*ourShader).setMat4("model", this->model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }


            // glDrawArrays(GL_TRIANGLES, 0, 36);
            // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);

            // ******************************//

            // Light    

            (*ourLightShader).use();

            (*ourLightShader).setVec3("lightColor", lightColor);
            (*ourLightShader).setMat4("projection", this->projection);
            (*ourLightShader).setMat4("view", this->view);
            this->model = mat4(1.0f);
            this->model = translate(this->model, vec3(lightPos));
            // this->model = scale(this->model, vec3(0.2f));
            (*ourLightShader).setMat4("model", this->model);
            
            glBindVertexArray(this->lightVAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            // glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);
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
