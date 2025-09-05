#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
  if (glfwInit() == false) {
    std::cerr << "error initializing glfw\n";
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(1080, 1920, "this is a window of all times", NULL, NULL);

  if (!window) {
    std::cerr << "failed to create window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;

  GLenum err = glewInit();

  GLfloat verts[] = {
      +0.0f, +0.0f, -1.0f, -1.0f, +1.0f, -1.0f,
  };

  GLuint buffID;
  glGenBuffers(1, &buffID); // its a logical buffer (?) which means that somehow
  glBindBuffer(GL_ARRAY_BUFFER, buffID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

  while (!glfwWindowShouldClose(window)) {
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
