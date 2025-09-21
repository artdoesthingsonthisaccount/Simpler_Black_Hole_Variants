#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <math.h>


class bh{
  public:
    bh(double r_schwarz_, double x_pos, double y_pos){
      this->r_schwarz = r_schwarz_;
      this->position[0] = x_pos;
      this->position[1] = y_pos;
    }

    void draw() {
      glBegin(GL_TRIANGLE_FAN);
      glColor3b(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0f, 0.0f);
      for (int i = 0; i <=100; i++) {
        double angle = 2.0f*M_PI * i/100;

        double x = r_schwarz * cos(angle); 
        double y = r_schwarz * sin(angle);
        glVertex2f(x, y);
      }
    };

  private:
      double r_schwarz;
      Eigen::Vector2<double> position = {};
       
};
