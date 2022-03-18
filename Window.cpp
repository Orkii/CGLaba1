#include "Window.h"
#include <GL/freeglut.h>



int Window::sizeX;
int Window::sizeY;
int Window::posX;
int Window::posY;

void Window::init(int argc, char** argv, void (*callback)()){


    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(sizeX, sizeY);
    glutInitWindowPosition(posX, posY);
    glutCreateWindow("Laba1");



    glutDisplayFunc(callback);
    glutMainLoop();

}
