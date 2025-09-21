#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "config.h"
#include <iostream>

class Engine {

  Engine(){
    if (!glfwInit()) {
      std::cerr << "Failed to init GLFW\n";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window =
        glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D BLACK HOLE", nullptr, nullptr);

    if (!window) {
      std::cerr << "Failed to create GLFW window\n";
      glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // --- Init GLEW --- //
    glewExperimental = GL_TRUE; // needed for core profile
    if (glewInit() != GLEW_OK) {
      std::cerr << "Failed to init GLEW\n";
    }
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  }
 

    void run() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double left   = -NAV_WIDTH+ curr_x;
        double right  =  NAV_WIDTH+ curr_x;
        double bottom = -NAV_HEIGHT + curr_y;
        double top    =  NAV_HEIGHT + curr_y;
        glOrtho(left, right, bottom, top, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

  GLFWwindow * get_window(){
    return window;
  }

  private:
    GLFWwindow * window;
    curr_x = 0.0f;
    curr_y = 0.0f;
    
};
