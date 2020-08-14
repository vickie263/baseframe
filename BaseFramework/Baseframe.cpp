
#include "Baseframe.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

GLFWwindow* window;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Baseframe::Baseframe()
{
  

}

Baseframe::~Baseframe()
{
}

int Baseframe::createWindow(int screen_w, int screen_h, const char* title)
{
    // glfw: initialize and configure
 // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(screen_w, screen_h, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    return 1;
}


void Baseframe::drawMesh(Mesh *pmesh, Shader shader)
{
     shader.use();
    if(nullptr != pmesh)
         pmesh->Draw(shader);
}

void Baseframe::drawMesh2(Mesh* pmesh)
{
    if (nullptr != pmesh)
        pmesh->Draw();
}

void Baseframe::run()
{
 
    while (!glfwWindowShouldClose(window))
    {
        processInput();
        glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        update();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

  
    destory();
}

void Baseframe::destory()
{

    // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
    glfwTerminate();
}



void Baseframe::update()
{
}

bool Baseframe::inputKey()
{
    return false;
}


void Baseframe::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (this->inputKey())
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

