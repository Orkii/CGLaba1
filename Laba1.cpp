#include <iostream>
//#include <GL/glut.h>
#include <GL/freeglut.h>
//#include <GL/glm.h>
//#include "math_3d.h"

# define M_PI 3.14159265358979323846
#include "Drawer.h"
#include "Window.h"
#include <list>




void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    Drawer::circle(0, 0, 0.5, 0.5);

    glutSwapBuffers();
}
int main(int argc, char **argv){
    Window::sizeX = 400;
    Window::sizeY = 400;
    Window::posX = 400;
    Window::posY = 400;

    Window::init(argc, argv, RenderSceneCB);
}

