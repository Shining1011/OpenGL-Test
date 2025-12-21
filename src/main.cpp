#include "config.h"

float vertices[] = {
0.5f, 0.5f, 0.0f, // top right
0.5f, -0.5f, 0.0f, // bottom right
-0.5f, -0.5f, 0.0f, // bottom left
-0.5f, 0.5f, 0.0f // top left
};

unsigned int indices[] = { // note that we start from 0!
0, 1, 3, // first triangle
1, 2, 3 // second triangle
};

const char *vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmentShaderSource = 
"#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
" FragColor = ourColor;\n"
"}\0";

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
            this->vertexShaderCompilation();
            this->fragmentShaderCompilation();
            this->createShaderProgramLinkShaders();
            this->instantiateObjects();
            this->bindCopyObjects();
            this->linkVertexAttributes();
            this->UnbindObjects();
            return 0;
        }

        int update(){
            // input
            this->processInput(this->window);
    
            // rendering commands
            // clear color buffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // activate shader
            glUseProgram(this->shaderProgram);


            float timeValue = static_cast<float>(glfwGetTime());
            float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
            int vertexColorLocation = glGetUniformLocation(this->shaderProgram, "ourColor");
            glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

            // draw triangle
            glBindVertexArray(this->VAO);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe mode
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
    
            // check and call events, swap buffers
            glfwSwapBuffers(this->window);
            glfwPollEvents();
            return 0;
        }

        int stop(){
            deleteObjects();
            terminateGLFW();
            return 0;
        }
    private:
        unsigned int vertexShader;
        unsigned int fragmentShader;
        unsigned int shaderProgram;
        unsigned int VBO, VAO, EBO;
        const unsigned int SCREEN_WIDTH = 800;
        const unsigned int SCREEN_HEIGHT = 600;

        void processInput(GLFWwindow *window){
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
                glfwSetWindowShouldClose(this->window, true);
            }
        }

        void checkVertShaderCompilation(unsigned int vertexShader){
            int success;
            char infoLog[512];
            glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
            if(!success){
                glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }
        }

        void checkFragShaderCompilation(unsigned int fragmentShader){
            int success;
            char infoLog[512];
            glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &success);
            if(!success){
                glGetShaderInfoLog(this->fragmentShader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            }
        }

        void checkShaderProgCompilation(unsigned int shaderProgram){
            int success;
            char infoLog[512];
            glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
            if(!success){
                glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
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

        void vertexShaderCompilation(){
            this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(this->vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(this->vertexShader);
            checkVertShaderCompilation(this->vertexShader);
        }

        void fragmentShaderCompilation(){
            this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(this->fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(this->fragmentShader);
            checkFragShaderCompilation(this->fragmentShader);
        }
        
        void createShaderProgramLinkShaders(){
            this->shaderProgram = glCreateProgram();
            glAttachShader(this->shaderProgram, vertexShader);
            glAttachShader(this->shaderProgram, fragmentShader);
            glLinkProgram(this->shaderProgram);
            checkShaderProgCompilation(this->shaderProgram);
            glDeleteShader(this->vertexShader);
            glDeleteShader(this->fragmentShader);
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
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
        }

        void UnbindObjects(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }

        void deleteObjects(){
            glDeleteVertexArrays(1, &this->VAO);
            glDeleteBuffers(1, &this->VBO);
            glDeleteProgram(this->shaderProgram);
        }

        void terminateGLFW(){
            glfwTerminate();
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