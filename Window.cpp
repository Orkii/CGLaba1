#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Window.h"
#include <stdio.h>

//#include "Drawable.h"


#include <iostream>
using namespace std;

int Window::sizeX;
int Window::sizeY;
int Window::posX;
int Window::posY;
list<Drawable*>* Window::objs;

int Window::init(int argc, char** argv, void (*callback)()){


    glutInit(&argc, argv);

    //if (objs == NULL) cout << "123" << endl;

    objs = new list<Drawable*>();

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

void Window::add(Drawable* obj){
    objs->push_front(obj);
}


void Window::paint(){
    for (Drawable* a : *objs){
        a->paint();
    }
}