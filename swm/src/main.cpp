#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WINDTH = 800;
const GLint HEIGHT = 600;

const GLchar *vertexShaderSource = "#version 330 core\n"
"layout ( location = 0 ) in vec3 position;\n "
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\n";


const GLchar *fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(0.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";


GLint shader_program;
GLuint VBO, VAO;

void window_size_callback(GLFWwindow *win, int w, int h)
{
    //std::cout << "Window size is changed" << std::endl;
    glViewport(0, 0, w, h);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader_program);
    glBindVertexArray(VBO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glfwSwapBuffers(win);
}

int main(int argc, char **argv)
{
    glfwInit();    

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    
    GLFWwindow *window = glfwCreateWindow(WINDTH, HEIGHT, "SWM", nullptr, nullptr);
    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return EXIT_FAILURE;
    }

    glfwSetWindowSizeCallback(window, window_size_callback);

    int screen_width, screen_height;

    glfwGetFramebufferSize(window, &screen_width, &screen_height);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    glViewport(0, 0, screen_width, screen_height);


    GLuint vertex_sharder = glCreateShader(GL_VERTEX_SHADER); 
    glShaderSource(vertex_sharder, 1, &vertexShaderSource, NULL);
    glCompileShader(vertex_sharder);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex_sharder, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_sharder, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER:VERTEX:COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER:FRAGMENT:COMPILATION_FAILED\n" << infoLog << std::endl;
    }  


    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_sharder);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetShaderiv(shader_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader_program, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER:PROGARAM:LINK\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_sharder);
    glDeleteShader(fragment_shader);

    GLfloat verteces[] =
    {
        -0.5f, -0.5f, 0.0f, //bottom left
        0.5f, -0.5f, 0.0f,  //bottom right
        0.0f, 0.5f, 0.0f,   //top middle        
    };

    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0); 
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //draw stuff
        glUseProgram(shader_program);
        glBindVertexArray(VBO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();

    return EXIT_SUCCESS;
}
