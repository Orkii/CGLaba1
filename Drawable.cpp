#include "Drawable.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

#include <iostream>
using namespace std;

Point::Point(glm::vec3 &v){

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), &v, GL_STATIC_DRAW);

}

void Point::paint(){

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
}

void Point::update(){
}

Smth::Smth(std::vector<glm::vec3> &v, int drawType_) {
    this->drawType = drawType_;

    
    pointNum = v.size();

    cout << "Len = " << v.size() << endl;

    glm::vec3 *vec;
    vec = new glm::vec3[v.size()];
    for (int i = 0; i < v.size(); i++) {
        vec[i] = v[i];
    }


    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec[0])* v.size(), vec, GL_STATIC_DRAW);
}
void Smth::paint(){

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(drawType, 0, pointNum);
    glDisableVertexAttribArray(0);
    cout << "Draw SMTH" << endl;
}

void Smth::update(){
}
