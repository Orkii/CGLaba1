#include "Drawer.h"
#include <GL/freeglut.h>
#include "math.h"
# define M_PI 3.14159265358979323846
void Drawer::circle(float midX, float midY, float radX, float radY, bool fill, int cnt) {
    float x, y;
    float a = M_PI * 2 / cnt;
    if (!fill) glBegin(GL_LINE_LOOP);
    else glBegin(GL_TRIANGLE_FAN);

    
    glPushMatrix();

    for (int i = -1; i <= cnt; i++) {
        x = sin(a * i) * radX + midX;
        y = cos(a * i) * radY + midY;
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();

}