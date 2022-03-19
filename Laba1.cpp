#include <GL/glew.h>
#include <iostream>

//#include <GL/glut.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

//#include "math_3d.h"


#include "Drawer.h"
#include "Window.h"

#include "Drawable.h"

#include <vector>

GLuint VBO;



void RenderSceneCB() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 
    //p->paint();



    glColor3f(0.0f, 1.0f, 1.0f);

    //glEnableVertexAttribArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDisableVertexAttribArray(0);


    Window::paint();

    //glBegin(GL_POINTS);
    //glVertex2f(0.0, 0.0);
    //glEnd();
    


    //SDrawer::circle(0, 0, 0.5, 0.5);

    glutSwapBuffers();

}
int main(int argc, char **argv){
    Window::sizeX = 400;
    Window::sizeY = 400;
    Window::posX = 100;
    Window::posY = 100;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    //p = new Point(glm::vec3(0.5, 0.0, 0.0));
    //p

    if (Window::init(argc, argv, RenderSceneCB) != 0) {
        return 1;
    }
        
    glm::vec3 v[4];// = { {0.5f, 0.5f, 0.0f} };

    //vector<glm::vec3> v2;
    //v2.push_back(glm::vec3(-0.25f, -0.25f, 0.0f));
    //v2.push_back(glm::vec3(0.0f, 0.4f, 0.0f));
    //v2.push_back(glm::vec3(0.25f, -0.25f, 0.0f));
    //v2.push_back(glm::vec3(-0.4f, 0.1f, 0.0f));
    //v2.push_back(glm::vec3(0.4f, 0.1f, 0.0f));
    //Window::add(new Smth(v2, GL_LINE_LOOP));


    v[0] = glm::vec3(-0.1f, -0.1f, 0.0f);
    v[1] = glm::vec3(0.1f, -0.1f, 0.0f);
    v[2] = glm::vec3(0.0f, 0.1f, 0.0f);
    v[3] = glm::vec3(0.0f, 0.2f, 0.0f);

    glm::vec3 v1(0.5f, 0.5f, 0.0f);

    Window::add(new Point(v1));



    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), &v, GL_STATIC_DRAW);

    glutMainLoop();

}

