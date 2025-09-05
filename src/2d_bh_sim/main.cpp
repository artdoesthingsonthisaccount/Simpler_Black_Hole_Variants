#pragma once
#include <iostream>

// needs to be initialized in exactly this order because GLFW uses some
// prototypes from GL/gl.h. without it there are missing prototypes which
// results in errors.
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// export line:
// export LIBDECOR_PLUGIN_DIR=/usr/lib/x86_64-linux-gnu/libdecor/plugins-1
// contains libdecor-gtk.so

int main() {
  std::cout << "hello blackhole\n";

  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
  if (!glfwInit()) {
    std::cerr << "failed to initialize glfw\n";
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(1920, 1080, "bh_simple_sim", NULL, NULL);

  if (!window) {
    std::cerr << "failed to create window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE; // enables the internal bookkeeping switch to say
                              // we are using GLEW

  GLenum err = glewInit();
  std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << std::endl;

  if (err != GLEW_OK) {
    std::cerr << "failed to initialize GLEW: " << glewGetErrorString(err)
              << std::endl;
    return -1;
  }

  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT); // makes the "back" buffer all black (only
                                  // need to edit the color buffs rn)
    glfwSwapBuffers(window);      // swap back buffer and front buffer
    glfwPollEvents(); // polls for OS events such as user inputs through mouse,
                      // keyboard ect and stuff like resizing the window
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
