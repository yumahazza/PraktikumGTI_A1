#include <windows.h>
#include <GL/glut.h>

void cube(float x, float y, float size)
{
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2,0.6,1);
	float s = 0.2;
	
	// 3 kubus
    cube(-0.36,-0.4,s);
    cube(-0.15,-0.4,s);
    cube(0.06,-0.4,s);

    // 2 kubus
    cube(-0.25,-0.185,s);
    cube(-0.04,-0.185,s);
  
    // 1 kubus
    cube(-0.15,0.03,s);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,500);
    glutCreateWindow("Kubus Bertingkat");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}



