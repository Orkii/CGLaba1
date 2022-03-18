#include <GL/glew.h>
#include "Window.h"
#include <GL/freeglut.h>

#include <stdio.h>

int Window::sizeX;
int Window::sizeY;
int Window::posX;
int Window::posY;

int Window::init(int argc, char** argv, void (*callback)()){


    glutInit(&argc, argv);



    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(sizeX, sizeY);
    glutInitWindowPosition(posX, posY);
    glutCreateWindow("Laba1");

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        printf("Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glutDisplayFunc(callback);
    
    return 0;
}
